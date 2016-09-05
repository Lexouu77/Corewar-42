/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 00:56:32 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 07:10:56 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
		play(arena);
		display_winner(arena);
		free_arena(arena);
		free(arena);
	}
	return (0);
}/*

int	main(void)
{
	ft_printf_buffed(0, "test, %s", " LOL ");
//	ft_printf_buffed(0, "test %d\n", 35);
	ft_printf("LEN DISPLAYED = %d\n", ft_printf_buffed(1, NULL));
}*/
