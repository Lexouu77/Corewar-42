/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ansi_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:56:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/28 11:41:15 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_ansi_code(t_flags *flag, char *str, t_info *list)
{
	str += 3;
	while (*(str - 1) != ']' && *str && *(str + 1) && *(str + 2) && *(str + 3)
			&& *(str + 4))
	{
		if (*(str - 2) == 'F' && *(str - 1) == 'G')
			str = apply_fg(str + 1, list);
		else if (*(str - 2) == 'B' && *(str - 1) == 'G')
			str = apply_bg(str + 1, list);
		else if (*(str - 2) == 'S' && *(str - 1) == 'P')
			str = apply_special(str + 1, flag, list);
		else
			++str;
	}
	return (str);
}
