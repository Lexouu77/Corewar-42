/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forbidden_characters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 23:30:22 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/22 01:22:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_forbidden_characters(char *s, int *i)
{
	int		j;
	int		k;
	int		error;

	j = -1;
	while (s[++j])
	{
		error = 0;
		k = -1;
		while (LABEL_CHARS[++k])
			if (s[j] == LABEL_CHARS[k])
				error = 1;
		if (s[j] == LABEL_CHAR || s[j] == DIRECT_CHAR || s[j] == SEPARATOR_CHAR
				|| ft_isspace(s[j]))
			error = 1;
		if ((s[j] == '-' || s[j] == '+') && s[j + 1] && ft_isdigit(s[j + 1]))
			error = 1;
		if (!error)
		{
			*i = j;
			return (0);
		}
	}
	return (1);
}
