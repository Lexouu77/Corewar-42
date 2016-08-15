/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:34:05 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 20:54:56 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "./libftprintf/ft_printf.h"
# include "op.h"
# include "client_struct.h"

extern t_op g_op_tab[];

void		assemble_asm_file(t_player *player);

/*
** DISPLAY FUNCTIONS
*/

int			display_error(char *message, char *filename);
void		display_usage(void);
int			display_warning(char *message, char *filename);
void		introduce_players(t_vm_data *arena);

/*
** ACCESSOR FUNCTIONS
*/

void		get_number_of_players(t_vm_data *arena);
t_player	*get_winner(t_vm_data *arena);
void		set_players_number(t_vm_data *arena);

/*
** INITIALISATION FUNCTIONS
*/

t_vm_data	*init_data(void);
int			init_game(char **argv, t_vm_data *arena, int argc);
void		init_process(t_vm_data *arena);

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
