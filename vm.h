/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 22:30:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 12:43:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "./libftprintf/ft_printf.h"
# include "op.h"
# include <curses.h>
# include <signal.h>
# include "vm_struct.h"

void		check_bonus(int argc, char **argv, t_vm_data *arena);

int			init_game(char **argv, t_vm_data *arena, int argc);

void		get_players_id(char **argv, t_vm_data *arena, int argc);

int			display_error(char *message, char *filename);

void		add_player(t_vm_data *arena, int desired_number, char *file);

t_player	*new_player(int	desired_number, char *file);

void		check_players_validity(t_vm_data *arena);

void		delete_invalid_players(t_vm_data *arena);

void		check_file_and_header(t_vm_data *arena);

void		get_number_of_players(t_vm_data *arena);

void		set_players_number(t_vm_data *arena);

void		init_process(t_vm_data *arena);

void		set_players_in_field(t_vm_data *arena);

void		set_last_player(t_vm_data *arena);

void		introduce_players(t_vm_data *arena);

void		play(t_vm_data *arena);

void		ncurses_play(t_vm_data *arena);

void		display_field(t_vm_data *arena);

void		increment_waiting_time(t_vm_data *arena);

void		check_instruction_from_proc(t_vm_data *arena);

void		check_period(t_vm_data *arena);

void		kill_player(t_vm_data *arena);

void		execute_instruction(t_vm_data *arena);

void		live(t_vm_data *arena, t_proc *process);

t_player	*get_winner(t_vm_data *arena);

int			get_direct_arg_value(t_vm_data *arena, t_proc *process,
int *byte_size);

void		zjump(t_vm_data *arena, t_proc *process);

void		aff(t_vm_data *arena, t_proc *process);

void		add(t_vm_data *arena, t_proc *process);

void		do_and(t_vm_data *arena, t_proc *process);

void		do_xor(t_vm_data *arena, t_proc *process);

void		do_fork(t_vm_data *arena, t_proc *process);

void		long_fork(t_vm_data *arena, t_proc *process);

void		sub(t_vm_data *arena, t_proc *process);

void		do_or(t_vm_data *arena, t_proc *process);

void		store_index(t_vm_data *arena, t_proc *process);

void		store(t_vm_data *arena, t_proc *process);

void		load(t_vm_data *arena, t_proc *process);

int			check_reg_number(t_vm_data *arena, t_proc *process, int *size);

int			get_param_value(t_vm_data *arena, t_proc *process, int *size,
int shift);

void        set_players_in_game(t_vm_data *arena);

int			is_someone_alive(t_vm_data *arena);

#endif
