/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 18:07:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/03 13:56:17 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "./libftprintf/ft_printf.h"
# include "op.h"

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

void						epur_str(char **str);

t_label						*create_lst_label(char *label_name);
void						push_lst_label(t_label **begin, t_label *to_add);

t_instruction				*create_lst_instruction(char *line, int number);
void						push_lst_instruction(t_instruction **begin,
		t_instruction *to_add);

int							is_comment(char *s);

int							is_a_label(char *line);

t_label						*add_label_and_switch(t_asm_data *data, char *line,
		t_label *current_label);

int							lines_are_correct(t_asm_data *data);

void						stock_instructions(t_asm_data *data, char *line,
		t_label *current_label, int line_number);

int							line_is_comment(char *line);
void						extract_comment_from_line(char *line,
		t_asm_data *data);
int							has_name(t_asm_data *data);
int							line_is_name(char *line);
void						extract_name_from_line(char *line,
		t_asm_data *data);
int							has_comment(t_asm_data *data);

int							check_unknown_label_call(t_asm_data *data);
int							label_has_instructions(t_instruction *line);
int							check_line_error(char *line);

int							create_file(char *file, t_asm_data *data);

int							is_valid_filename(char *filename, t_asm_data *data);

void						print_usage_and_exit(void);

int							check_bonus_flags(char *flag, t_asm_data *data);

int							is_a_cor_file(char *filename);

int							get_op_code(char *line);

t_instruction				*get_instruction(t_label *label, char *line,
		int line_number);

void						init_instruction(t_instruction *instr, int i);

void						display_info(t_asm_data *data);

int							check_line_error(char *line);

void						stock_label_called_name(t_instruction *instr,
		char *line);

char						*go_to_next_parameter(char *line);

void						get_distance_to_label(t_asm_data *data);

void						disassemble(char *filename);

void							get_body(int fd, t_instruction **instr,
		unsigned int prog_size);

void						write_body(int fd, t_instruction *instr);

void						print_success(char *filename);
#endif
