/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_a_label_call.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 00:29:17 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/22 00:36:12 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		has_a_label_call(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == DIRECT_CHAR && s[i + 1] && s[i + 1] == LABEL_CHAR)
			return (i + 2);
	}
	return (-1);
}
