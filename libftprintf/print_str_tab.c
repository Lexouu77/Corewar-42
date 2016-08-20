/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:37 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:37 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_str_tab(va_list *va, t_info *list)
{
	char	**s;
	int		len;

	s = va_arg(*va, char**);
	len = va_arg(*va, int);
	while (len)
	{
		if (*s)
			list->tmp_third = ft_strdup(*s);
		else
			list->tmp_third = ft_strdup("(null)");
		bufferjoin(list, list->tmp_third, ft_strlen(list->tmp_third));
		free(list->tmp_third);
		++s;
		if (--len)
			bufferujoin(list, '\n');
	}
}
