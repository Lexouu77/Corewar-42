/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 20:35:04 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 21:54:50 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		fill_field(t_vm_data *arena, t_player *player, int prog_sz, int fd)
{
	int			size;
	t_instr		instruction;

	size = prog_sz;
	instruction.i = 0;
	instruction.fd = fd;
	instruction.format = 0;
	while (size)
	{
		if (!stock_op_code(arena, &instruction, player, &size))
			break ;
		if (!stock_format(arena, &instruction, player, &size))
			break ;
		if (!stock_parameter_value(arena, &instruction, player, &size))
			break ;
		if (!stock_fixed_parameter_value(arena, &instruction, player, &size))
			break ;
	}
}
