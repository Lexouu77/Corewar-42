/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 18:07:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 19:45:18 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "./libftprintf/ft_printf.h"
# include "op.h"

extern t_op g_op_tab[];

typedef struct				s_label_list
{
	char					*label_name;
	int						line_number;
	struct s_label_list		*next;
}							t_label_list;

typedef struct				s_instruction
{
	char					*raw_string;
	int						line_number;
	unsigned int			bytes_size;
	char					op_code;
	char					format;
	int						number_of_args;
	char					*args_type;
	int						*args_value;
	int						*args_byte_size;
	int						number_of_label_called;
	char					**label_called;
	struct s_instruction	*next;
}							t_instruction;

/* INSTRUCTION STRUCTURE */

/* Contains information about the Instruction itself */

/*
** Instruction string.
** Number of the line.
** Size (Bytes).
** Instruction op_code.
** Format Byte.
** Number of arguments.
** Type of arguments.
** Value of arguments.
** Size (Bytes) of arguments.
** Number of label called in the instruction.
** Name of called label.
** Next pointer.
*/

typedef struct				s_file_line
{
	char					*line;
	int						line_number;
	char					is_name;
	char					is_comment;
	char					is_label;
	char					is_instruction;
	struct s_file_line		*next;
}							t_file_line;

/* FILE STRUCTURE */

/* Contains each line of the file. */

/*
** File string line by line.
** Number of the line.
** Is the line a name definition?
** Is the line a comment definition?
** Is the line a label? // usefull to create label_linked_list
** Is the line an instruction?
** Next pointer.
*/

typedef struct				s_data
{
	struct s_file_line		*file_content;
	struct s_label_list		*label_list;
	int						error_line;
	int						total_file_size;
	char					*name;
	char					*comment;
	char					has_name;
	char					has_comment;
	char					has_instructions;
	char					display_byte_info;
}							t_data;

/* DATA STRUCTURE */

/* Contains data about everything. */

/*
** Structure with every line of the file.
** Line number of the error;
** Size (Bytes) of the file.
** File name.
** File comment.
** Does the file has a name?
** Does the file has a comment?
** Does the file has instructions?
** Display byte decomposition during assemble.
*/

/*
typedef enum				e_parsing_error
{
	NO_ERROR,
	EMPTY_FILENAME,
	NOT_A_DOT_S_FILE,
	UNREADABLE_FILE,
	EMPTY_FILE,
	MULTIPLE_NAME_DEFINITIONS,
	MULTIPLE_COMMENT_DEFINITIONS,
	MISSING_NAME,
	MISSING_COMMENT,
	INVALID_CHARACTER,
	INVALID_INSTRUCTION,
	INVALID_INSTRUCTION_FORMAT,
	INVALID_PARAMS_NUMBER,
	INVALID_REGISTER,
	UNKNOW_LABEL,
	MISSING_MAGIC_CODE,
	MISSING_INSTRUCTIONS,
	MULTIPLE_INSTRUCTIONS,
	CANT_CREATE
}							t_parsing_error;

typedef struct				s_label
{
	char					*name;
	struct s_instruction	*instructions;
	unsigned int			bytes_size;
	struct s_label			*next;
}							t_label;
TODO : Redo it later.
typedef struct				s_asm_data
{
	char					*base_filename;
	char					*name;
	char					*comment;
	int						line_number_of_error;
	t_parsing_error			error;
	struct s_instruction	*lines;
	struct s_label			*labels;
	int						just_switched_label;
	int						total_size;
	int						display_byte_info;
}							t_asm_data;
*/

void						add_label_to_list(char	*name, t_data *data,
							int line_number);
int							stock_comment(t_file_line *node, t_data *data,
							int i);
int							stock_name(t_file_line *node, t_data *data, int i);
void						assemble(char *file, t_data *data);
t_instruction				*create_lst_instruction(char *line,
							int line_number);
void						get_asm_body(int fd, t_instruction **instruction,
							unsigned int size);
int							get_number_of_arg(char *s);
void						check_args(int argc, char **argv);
void						disassemble(char *file);
void						get_asm_body(int fd, t_instruction **instruction,
							unsigned int size);
char						*remove_comment_from_line(char *line);

/* DISPLAY FUNCTIONS */

int							display_error(char *message, char *file);
int							display_error_line(char *message, char *file,
							int line, int c);
int							display_instruction_error(int line, char *file,
							int c, char *instruction);
int							display_label_error(int line, char *label,
							char *file, int er_line);
void						display_comment_definition_error(char *file,
							t_data *data);
void						display_name_definition_error(char *file,
							t_data *data);
void						display_usage(void);
void						display_success(char *filename);

/* TEST FUNCTIONS */

void						check_comment(t_data *data);
int							check_forbidden_characters(char *s, int *i);
void						check_name(t_data *data);
int							does_instruction_exist(char *s);
int							get_shorten_len(char *s);
int							is_a_cor_file(char *filename);
int							is_a_s_file(char *filename);
int							is_file_valid(char *file);
int							is_instruction_label(char *s);
int							is_only_flags_or_nothing(int argc, char **argv);
int							label_already_exist(t_data *data, char *label_name);
int							line_starts_with_comment(char *s);
int							line_has_comment(char *s);
int							was_already_called(char **argv, int index);

/* READING FUNCTIONS */

void						stock_file_content(t_data *data, int fd);
void						add_file_content_line(t_data *data, char *line);

int							read_fixed_param_types(int fd, t_instruction *instr,
							int *i);
int							read_format(int fd, t_instruction *instr, int *i);
int							read_op_code(int fd, t_instruction *instr, int *i);
void						read_param_types(t_instruction *instr);
int							read_param_value(int fd, t_instruction *instr);

/* WRITING FUNCTIONS */

int							create_asm_file(char *file, int reading_fd);
void						create_cor_file(char *file, t_data *data);
void						write_asm_body(int fd, t_instruction *instr);
void						write_asm_header(int fd, t_header header);
void						write_asm_param(int fd, t_instruction *instr);
void						write_cor_header(int fd, t_data *data);

/* FREE FUNCTIONS */

void						reset_data_struct(t_data *data);
void						free_file_content(t_data *data);
void						free_list(t_instruction *list);

/* DELETE FUNCTIONS */

void						delete_label_list(t_label_list *list);
void						remove_comment_from_file_content(t_data *data);
void						remove_name_from_file_content(t_data *data);

/* PARSING FUNCTIONS */

int							check_instructions(char *file, t_data *data);
int							check_instruction_label(char *file, t_data *data,
							t_file_line *node);
int							check_instruction_line(char *file, t_data *data,
							t_file_line *node, int index);
int							cut_name_and_check_syntax(char *file, t_data *data);
int							cut_comment_and_check_syntax(char *file,
							t_data *data);

#endif
