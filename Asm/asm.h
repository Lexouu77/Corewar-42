/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 18:07:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 07:02:33 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "./libftprintf/ft_printf.h"
# include "op.h"

extern t_op g_op_tab[];

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
t_instruction				*create_lst_instruction(char *line,
							int line_number);
void						get_asm_body(int fd, t_instruction **instruction,
							unsigned int size);
void						check_args(int argc, char **argv);
void						disassemble(char *file);
void						get_asm_body(int fd, t_instruction **instruction,
							unsigned int size);

/* DISPLAY FUNCTIONS */

int							display_error(char *message, char *file);
void						display_usage(void);
void						display_success(char *filename);

/* TEST FUNCTIONS */

int							is_a_cor_file(char *filename);
int							is_a_s_file(char *filename);
int							is_only_flags_or_nothing(int argc, char **argv);
int							was_already_called(char **argv, int index);

/* READING FUNCTIONS */

int							read_fixed_param_types(int fd, t_instruction *instr,
							int *i);
int							read_format(int fd, t_instruction *instr, int *i);
int							read_op_code(int fd, t_instruction *instr, int *i);
void						read_param_types(t_instruction *instr);
int							read_param_value(int fd, t_instruction *instr);

/* WRITING FUNCTIONS */

int							create_asm_file(char *file, int reading_fd);
void						write_asm_body(int fd, t_instruction *instr);
void						write_asm_header(int fd, t_header header);
void						write_asm_param(int fd, t_instruction *instr);

#endif
