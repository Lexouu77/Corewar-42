/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_param_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 10:09:06 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 12:56:42 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	stock_param_value(t_instruction *instruction, char *s, int shift)
{
	const int	index = ((6 - shift) / 2);

	if (*s && *s == 'r')
		instruction->parameter_value[index] = ft_atoi(s + 1);
	else if (*s && s[1] && *s == DIRECT_CHAR && s[1] == LABEL_CHAR)
		return (stock_label_called_name(instruction, s + 2));
	else if (*s && *s == DIRECT_CHAR)
		instruction->parameter_value[index] = ft_atoi(s + 1);
	else
		instruction->parameter_value[index] = ft_atoi(s);
}
