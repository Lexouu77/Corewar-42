/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 10:57:07 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 18:12:15 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_st_instruction(t_proc *process, t_vm_data *arena, int i)
{
	if ((arena->verbosity & 8) != 8)
		return ;
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a st!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
	{
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
	}
}

static void	store_b(t_vm_data *arena, t_proc *process, int reg, int error)
{
	int		tmp;

	tmp = (short)get_n_param_value(arena, process, 2, &error);
	if (error)
	{
		move_pc_from_format(arena, process);
		return (display_st_instruction(process, arena, 0));
	}
	display_st_instruction(process, arena, 1);
	write_param_value(arena, process->pc + (tmp % IDX_MOD),
			process->reg[reg - 1], process);
	move_pc_from_format(arena, process);
	if ((arena->verbosity & 8) == 8)
		ft_printf_fd(arena->fd, "It did stock r%d (%d) at %d bytes away\n",
				reg, process->reg[reg - 1], tmp);
}

void		store(t_vm_data *arena, t_proc *process)
{
	int	error;
	int	reg;
	int	tmp;

	error = 0;
	reg = get_n_reg_param_value(arena, process, 1, &error);
	if (get_param_type(arena, 2) == REG_CODE)
	{
		tmp = get_n_reg_param_value(arena, process, 2, &error);
		move_pc_from_format(arena, process);
		if (error)
			return (display_st_instruction(process, arena, 0));
		display_st_instruction(process, arena, 1);
		if ((arena->verbosity & 8) == 8)
			ft_printf_fd(arena->fd, "It did stock r%d (%d) in r%d\n", reg,
					process->reg[reg - 1], tmp);
		process->reg[tmp - 1] = process->reg[reg - 1];
	}
	else
		store_b(arena, process, reg, error);
}
