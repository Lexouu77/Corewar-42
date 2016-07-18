/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_label.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 17:28:18 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/18 18:37:03 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_instruction_label(char *s)
{
	int	i;

	i = 0;
	if (s[0] && s[0] == LABEL_CHAR)
		return (1);
	while (s[++i])
		if (s[i] == LABEL_CHAR && s[i - 1] != DIRECT_CHAR)
			return (1);
	return (0);
}
