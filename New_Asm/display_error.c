/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 00:25:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 07:06:19 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			display_error(char *message, char *file)
{
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s ", "->");
	if (file)
		ft_printf("%[[FG_MAG,SP_RST]s ", file);
	if (message)
		ft_printf(": %s.\n", message);
	return (0);
}
