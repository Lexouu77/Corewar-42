/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_cor_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:12:49 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/17 14:15:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_a_cor_file(char *filename)
{
	const int	l = ft_strlen(filename);

	if (ft_strlen(filename) > 4 && !ft_strcmp(filename + l - 4, ".cor"))
		return (1);
	return (0);
}
