/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 20:47:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/14 21:14:25 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	stock_format(t_vm_data *arena, t_instr *instruction,
	t_player *player, int *size)
{
	if (!g_op_tab[instruction->op_code - 1].byte_param)
		return (1);
	if (!read(instruction->fd, &instruction->format, 1))
		return (0);
	arena->field[player->process->pc + instruction->i] = instruction->format;
	arena->color_field[player->process->pc + instruction->i] =
	player->number_of_player;
	instruction->i++;
	*size = *size - 1;
	return (1);
}
