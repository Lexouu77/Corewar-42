/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_instruction_exist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:54:23 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 18:04:14 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		does_instruction_exist(char *s)
{
	int	i;

	i = -1;
	while (g_op_tab[++i].op_code)
		if (!ft_strcmp(s, g_op_tab[i].name))
			return (1);
	return (0);
}
