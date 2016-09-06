/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 05:37:05 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/06 16:32:37 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define EM "Error : Invalid format for op_code : %d at pc : %d at cycle : %d\n"

static void	quick_reset_process(t_proc *process)
{
	process->is_waiting = 0;
	process->cycles_waiting = 0;
	process->cycles_to_wait = 0;
}

static int	check_format(t_vm_data *arena, t_proc *process)
{
	int	i;
	int	shift;

//	arena->op_code = arena->field[process->pc];
	arena->op_code = process->op_code;
	if (!g_op_tab[arena->op_code - 1].byte_param)
		return (1);
	shift = 6;
	i = -1;
	arena->format = arena->field[((process->pc + 1) % arena->mem_size)];
	while (++i < g_op_tab[arena->op_code - 1].arg_number)
	{
		if ((((arena->format >> shift) & 3) &
				g_op_tab[arena->op_code - 1].args_type[i]) == 0)
		{
//			ft_printf_fd(2, EM, arena->op_code, process->pc, arena->cycles);
			if (g_op_tab[arena->op_code - 1].byte_param)
				//process->pc = ((process->pc + 2) % arena->mem_size);
				move_pc_from_format(arena, process);
			else
				move_pc_without_format(arena, process);
			quick_reset_process(process);
			return (0);
		}
		shift -= 2;
	}
	return (1);
}

void		execute_instruction(t_vm_data *arena)
{
	t_player		*player;
	t_proc			*process;
	static void		(*f[16])(t_vm_data *, t_proc *) = {live, load, store,
		add, sub, do_and, do_or, do_xor, zjump, load_index, store_index,
		do_fork, long_load, long_load_index, long_fork, aff};

	player = arena->last_player;
	while (player)
	{
		process = player->last_process;
		while (process)
		{
			if (process->op_code - 1 < 0 || process->op_code - 1 > 16)
			{
				ft_printf_fd(2, "FATAL ERROR INVALID OP CODE : %d num : %d pc : %d\n", arena->field[process->pc] - 1, process->number, process->pc);
				//exit(0);
			}
			if (process->is_waiting &&
					process->cycles_waiting == process->cycles_to_wait - 1 && check_format(arena, process))
			{
				f[process->op_code - 1](arena, process);
				quick_reset_process(process);
			}
			process = process->prev;
		}
		player = player->prev;
	}
}
