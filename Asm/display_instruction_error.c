/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_instruction_error.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:47:06 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 19:48:45 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			display_instruction_error(int line, char *file, int c,
		char *instruction)
{
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s ", "->");
	ft_printf("[%[[FG_GRE,SP_RST]d]", line);
	if (c + 1 > 0)
		ft_printf("~[%[[FG_CYA,SP_RST]d]", c + 1);
	if (file)
		ft_printf("%[[FG_MAG,SP_RST]s ", file);
	ft_printf(": Unknown instruction [%[[FG_MAG,SP_RST]s].\n", instruction);
	if (instruction)
		free(instruction);
	return (0);
}
