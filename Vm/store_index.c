/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 22:09:58 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 20:51:19 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_sti_instruction(t_proc *process, t_vm_data *arena, int i)
{
	if ((arena->verbosity & 8) != 8)
		return ;
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a sti!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
	{
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
	}
}

void		store_index(t_vm_data *arena, t_proc *process)
{
	int	error;
	int	reg;
	int	tmp;
	int	tmp_two;

	error = 0;
	reg = get_n_reg_param_value(arena, process, 1, &error);
	tmp = (short)get_n_param_value(arena, process, 2, &error);
	tmp_two = get_n_param_value(arena, process, 3, &error);
	if (error)
		return (display_sti_instruction(process, arena, 0));
	display_sti_instruction(process, arena, 1);
	if ((arena->verbosity & 8) == 8)
		ft_printf_fd(arena->fd, "It did stock r%d (%d) at %d bytes away\n",
			reg, process->reg[reg - 1], (tmp + tmp_two) % IDX_MOD);
	write_param_value(arena, process->pc + ((tmp + tmp_two) % IDX_MOD),
			process->reg[reg - 1], process);
	move_pc_from_format(arena, process);
}
