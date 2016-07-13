/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:04:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/04 22:15:59 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_op_tab[];

static char		*len_to_next_arg(char *line, char *param)
{
	line += ft_strlen(param);
	while (*line && (*line == 32 || *line == ','))
		line++;
	return (line);
}

static void		display_param_type(char *param)
{
	if (param[0] == 'r')
		ft_printf("[%[[FG_MAG,SP_RST]s] ", "Register");
	else if (param[0] == '%')
		ft_printf("[%[[FG_MAG,SP_RST]s] ", "Direct");
	else
		ft_printf("[%[[FG_MAG,SP_RST]s] ", "Indirect");
}

static void		display_param_info(t_instruction *instr)
{
	char		*line;
	int			i;
	char		*param;

	i = -1;
	line = ft_strdup(instr->raw_string +
			ft_strlen(g_op_tab[instr->op_code - 1].name) + 1);
	while (++i < instr->number_of_args)
	{
		if (ft_strxlen(line, ',') < ft_strxlen(line, 32))
			param = ft_strndup(line, ft_strxlen(line, ','));
		else
			param = ft_strndup(line, ft_strxlen(line, 32));
		if (i)
			ft_printf(" | ");
		ft_printf("Parameter : %[[BG_BLU,SP_RST]s ", param);
		display_param_type(param);
		ft_printf("[%[[FG_RED,SP_RST]d] ", instr->args_byte_size[i]);
		ft_printf("[%#[[FG_GRE,SP_RST]x]", instr->args_value[i]);
		line = len_to_next_arg(line, param);
	}
	ft_printf("\n");
	free(param);
}

static void		display_line(t_instruction *instr, int *total_size)
{
	ft_printf("[%[[FG_GRE,SP_RST]d] : %[[FG_RED,SP_RST]s\n",
				instr->line_number, instr->raw_string);
	ft_printf("op_code : [%#[[FG_YEL,SP_RST]x] | ", instr->op_code);
	if (instr->format)
		ft_printf("format : %#[[FG_MAG,SP_RST]x | ",
				instr->format);
	else
		ft_printf("%[[FG_CYA,SP_RST]s ! | ", "No format byte");
	ft_printf("Size : [%[[FG_RED,SP_RST]d] Bytes | ",
			instr->bytes_size);
	*total_size += instr->bytes_size;
	ft_printf("Total size : [%[[FG_YEL,SP_RST]d] bytes\n", *total_size);
}

void			display_info(t_asm_data *data)
{
	t_label			*label;
	t_instruction	*instr;
	int				total_size;

	total_size = 0;
	label = data->labels;
	while (label)
	{
		instr = label->instructions;
		while (instr)
		{
			display_line(instr, &total_size);
			display_param_info(instr);
			instr = instr->next;
		}
		label = label->next;
	}
}
