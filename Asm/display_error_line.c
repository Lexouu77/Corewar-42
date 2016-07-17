/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 00:25:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 18:17:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			display_error_line(char *message, char *file, int line)
{
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s ", "->");
	ft_printf("[%[[FG_GRE,SP_RST]d]", line);
	if (file)
		ft_printf("%[[FG_MAG,SP_RST]s ", file);
	if (message)
		ft_printf(": %s.\n", message);
	return (0);
}
