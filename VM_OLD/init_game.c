/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 02:37:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/10 06:36:55 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		init_game(char **argv, t_vm_data *arena, int argc)
{
	get_players_id(argv, arena, argc);
	check_players_validity(arena);
	delete_invalid_players(arena);
	check_file_and_header(arena);
	delete_invalid_players(arena);
	get_number_of_players(arena);
	set_players_number(arena);
	if (!arena->number_of_valid_player)
		return (display_error("Not enough valid players.", NULL));
	delete_invalid_players(arena);
	init_process(arena);
	if (!arena->number_of_valid_player)
		return (display_error("Not enough valid players.", NULL));
	set_players_in_field(arena);
	introduce_players(arena);
	return (1);
}