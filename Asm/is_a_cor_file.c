/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_cor_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 16:45:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/14 17:06:04 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_a_cor_file(char *filename)
{
	const int	len = ft_strlen(filename);

	if (len > 3 && !ft_strcmp(filename + (len - 4), ".cor"))
		return (1);
	return (0);
}
