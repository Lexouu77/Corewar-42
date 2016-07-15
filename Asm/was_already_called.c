/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   was_already_called.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 23:59:34 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 00:11:01 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		was_already_called(char **argv, int i)
{
	int	j;

	j = 0;
	while (++j < i - 1)
		if (!ft_strcmp(argv[j], argv[i]))
			return (1);
	return (0);
}
