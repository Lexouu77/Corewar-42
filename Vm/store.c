/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 10:57:07 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/20 12:33:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define TMIDX (tmp % IDX_MOD)
#define CRN(x) check_reg_number(x)

extern t_op g_op_tab[];

static void	display_st_instruction(t_proc *process, t_vm_data *arena, int i)
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
	ft_printf_fd(arena->fd, " is doing a st!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
	{
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
		process->carry = 0;
	}
}

static void	display_st_instruction_end(t_vm_data *arena, t_proc *process,
		int value, int code)
{
	const int	tmp_reg = arena->field[(process->pc + 2) % arena->mem_size];

	if ((arena->verbosity & 8) != 8)
		return ;
	if (code == REG_CODE)
		ft_printf_fd(arena->fd, "It did stock r%d (%d) in r%d\n", tmp_reg ,
				process->reg[tmp_reg - 1], value);
	else
		ft_printf_fd(arena->fd, "It did stock r%d (%d) at %d bytes away\n",
				tmp_reg , process->reg[tmp_reg - 1], value);
}

void		store(t_vm_data *arena, t_proc *process)
{
	const int	tmp_reg = arena->field[(process->pc + 2) % arena->mem_size];
	int			tmp;

	if (((arena->format >> 4) & 0x3) == REG_CODE)
	{
		tmp = arena->field[(process->pc + 3) % arena->mem_size];
		display_st_instruction(process, arena, CRN(tmp - 1) & CRN(tmp_reg - 1));
		if (check_reg_number(tmp - 1) & check_reg_number(tmp_reg - 1))
			process->reg[tmp - 1] = process->reg[tmp_reg - 1];
		if (check_reg_number(tmp - 1) & check_reg_number(tmp_reg - 1))
			display_st_instruction_end(arena, process, tmp, REG_CODE);
		process->pc = (process->pc + 4) % arena->mem_size;
	}
	else
	{
		tmp = get_param_value(arena, process->pc + 3, 4);
		tmp = get_param_value(arena, process->pc + tmp, 4);
		display_st_instruction(process, arena, check_reg_number(tmp_reg - 1));
		if (check_reg_number(tmp_reg - 1))
			write_param_value(arena, process->pc + (tmp % IDX_MOD),
					process->reg[tmp_reg - 1], process);
		if (check_reg_number(tmp_reg - 1))
			display_st_instruction_end(arena, process, TMIDX, IND_CODE);
		process->pc = (process->pc + 7) % arena->mem_size;
	}
}
