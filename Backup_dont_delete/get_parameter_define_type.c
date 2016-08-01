/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameter_define_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 17:38:11 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/21 23:10:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_parameter_define_type(char *line, int index)
{
	if (!line[index])
		return (-1);
	if (line[index] == 'r')
		return (T_REG);
	if (((line[index] == '-' || line[index] == '+') && line[index + 1] &&
			ft_isdigit(line[index + 1])) || (line[index] &&
			ft_isdigit(line[index])))
		return (T_IND);
	if (line[index] == DIRECT_CHAR || (line[index] == DIRECT_CHAR &&
				line[index + 1] && line[index + 1] == LABEL_CHAR))
		return (T_DIR);
	return (-1);
}
