/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_label_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:32:44 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 16:48:07 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			display_label_error(int line, char *label, char *file, int er_line)
{
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s ", "->");
	ft_printf("[%[[FG_GRE,SP_RST]d]", line);
	if (file)
		ft_printf("%[[FG_MAG,SP_RST]s ", file);
	ft_printf(": Label [%[[FG_MAG,SP_RST]s]", label);
	if (label)
		free(label);
	ft_printf(" already declared at line [%[[FG_CYA,SP_RST]d].\n", er_line);
	return (0);
}
