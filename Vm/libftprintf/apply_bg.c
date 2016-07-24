/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_bg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:40 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_bg(char *s, t_info *list)
{
	if (*s == 'R' && *(s + 1) == 'E' && *(s + 2) == 'D')
		bufferjoin(list, ANSI_BG_RED, 6);
	else if (*s == 'G' && *(s + 1) == 'R' && *(s + 2) == 'E')
		bufferjoin(list, ANSI_BG_GREEN, 6);
	else if (*s == 'Y' && *(s + 1) == 'E' && *(s + 2) == 'L')
		bufferjoin(list, ANSI_BG_YELLOW, 6);
	else if (*s == 'B' && *(s + 1) == 'L' && *(s + 2) == 'U')
		bufferjoin(list, ANSI_BG_BLUE, 6);
	else if (*s == 'M' && *(s + 1) == 'A' && *(s + 2) == 'G')
		bufferjoin(list, ANSI_BG_MAGENTA, 6);
	else if (*s == 'C' && *(s + 1) == 'Y' && *(s + 2) == 'A')
		bufferjoin(list, ANSI_BG_CYAN, 6);
	else if (*s == 'W' && *(s + 1) == 'H' && *(s + 2) == 'I')
		bufferjoin(list, ANSI_BG_WHITE, 6);
	return (s + 4);
}
