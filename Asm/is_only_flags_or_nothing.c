/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_flags_or_nothing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 20:04:13 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/13 20:19:09 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_only_flags_or_nothing(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!argv[i] || !ft_strlen(argv[i]) || !ft_strcmp("-a", argv[i]))
			continue ;
		else
			return (0);
	}
	return (1);
}
