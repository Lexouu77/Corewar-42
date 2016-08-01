/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_parameter_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 12:48:18 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 12:50:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	display_parameter_type(char c)
{
	if (c == 'r')
		ft_printf("[%[[FG_MAG,SP_RST]s] ", "Register");
	else if (c == '%')
		ft_printf("[%[[FG_MAG,SP_RST]s] ", "Direct");
	else
		ft_printf("[%[[FG_MAG,SP_RST]s] ", "Indirect");
}
