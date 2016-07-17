/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 00:25:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 20:55:19 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			display_error_line(char *message, char *file, int line, int c)
{
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s ", "->");
	ft_printf("[%[[FG_GRE,SP_RST]d]", line);
	if (c > 0)
	ft_printf("~[%[[FG_CYA,SP_RST]d]", c + 1);
	if (file)
		ft_printf("%[[FG_MAG,SP_RST]s ", file);
	if (message)
		ft_printf(": %s.\n", message);
	return (0);
}
