/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_next_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 21:00:58 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/06 14:12:24 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		go_to_next_param(char *s, int index)
{
	if (!s[index])
		return (-1);
	if (ft_isspace(s[index]))
	{
		while (s[index] && ft_isspace(s[index]))
			index++;
	}
	else
	{
		while (s[index] && !ft_isspace(s[index]))
			index++;
		while (s[index] && ft_isspace(s[index]))
			index++;
	}
	if (!s[index])
		return (-1);
	return (index);
}
