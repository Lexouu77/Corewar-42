/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_op_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 20:47:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/14 21:29:00 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	stock_op_code(t_vm_data *arena, t_instr *instruction,
		t_player *player, int *size)
{
	if (!read(instruction->fd, &instruction->op_code, 1))
		return (0);
	arena->field[player->process->pc + instruction->i] = instruction->op_code;
	arena->color_field[player->process->pc + instruction->i] =
		player->number_of_player;
	instruction->i++;
	*size = *size - 1;
	instruction->number_of_args = g_op_tab[instruction->op_code - 1].arg_number;
	return (1);
}
