/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_s_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 17:01:24 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/13 21:43:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			is_a_s_file(char *filename)
{
	const int	len = ft_strlen(filename);

	if (len > 2 && !ft_strcmp(filename + (len - 2), ".s"))
		return (1);
	return (0);
}
