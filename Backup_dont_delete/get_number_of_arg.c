/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:38:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 19:45:29 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_number_of_arg(char *s)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i] && (ft_isspace(s[i]) || s[i] == SEPARATOR_CHAR))
		i++;
	while (s[i])
	{
		if (s[i] && (!ft_isspace(s[i]) && s[i] != SEPARATOR_CHAR))
			n++;
		while (s[i] && (!ft_isspace(s[i]) && s[i] != SEPARATOR_CHAR))
			i++;
		while (s[i] && (ft_isspace(s[i]) || s[i] == SEPARATOR_CHAR))
			i++;
	}
	return (n);
}
