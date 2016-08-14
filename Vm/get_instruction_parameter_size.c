/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction_parameter_size.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 21:14:20 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/14 21:14:23 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_instruction_parameter_size(t_vm_data *arena, int format,
		int number_of_param, int op_code)
{
	int	shift;
	int	i;

	arena->tmp_args_value = ft_memalloc(sizeof(int) * number_of_param);
	i = -1;
	while (++i < number_of_param)
	{
		shift = 6 - 2 * i;
		if (((format >> shift) & 0x3) == REG_CODE)
			arena->tmp_args_value[i] = 1;
		if (((format >> shift) & 0x3) == IND_CODE)
			arena->tmp_args_value[i] = IND_SIZE;
		if (((format >> shift) & 0x3) == DIR_CODE)
			arena->tmp_args_value[i] =
				(g_op_tab[op_code - 1].byte_dir) ? IND_SIZE : DIR_SIZE;
	}
}
