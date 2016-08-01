/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 05:31:49 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 13:06:09 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


void	fill_instruction(t_data *data, t_instruction *instruction, char *s)
{
	int			len;
	char		*tmp;
	int			shift;
	const int	arg_number = g_op_tab[instruction->op_code].arg_number;

	shift = 6;
	len = 0;
	tmp = ft_strndup(s, len);
	instruction->op_code = does_instruction_exist(tmp);
	free(tmp);
	instruction->parameter_type = ft_memalloc(sizeof(char) * arg_number);
	instruction->parameter_value = ft_memalloc(sizeof(int) * arg_number);
	instruction->parameter_size = ft_memalloc(sizeof(int) * arg_number);
	while ((len = go_to_next_param(s, 0)) != -1)
	{
		if (g_op_tab[instruction->op_code].byte_param)
			stock_format_byte(instruction, s + len, shift);
		stock_param_type(instruction, s + len, shift);
		stock_param_value(instruction, s + len, shift);
		shift -= 2;
	}
	data->total_file_size += instruction->size;
	stock_label_distance(data);
	if (data->display_instruction_info)
		display_instruction_info(data);
}
