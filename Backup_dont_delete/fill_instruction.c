/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 05:31:49 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/02 19:27:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NB_ARG g_op_tab[instruction->op_code].arg_number

// data pour le -a
//
void	fill_instruction(t_data *data, t_instruction *instruction, char *s)
{
	(void)data;
	(void)instruction;
	(void)s;
/*	int		len;
	char	*tmp;
	int		shift;

	shift = 6;
	tmp = ft_strndup(s, len);
	instruction->op_code = does_instruction_exist(tmp);
	free(tmp);
	instruction->args_type = ft_memalloc(sizeof(char) * NB_ARG);
	instruction->args_value = ft_memalloc(sizeof(int) * NB_ARG);
	instruction->args_byte_size = ft_memalloc(sizeof(int) * NB_ARG);
	while ((len = go_to_next_param(s, 0)) != -1)
	{
		if (g_op_tab[instruction->op_code].byte_param)
			stock_format_byte(instruction, s + len);
		stock_param_type(instruction, s + len);
		stock_param_value(instruction, s + len);
		shift -= 2;
	}
	data->total_file_size += instruction->size;
	stock_label_distance(data);
	if (data->display_instruction_info)
		display_instruction_info(data);*/
}
