/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 22:02:56 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 19:28:50 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			display_usage(void)
{
	ft_printf("%[[FG_YEL,SP_RST]s : ./corewar [", "Usage");
	ft_printf("%[[FG_MAG,SP_RST]s (Color Display) | ", "-c");
	ft_printf("%[[FG_RED,SP_RST]s [0-9] (Dump) | ", "-d");
	ft_printf("%[[FG_YEL,SP_RST]s [0-9] (Set Player Number) | ", "-n");
	ft_printf("%[[FG_BLU,SP_RST]s [0-9] (Loop Dump) | ", "-l");
	ft_printf("%[[FG_GRE,SP_RST]s [1|2|4|8] (Verbosity Mod) | ", "-v");
	ft_printf("%[[FG_CYA,SP_RST]s (Graphic Mod) | ", "-g");
	ft_printf("%[[FG_CYA,SP_RST]s (Create a Log File)]", "-f");
	ft_printf(" [file%[[FG_MAG,SP_RST]s] [file%[[FG_MAG,SP_RST]s] ...\n",
			".s", ".cor");
	ft_printf("Verbosity : \t - 1 : Show lives.\n");
	ft_printf("\t\t - 2 : Show cycles.\n");
	ft_printf("\t\t - 4 : Show deaths.\n");
	ft_printf("\t\t - 8 : Show instruction execution.\n");
	ft_printf("-Playing with more than four valid players will only ");
	ft_printf("use the four first valid ones as players.\n");
	ft_printf("-Playing with no valid players won't trigger the arena.\n");
	ft_printf("-Using someone who isn't tagged with the COREWAR_EXEC_MAGIC");
	ft_printf(" won't validate his participation.\n");
	ft_printf("-Dump and Loop Dump bonuses can't work together.\n");
	ft_printf("-Graphic will automatically set Color + Log File and ");
	ft_printf("unset Loop Dump + Dump.\n");
	ft_printf("-Press [SPACE] to pause the vm in Graphic mode. -/+ to set the");
	ft_printf(" time between each cycles.\n");
}
