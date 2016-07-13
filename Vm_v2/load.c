/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:07:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 12:43:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_ld_instruction(t_proc *process, t_vm_data *arena, int i)
{
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

static int	get_arg_val(t_proc *process, t_vm_data *arena, int i, int shift)
{
	if ((arena->field[(process->pc + 1) % arena->mem_size] >> shift
					& 3) == REG_CODE)
		return (process->reg[i - 1]);
	else
		return (i);
}

void		load(t_vm_data *arena, t_proc *process)
{
	int		tmp_one;
	int		tmp_reg;
	int		size;
	int		i;

	size = 0;
	tmp_one = get_param_value(arena, process, &size, 6);
	tmp_reg = arena->field[(process->pc + size + 1) % arena->mem_size];
	process->pc = (process->pc + 1) % arena->mem_size;
	size = 1;
	i = check_reg_number(arena, process, &size);
	if (i)
		tmp_one = get_arg_val(process, arena, tmp_one, 6);
	if ((arena->verbosity & 8) == 8)
		display_ld_instruction(process, arena, i);
	if (i && (arena->verbosity & 8) == 8)
		ft_printf_fd(arena->fd, "It did stock in r%d the value (%d)\n",
			tmp_reg, tmp_one);
	if (i)
	{
			process->reg[tmp_reg - 1] = tmp_one;
			process->carry = 1;
		//add color/process/fresh field avec une fonction : write_mem(WHERE, WHAT, arena, process)
	}
	process->pc = (process->pc + size + 1) % arena->mem_size;
}
