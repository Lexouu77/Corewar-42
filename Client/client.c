/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:24:28 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 19:28:09 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int					client(int argc, char **argv)
{
	t_vm_data *arena;

	if (argc == 1)
		display_usage(); // change it ? ./client instead of Corewar i guess
	else
	{
		arena = init_data();
		parse_flag(argc, argv, arena);
		if (!init_game(argv, arena, argc))
			exit(-1);
	//	send_file_to_server(data->players); // sending players linked_list to server.
		free_arena(arena);
		free(arena);
	}
	return (0);
}

 // TODO : Remove flags unless -n 'digit'
