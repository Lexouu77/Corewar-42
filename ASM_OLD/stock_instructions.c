/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 03:14:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/25 18:54:54 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_op_tab[];

/*
** If shift = 6 -> byte_size++ for the format !
*/

static void	stock_format(char *line, t_instruction *instr, int i)
{
	int		shift;

	shift = 6 - (2 * (g_op_tab[i].arg_number -
				(instr->number_of_args + 1)));
	if (shift == 6)
		instr->bytes_size++;
	if (line[0] == 'r')
		instr->format |= REG_CODE << shift;
	else if (line[0] == '%')
		instr->format |= DIR_CODE << shift;
	else
		instr->format |= IND_CODE << shift;
}

static void	stock_arg_type_and_size(char *line, t_instruction *instr, int i)
{
	const int	n = (g_op_tab[i].arg_number - (instr->number_of_args + 1));
	const int	size = instr->bytes_size;

	if (line[0] == 'r')
		instr->args_type[n] = 'r';
	else if (line[0] == '%' && line[1] == ':')
	{
		instr->args_type[n] = 'l';
		instr->number_of_label_called++;
	}
	else if (line[0] == '%')
		instr->args_type[n] = 'd';
	else
		instr->args_type[n] = 'i';
	if (line[0] == 'r')
		instr->bytes_size++;
	else if (line[0] == '%' && line[1] == ':')
		instr->bytes_size += IND_SIZE;
	else if (line[0] == '%')
		instr->bytes_size += (!g_op_tab[i].byte_dir) ? DIR_SIZE : IND_SIZE;
	else
		instr->bytes_size += IND_SIZE;
	instr->args_byte_size[n] = instr->bytes_size - size;
}

static void	stock_arg_value(char *line, t_instruction *instr, int i)
{
	const int n = (g_op_tab[i].arg_number - (instr->number_of_args + 1));

	if (line[0] == 'r')
		instr->args_value[n] = ft_atoi(line + 1);
	else if (line[0] == '%' && line[1] == ':')
		return (stock_label_called_name(instr, line));
	else if (line[0] == '%')
		instr->args_value[n] = ft_atoi(line + 1);
	else
		instr->args_value[n] = ft_atoi(line);
}

void		stock_instructions(t_asm_data *data, char *line,
		t_label *current_label, int line_number)
{
	const int		i = get_op_code(line);
	t_instruction	*instr;

	instr = get_instruction(current_label, line, line_number);
	init_instruction(instr, i);
	line += ft_strlen(g_op_tab[i].name) + 1;
	while (--(instr->number_of_args) >= 0)
	{
		if (g_op_tab[i].byte_param)
			stock_format(line, instr, i);
		stock_arg_type_and_size(line, instr, i);
		stock_arg_value(line, instr, i);
		line = go_to_next_parameter(line);
	}
	data->total_size += instr->bytes_size;
	instr->number_of_args = g_op_tab[i].arg_number;
}
