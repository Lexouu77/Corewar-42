/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjivas <adjivas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 16:11:26 by adjivas           #+#    #+#             */
/*   Updated: 2016/09/13 16:13:17 by adjivas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "./libftprintf/ft_printf.h"
# include "op.h"
# include "vm_extern.h"
# include "vm_struct.h"

extern t_op g_op_tab[];

/*
** MAIN FUNCTIONS
*/

void		assemble_asm_file(t_player *player);
void		check_instruction_from_proc(t_vm_data *arena, t_proc *process);
void		check_period(t_vm_data *arena);
void		dump(t_vm_data *arena);
void		dump_and_wait(t_vm_data *arena);
void		execute_instruction(t_vm_data *arena, t_proc *process);
void		increment_waiting_time(t_vm_data *arena, t_proc *process);
int			is_someone_in_game(t_vm_data *arena);
void		kill_player(t_vm_data *arena);
void		manage_keys(t_vm_data *arena);
void		move_pc_from_format(t_vm_data *arena, t_proc *process);
void		move_pc_without_format(t_vm_data *arena, t_proc *process);
void		play(t_vm_data *arena);

/*
** INSTRUCTIONS FUNCTIONS
*/

void		add(t_vm_data *arena, t_proc *process);
void		aff(t_vm_data *arena, t_proc *process);
void		do_and(t_vm_data *arena, t_proc *process);
void		do_fork(t_vm_data *arena, t_proc *process);
void		do_or(t_vm_data *arena, t_proc *process);
void		do_xor(t_vm_data *arena, t_proc *process);
void		live(t_vm_data *arena, t_proc *process);
void		load(t_vm_data *arena, t_proc *process);
void		long_load(t_vm_data *arena, t_proc *process);
void		load_index(t_vm_data *arena, t_proc *process);
void		long_load_index(t_vm_data *arena, t_proc *process);
void		long_fork(t_vm_data *arena, t_proc *process);
void		store(t_vm_data *arena, t_proc *process);
void		store_index(t_vm_data *arena, t_proc *process);
void		sub(t_vm_data *arena, t_proc *process);
void		zjump(t_vm_data *arena, t_proc *process);

/*
** DISPLAY FUNCTIONS
*/

int			display_error(char *message, char *filename);
void		display_field(t_vm_data *arena);
void		display_info(t_vm_data *arena, int i, int d_value);
void		display_usage(void);
int			display_warning(char *message, char *filename);
void		display_winner(t_vm_data *arena);
void		introduce_players(t_vm_data *arena);

/*
** ACCESSOR FUNCTIONS
*/

long		get_n_param_value(t_vm_data *arena, t_proc *proc, int nb, int *err);
int			get_n_param_size(t_vm_data *arena, int n);
int			get_n_reg_param_value(t_vm_data *arena, t_proc *process, int nb,
		int *error);
void		get_number_of_players(t_vm_data *arena);
long		get_param_value(t_vm_data *arena, int pc, int size);
int			get_param_type(t_vm_data *arena, int param_number);
int			get_parameter_size(int op_code, int var_code);
t_player	*get_winner(t_vm_data *arena);
void		set_players_number(t_vm_data *arena);
void		write_param_value(t_vm_data *arena, int pc, int value,
		t_proc *process);
int			get_period_live(t_vm_data *arena);
int			get_last_live(t_vm_data *arena);
char		*get_name(t_vm_data *arena);
char		*get_color(t_vm_data *arena, int number);

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
void		set_color_field_owner(t_vm_data *arena, int size, t_proc *process,
		int index);
void		set_last_player(t_vm_data *arena);
void		set_players_in_field(t_vm_data *arena);
void		set_players_in_game(t_vm_data *arena);

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
int			check_reg_number(int reg_number);
int			is_a_s_file(char *filename);
int			is_file_valid(char *file);

/*
** DELETE-FREE FUNCTIONS
*/

void		delete_invalid_players(t_vm_data *arena);
void		free_arena(t_vm_data *arena);

#endif
