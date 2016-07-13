/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 00:56:32 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/20 18:42:19 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_vm_data	*init_data(void)
{
	t_vm_data *arena;

	if (!(arena = (t_vm_data *)ft_memalloc(sizeof(t_vm_data))))
		ft_malloc_error();
	arena->mem_size = MEM_SIZE * sizeof(int);
	if (!(arena->field = (int*)ft_memalloc(arena->mem_size)) ||
			!(arena->process_field = (int*)ft_memalloc(arena->mem_size)) ||
			!(arena->fresh_field = (int*)ft_memalloc(arena->mem_size)) ||
			!(arena->color_field = (int*)ft_memalloc(arena->mem_size)))
		ft_malloc_error();
	arena->max_checks = MAX_CHECKS;
	arena->cycles_to_die = CYCLE_TO_DIE;
	arena->cycle_delta = CYCLE_DELTA;
	arena->nbr_live = NBR_LIVE;
	arena->next_cycle_check = arena->cycles_to_die;
	arena->number_of_checks++;
	arena->process_next_number++;
	return (arena);
}

static void			display_usage(void)
{
	ft_printf("%[[FG_YEL,SP_RST]s : ./corewar [", "Usage");
	ft_printf("%[[FG_MAG,SP_RST]s (Color Display) | ", "-c");
	ft_printf("%[[FG_RED,SP_RST]s [0-9] (Dump) | ", "-d");
	ft_printf("%[[FG_YEL,SP_RST]s [0-9] (Set Player Number) | ", "-n");
	ft_printf("%[[FG_BLU,SP_RST]s [0-9] (Loop Dump) | ", "-l");
	ft_printf("%[[FG_GRE,SP_RST]s [1|2|4|8] (Verbosity Mod) | ", "-v");
	ft_printf("%[[FG_CYA,SP_RST]s (Graphic Mod) | ", "-g");
	ft_printf("%[[FG_CYA,SP_RST]s (Create a Log File)]", "-f");
	ft_printf(" [file%[[FG_MAG,SP_RST]s] [file%[[FG_MAG,SP_RST]s] ...\n",
			".s", ".cor");
	ft_printf("Verbosity : \t - 1 : Show lives.\n");
	ft_printf("\t\t - 2 : Show cycles.\n");
	ft_printf("\t\t - 4 : Show deaths.\n");
	ft_printf("\t\t - 8 : Show instruction execution.\n");
	ft_printf("-Playing with more than four valid players will only ");
	ft_printf("use the four first valid ones as players.\n");
	ft_printf("-Playing with no valid players won't trigger the arena.\n");
	ft_printf("-Using someone who isn't tagged with the COREWAR_EXEC_MAGIC");
	ft_printf(" won't validate his participation.\n");
	ft_printf("-Dump and Loop Dump bonuses can't work together.\n");
	ft_printf("-Graphic will automatically set Color + Log File and ");
	ft_printf("unset Loop Dump + Dump.\n");
	ft_printf("-Press [SPACE] to pause the vm in Graphic mode. -/+ to set the");
	ft_printf(" time between each cycles.\n");
}

static void			display_winner(t_vm_data *arena)
{
	t_player	*player;

	player = get_winner(arena);
	ft_printf("The winner is : ");
	if (player->number_of_player == 1)
		ft_printf(" %[[FG_GRE,SP_RST]s", player->name);
	if (player->number_of_player == 2)
		ft_printf(" %[[FG_BLU,SP_RST]s", player->name);
	if (player->number_of_player == 3)
		ft_printf(" %[[FG_RED,SP_RST]s", player->name);
	if (player->number_of_player == 4)
		ft_printf(" %[[FG_CYA,SP_RST]s", player->name);
	if (player->number_of_player == 1)
		ft_printf(" (%[[BG_GRE,SP_RST]s)!\n", player->comment);
	if (player->number_of_player == 2)
		ft_printf(" (%[[BG_BLU,SP_RST]s)!\n", player->comment);
	if (player->number_of_player == 3)
		ft_printf(" (%[[BG_RED,SP_RST]s)!\n", player->comment);
	if (player->number_of_player == 4)
		ft_printf(" (%[[BG_CYA,SP_RST]s)!\n", player->comment);
}

static void			free_arena(t_vm_data *arena)
{
	t_player	*player;

	player = arena->players;
	while (player)
	{
		free(player->name);
		free(player->comment);
		player = player->next;
	}
	if (arena->log_file)
		close(arena->fd);
	free(arena->field);
	free(arena->color_field);
	free(arena->process_field);
	free(arena->fresh_field);
}

static void			sighandler(int sig_num)
{
	if (sig_num == SIGINT)
		endwin();
	if (sig_num == SIGINT || sig_num == SIGQUIT)
		exit(1);
}

int					main(int argc, char **argv)
{
	t_vm_data *arena;

	if (argc == 1)
		display_usage();
	else
	{
		signal(SIGINT, sighandler);
		signal(SIGQUIT, sighandler);
		arena = init_data();
		check_bonus(argc, argv, arena);
		if (!init_game(argv, arena, argc))
			exit(-1);
		if (arena->log_file)
			if ((arena->fd =
						open("Corewar.log", O_WRONLY | O_CREAT | O_TRUNC, 0644))
					== -1)
				ft_error("Couldn't create the log file.\n");
		if (arena->graph)
			ncurses_play(arena);
		else
			play(arena);
		display_winner(arena);
		free_arena(arena);
		free(arena);
	}
	return (0);
}
