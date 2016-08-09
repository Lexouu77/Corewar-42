/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:52:52 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/13 20:08:18 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				display_usage(void)
{
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s : ", "USAGE");
	ft_printf("./asm %[[FG_GRE,SP_RST]s (Detailled info) ", "-a");
	ft_printf("[file%[[FG_RED,SP_RST]s] ", ".s");
	ft_printf("[file%[[FG_RED,SP_RST]s] ...\n", ".cor");
	exit(-1);
}
