/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sign_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 00:08:54 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/22 01:22:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_sign_error(char *s, int *i)
{
	int		j;
	int		error;

	j = -1;
	while (s[++j])
	{
		error = 0;
		if ((s[j] == '-' || s[j] == '+') && s[j + 1] && !ft_isdigit(s[j + 1]))
		{
			error = 1;
			j++;
		}
		if (error)
		{
			*i = j;
			return (0);
		}
	}
	return (1);
}
