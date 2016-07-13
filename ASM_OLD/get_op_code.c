/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:02:34 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/17 17:03:17 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_op_tab[];

int			get_op_code(char *line)
{
	int	i;

	i = -1;
	while (g_op_tab[++i].name)
		if (!ft_strncmp(line, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)) &&
				line[ft_strlen(g_op_tab[i].name)] == ' ')
			break ;
	return (i);
}
