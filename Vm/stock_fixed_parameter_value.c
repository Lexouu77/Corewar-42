/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_fixed_parameter_value.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 21:17:04 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/14 21:30:24 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	cast_fixed_values(t_vm_data *arena, t_instr *instruction, int size,
		t_player *player)
{
	if (size == 2)
	{
		arena->field[player->process->pc + instruction->i] =
			(arena->tmp >> 8) & 0xFF;
		arena->field[player->process->pc + ++instruction->i] =
			arena->tmp & 0xFF;
	}
	else if (size == 4)
	{
		arena->field[player->process->pc + instruction->i] =
			(arena->tmp >> 24) & 0xFF;
		arena->field[player->process->pc + ++instruction->i] =
			(arena->tmp >> 16) & 0xFF;
		arena->field[player->process->pc + ++instruction->i] =
			(arena->tmp >> 8) & 0xFF;
		arena->field[player->process->pc + ++instruction->i] =
			arena->tmp & 0xFF;
	}
	else
		arena->field[player->process->pc + instruction->i] = arena->tmp & 0xFF;
}

int	stock_fixed_parameter_value(t_vm_data *arena, t_instr *instruction,
		t_player *player, int *size)
{
	const int	direct_size = (g_op_tab[instruction->op_code - 1].byte_dir) ?
		IND_SIZE : DIR_SIZE;
	if (g_op_tab[instruction->op_code - 1].byte_param)
		return (1);
	if (!(read(instruction->fd, &arena->tmp, direct_size)))
		return (0);
	byte_swap(&arena->tmp, direct_size);
	cast_fixed_values(arena, instruction, direct_size, player);
	instruction->i++;
	*size = *size - direct_size;
	return (1);
}
