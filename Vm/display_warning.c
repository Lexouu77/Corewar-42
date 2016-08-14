/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_warning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 21:50:28 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/13 21:50:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		display_warning(char *message, char *filename)
{
	ft_printf("%[[FG_RED,SP_RST]s ", "WARNING");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s", "->");
	if (filename)
		ft_printf(" %[[FG_MAG,SP_RST]s :", filename);
	ft_printf(" %s\n", message);
	return (0);
}
