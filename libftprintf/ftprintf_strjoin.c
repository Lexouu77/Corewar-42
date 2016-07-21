/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:25:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/06 16:44:54 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ftprintf_strjoin(t_info *list, char *s, int s2_len)
{
	char	*ns;

	ns = ft_strnew(list->nb_c_written + s2_len);
	ns = ftprintf_strncpy_cat(ns, list, s, s2_len);
	return (ns);
}
