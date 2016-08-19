/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:07:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/19 04:25:24 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_ld_instruction(t_proc *process, t_vm_data *arena, int i)
{
	if ((arena->verbosity & 8) != 8)
	{
		if (!i)
			process->carry = 0;
		return ;
	}
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a ld!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
	{
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
		process->carry = 0;
	}
}

void		load(t_vm_data *arena, t_proc *process)
{
	const int	reg = get_param_value(arena, process->pc + 6, 1);
	int			tmp;

	if (!check_reg_number(reg - 1))
	{
		process->pc = (process->pc + 7) % arena->mem_size;
		return (display_ld_instruction(process, arena, 0));
	}
	tmp = get_param_value(arena, process->pc + 2, 4);
	if (get_param_type(arena, 1) == DIR_CODE)
		tmp = get_param_value(arena, process->pc + (tmp % IDX_MOD), 4);
	process->reg[reg - 1] = tmp;
	if ((arena->verbosity & 8) != 8)
		ft_printf_fd(arena->fd, "It stocked %d in reg %d\n", tmp, reg);
	process->carry = 1;
}
