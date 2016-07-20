/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_s_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 17:01:24 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/14 20:00:56 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_a_s_file(char *filename)
{
	const int	len = ft_strlen(filename);

	const char *ss = malloc(42);
	(void)ss;
	if (len > 2 && !ft_strcmp(filename + (len - 2), ".s"))
		return (1);
	return (0);
}
