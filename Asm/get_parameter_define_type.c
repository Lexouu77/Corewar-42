/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameter_define_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 17:38:11 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/21 22:46:23 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_parameter_define_type(char *line, int index)
{
	ft_printf("%[[BG_BLU,SP_RST]s\n", line + index);
	if (!line[index])
		return (-1);
	if (line[index] == 'r')
		return (T_REG);
	if (ft_isdigit(line[index]))
		return (T_IND);
	if (line[index] == DIRECT_CHAR || (line[index] == DIRECT_CHAR &&
				line[index + 1] && line[index + 1] == LABEL_CHAR))
		return (T_DIR);
	return (-1);
}
