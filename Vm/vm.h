/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 22:30:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/12 16:55:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "./libftprintf/ft_printf.h"
# include "op.h"
# include "vm_struct.h"

extern t_op g_op_tab[];

/*
** DISPLAY FUNCTIONS
*/

int			display_error(char *message, char *filename);
void		display_usage(void);
void		get_number_of_players(t_vm_data *arena);
t_player	*get_winner(t_vm_data *arena);
void		introduce_players(t_vm_data *arena);

/*
** INITIALISATION FUNCTIONS
*/

t_vm_data	*init_data(void);
int			init_game(char **argv, t_vm_data *arena, int argc);
void		init_process(t_vm_data *arena);
void		set_players_number(t_vm_data *arena);

/*
** FREE FUNCTIONS
*/

void		free_arena(t_vm_data *arena);

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

void		check_file_header(t_vm_data *arena);
void		check_players_validity(t_vm_data *arena);
int			is_file_valid(char *file);

/*
** DELETE FUNCTIONS
*/

void		delete_invalid_players(t_vm_data *arena);

#endif
