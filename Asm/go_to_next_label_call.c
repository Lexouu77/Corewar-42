/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_next_label_call.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 00:41:39 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 02:10:19 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	go_to_next_label_call(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == DIRECT_CHAR && s[i + 1] && s[i + 1] == LABEL_CHAR)
			return (i + 2);
		i++;
	}
	return (-1);
}
