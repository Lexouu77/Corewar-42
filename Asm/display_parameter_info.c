/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_parameter_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 12:37:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/06 14:12:22 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define STR instruction->raw_string + k

void	display_parameter_info(t_instruction *instruction)
{
	int			i;
	char		*param;
	int			k;

	k = 0;
	i = -1;
	k += go_to_next_param(STR, 0);
	instruction->number_of_args = g_op_tab[instruction->op_code].arg_number;
	while (++i < instruction->number_of_args)
	{
		if (ft_strxlen(STR, ',') < (size_t)get_shorten_len(STR))
			param = ft_strndup(STR, ft_strxlen(STR, ','));
		else
			param = ft_strndup(STR, get_shorten_len(STR));
		if (i)
			ft_printf(" | ");
		ft_printf("Parameter : %[[BG_BLU,SP_RST]s ", param);
		display_parameter_type(param[0]);
		ft_printf("[%[[FG_RED,SP_RST]d] ", instruction->parameter_size[i]);
		ft_printf("[%#[[FG_GRE,SP_RST]x]", instruction->parameter_value[i]);
		k += go_to_next_param(STR, 0);
		free(param);
	}
	ft_printf("\n");
}
