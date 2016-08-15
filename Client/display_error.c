/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 02:56:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 19:28:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		display_error(char *message, char *filename)
{
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s", "->");
	if (filename)
		ft_printf(" %[[FG_MAG,SP_RST]s :", filename);
	ft_printf(" %s\n", message);
	return (0);
}
