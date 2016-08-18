/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_spe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:41 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*apply_special(char *s, t_flags *flag, t_info *list)
{
	if (*s == 'B' && *(s + 1) == 'O' && *(s + 2) == 'L')
		bufferjoin(list, ANSI_BOLD, 5);
	else if (*s == 'U' && *(s + 1) == 'N' && *(s + 2) == 'D')
		bufferjoin(list, ANSI_UNDERLIGNED, 5);
	else if (*s == 'R' && *(s + 1) == 'E' && *(s + 2) == 'V')
		bufferjoin(list, ANSI_REVERSE_COLOR, 5);
	else if (!flag->reset_ansi &&
			*s == 'R' && *(s + 1) == 'S' && *(s + 2) == 'T')
		flag->reset_ansi = 1;
	else if (!flag->reset_fg &&
			*s == 'F' && *(s + 1) == 'G' && *(s + 2) == 'R')
		flag->reset_fg = 1;
	else if (!flag->reset_bg &&
			*s == 'B' && *(s + 1) == 'G' && *(s + 2) == 'R')
		flag->reset_bg = 1;
	return (s + 4);
}

void			apply_spe_after(t_flags *flag, t_info *list)
{
	if (flag->reset_ansi)
		bufferjoin(list, ANSI_RESET, 5);
	if (flag->reset_fg)
		bufferjoin(list, ANSI_FG_STANDART, 6);
	if (flag->reset_bg)
		bufferjoin(list, ANSI_BG_STANDART, 6);
}
