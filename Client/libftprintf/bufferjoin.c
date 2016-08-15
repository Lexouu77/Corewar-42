/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:41 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			bufferjoin(t_info *list, char *str, int len)
{
	const int	len2 = (len == -1) ? ft_strlen(str) : len;

	if (!list->nb_c_written)
		list->converted_string = ftprintf_strndup(str, len2);
	else
	{
		list->tmp = list->converted_string;
		list->converted_string = ftprintf_strjoin(list, str, len2);
		free(list->tmp);
	}
	list->nb_c_written += len2;
}
