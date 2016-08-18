/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uc_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:40 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			uc_to_str(t_info *list, int c)
{
	const	int	len = get_unicode_len(c);

	list->tmp_second = ft_strnew(len);
	if (c < 128)
		list->tmp_second[0] = c;
	else if (c < 2048)
	{
		list->tmp_second[0] = (char)(((c >> 6) | 0xC0) & 0xDF);
		list->tmp_second[1] = (char)((c | 0x80) & 0xBF);
	}
	else if (c < 65536)
	{
		list->tmp_second[0] = (char)(((c >> 12) | 0xE0) & 0xEF);
		list->tmp_second[1] = (char)(((c >> 6) | 0x80) & 0xBF);
		list->tmp_second[2] = (char)((c | 0x80) & 0xBF);
	}
	else
	{
		list->tmp_second[0] = (char)(((c >> 18) | 0xF0) & 0xF7);
		list->tmp_second[1] = (char)(((c >> 12) | 0x80) & 0xBF);
		list->tmp_second[2] = (char)(((c >> 6) | 0x80) & 0xBF);
		list->tmp_second[3] = (char)((c | 0x80) & 0xBF);
	}
	return (len);
}
