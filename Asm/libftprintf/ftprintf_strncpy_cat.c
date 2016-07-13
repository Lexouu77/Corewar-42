/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_strncpy_cat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:27 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:27 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ftprintf_strncpy_cat(char *ns, t_info *list, char *s, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < list->nb_c_written)
		ns[i] = list->converted_string[i];
	j = -1;
	while (++j < len)
		ns[j + i] = s[j];
	return (ns);
}
