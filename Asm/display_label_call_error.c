/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_label_call_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 00:29:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/22 01:04:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			display_label_call_error(int line, char *label, char *file)
{
	char	*tmp;

	tmp = ft_strndup(label, get_shorten_len(label));
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s ", "->");
	ft_printf("[%[[FG_GRE,SP_RST]d]", line);
	if (file)
		ft_printf("%[[FG_MAG,SP_RST]s ", file);
	if (tmp)
	{
		ft_printf(": Unknown Label called [%[[FG_MAG,SP_RST]s].\n", tmp);
		free(tmp);
	}
	return (0);
}
