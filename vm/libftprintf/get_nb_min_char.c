/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_min_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:29 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:29 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	add_precision(t_flags *flag, int *len, char *str)
{
	flag->is_precision_here = 1;
	if (str[0] != 48 && str[1])
	{
		++flag->nb_max_char;
		++*len;
	}
	else if (str[0] != 48)
	{
		--flag->nb_max_char;
		--*len;
	}
}

void			get_nb_min_char(t_flags *flag, char *str)
{
	int	len;
	int	len2;

	len2 = ft_strlen(str);
	len = ((flag->plus || flag->space) && (flag->type == 'D' ||
				flag->type == 'd' || flag->type == 'i')) ? 1 : 0;
	if ((flag->type == 'o' || flag->type == 'O') && flag->hash)
		add_precision(flag, &len, str);
	len += ((flag->type == 'x' || flag->type == 'X') && flag->hash &&
			str[0] != 48) ? 2 : 0;
	if (flag->is_precision_here)
	{
		if (str[0] == 48 && len2 == 1)
			len2 = 0;
		flag->zero = 0;
		if (flag->nb_max_char > flag->nb_min_char)
			flag->nb_min_char = 0;
		else
			flag->nb_min_char -= (len2 >= flag->nb_max_char) ? (len2 + len) :
				(flag->nb_max_char + len);
		flag->nb_max_char -= (flag->nb_max_char > len2) ? len2 :
			flag->nb_max_char;
	}
	else
		flag->nb_min_char -= (len2 + len);
}
