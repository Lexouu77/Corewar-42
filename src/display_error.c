/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 02:56:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/13 16:53:00 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		display_error(char *message, char *filename)
{
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s", "->");
	if (filename)
		ft_printf(" %[[FG_MAG,SP_RST]s :", filename);
	ft_printf(" %s\n", message);
	return (0);
}
