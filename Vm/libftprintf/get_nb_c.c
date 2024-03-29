/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:09:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 18:11:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_nb_c(char *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			n++;
	return (n);
}
