/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 22:30:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/14 22:07:17 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "./libftprintf/ft_printf.h"
# include "op.h"
# include "vm_struct.h"

extern t_op g_op_tab[];

void		assemble_asm_file(t_player *player);

/*
** DISPLAY FUNCTIONS
*/

int			display_error(char *message, char *filename);
void		display_field(t_vm_data *arena);
void		display_usage(void);
int			display_warning(char *message, char *filename);
void		display_winner(t_vm_data *arena);
void		introduce_players(t_vm_data *arena);

/*
** ACCESSOR FUNCTIONS
*/

void		get_number_of_players(t_vm_data *arena);
t_player	*get_winner(t_vm_data *arena);
void		set_players_number(t_vm_data *arena);

/*
** STOCK FUNCTIONS
*/

void		get_instruction_parameter_size(t_vm_data *arena, int format,
			int number_of_param, int op_code);
int			stock_fixed_parameter_value(t_vm_data *arena, t_instr *instruction,
			t_player *player, int *size);
int			stock_format(t_vm_data *arena, t_instr *instruction,
			t_player *player, int *size);
int			stock_op_code(t_vm_data *arena, t_instr *instruction,
			t_player *player, int *size);
int			stock_parameter_value(t_vm_data *arena, t_instr *instruction,
			t_player *player, int *size);

/*
** INITIALISATION FUNCTIONS
*/

void		fill_field(t_vm_data *arena, t_player *player, int prog_sz, int fd);
t_vm_data	*init_data(void);
int			init_game(char **argv, t_vm_data *arena, int argc);
void		init_process(t_vm_data *arena);
void		set_players_in_field(t_vm_data *arena);

/*
** PARSING FUNCTIONS
*/

void		parse_flag(int argc, char **argv, t_vm_data *arena);
void		stock_players_and_number(char **argv, t_vm_data *arena, int argc);

/*
** LINKED_LIST FUNCTIONS
*/

void		add_player(t_vm_data *arena, int desired_number, char *file);
t_player	*create_new_player(int desired_number, char *file);

/*
** TEST FUNCTIONS
*/

void		check_asm_file(t_vm_data *arena);
void		check_file_header(t_vm_data *arena);
void		check_players_validity(t_vm_data *arena);
int			is_a_s_file(char *filename);
int			is_file_valid(char *file);

/*
** DELETE-FREE FUNCTIONS
*/

void		delete_invalid_players(t_vm_data *arena);
void		free_arena(t_vm_data *arena);

#endif
