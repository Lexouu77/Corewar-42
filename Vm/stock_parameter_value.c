/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_parameter_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 21:12:44 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/14 22:46:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	cast_values(t_vm_data *arena, t_instr *instruction, int index,
		t_player *player)
{
	set_color_field_owner(arena, arena->tmp_args_value[index],
			player->process, instruction->i);
	if (arena->tmp_args_value[index] == 2)
	{
		arena->field[player->process->pc + instruction->i] =
			(arena->tmp >> 8) & 0xFF;
		arena->field[player->process->pc + ++instruction->i] =
			arena->tmp & 0xFF;
	}
	else if (arena->tmp_args_value[index] == 4)
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
		arena->field[player->process->pc + instruction->i] =
			arena->tmp & 0xFF;
}

int			stock_parameter_value(t_vm_data *arena, t_instr *instruction,
		t_player *player, int *size)
{
	int		i;

	if (!g_op_tab[instruction->op_code - 1].byte_param)
		return (1);
	i = -1;
	get_instruction_parameter_size(arena, instruction->format,
			instruction->number_of_args, instruction->op_code);
	while (++i < instruction->number_of_args)
	{
		if (!(read(instruction->fd, &arena->tmp, arena->tmp_args_value[i])))
		{
			free(arena->tmp_args_value);
			return (0);
		}
		byte_swap(&arena->tmp, arena->tmp_args_value[i]);
		cast_values(arena, instruction, i, player);
		instruction->i++;
		*size = *size - arena->tmp_args_value[i];
	}
	free(arena->tmp_args_value);
	return (1);
}
