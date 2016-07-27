/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_end_of_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 02:53:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 04:52:18 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		go_to_end_of_label(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != LABEL_CHAR)
		i++;
	if (!s[i])
		return (0);
	i++;
	while (s[i] && ft_isspace(s[i]))
		i++;
	return (i);
}
