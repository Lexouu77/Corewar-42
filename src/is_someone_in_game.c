/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_someone_in_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 23:12:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/13 15:55:30 by adjivas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		display_kill_process(t_proc *process, t_vm_data *arena)
{
	arena->number_of_process--;
	if ((arena->verbosity & 4) == 4)
	{
		ft_printf_fd(arena->fd, "Process number : %d", process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d",
				process->father->number_of_player);
		ft_printf_fd(arena->fd, " just died !\n");
	}
}

static	t_proc	*kill_last_process(t_proc *process, t_vm_data *arena)
{
	free(process->reg);
	free(process);
	arena->process = NULL;
	arena->last_process = NULL;
	return (NULL);
}

static t_proc	*reset_and_go_to_next_process(t_proc *process)
{
	process->lives = 0;
	return (process->next);
}

static t_proc	*kill_process(t_proc *process, t_vm_data *arena)
{
	t_proc	*tmp;

	tmp = process;
	if (process->lives)
		return (reset_and_go_to_next_process(process));
	display_kill_process(process, arena);
	if (!process->next && !process->prev)
		return (kill_last_process(process, arena));
	free(process->reg);
	if (!process->next)
	{
		arena->last_process = process->prev;
		arena->last_process->next = NULL;
		free(process);
		return (NULL);
	}
	process = process->next;
	process->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = process;
	if (tmp == arena->process)
		arena->process = process;
	free(tmp);
	return (process);
}

int				is_someone_in_game(t_vm_data *arena)
{
	t_proc		*process;

	process = arena->process;
	while (process)
		process = kill_process(process, arena);
	if (!arena->process)
	{
		kill_player(arena);
		return (0);
	}
	check_period(arena);
	return (1);
}
