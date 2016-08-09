/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 05:31:49 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/09 20:56:17 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NARG instruction->number_of_args

static char	*stock_op_code(char *s)
{
	int		i;

	i = 0;
	while (s[i] && !ft_isspace(s[i]) && s[i] != SEPARATOR_CHAR)
		++i;
	return (ft_strndup(s, i));
}

void	fill_instruction(t_data *data, t_instruction *instruction, char *s)
{
	int			len;
	const char	*tmp = (const char *)stock_op_code(s);
	int			shift;

	shift = 6;
	len = 0;
	instruction->op_code = does_instruction_exist((char *)tmp);
	instruction->number_of_args = g_op_tab[instruction->op_code].arg_number;
	free((char *)tmp);
	instruction->parameter_type = ft_memalloc(sizeof(char) * NARG);
	instruction->parameter_value = ft_memalloc(sizeof(int) * NARG);
	instruction->parameter_size = ft_memalloc(sizeof(int) * NARG);
	instruction->size++;
	while ((len = go_to_next_param(s, len)) != -1)
	{
		if (g_op_tab[instruction->op_code].byte_param)
			stock_format_byte(instruction, s + len, shift);
		stock_param_type(instruction, s + len, shift);
		stock_param_value(instruction, s + len, shift);
		shift -= 2;
	}
	data->total_file_size += instruction->size;
}
