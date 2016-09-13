/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 00:56:32 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/13 17:41:23 by adjivas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>

#include "vm.h"

void				ft_signal_handler(int sig)
{
	if (sig == SIGTSTP)
		sleep(5);
}

int					main(int argc, char **argv)
{
	t_vm_data *arena;

	if (argc == 1)
		display_usage();
	else
	{
		arena = init_data();
		parse_flag(argc, argv, arena);
		if (!init_game(argv, arena, argc))
			exit(-1);
		if (arena->log_file && (arena->fd =
			open("Corewar.log", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
			ft_error("Couldn't create the log file.\n");
		signal(SIGTSTP, ft_signal_handler);
		if (arena->graph == 1)
			core_init();
		play(arena);
		display_winner(arena);
		free_arena(arena);
		free(arena);
	}
	return (0);
}
