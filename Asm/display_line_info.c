/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_line_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 12:02:23 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 12:09:19 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		display_line_info(t_instruction *instruction, int *size)
{
	ft_printf("[%[[FG_GRE,SP_RST]d] : %[[FG_RED,SP_RST]s\n",
						instruction->line_number, instruction->raw_string);
	ft_printf("op_code : [%#[[FG_YEL,SP_RST]x] | ", instruction->op_code + 1);
		if (instruction->format)
			ft_printf("format : %#[[FG_MAG,SP_RST]x | ", instruction->format);
		else
			ft_printf("%[[FG_CYA,SP_RST]s ! | ", "No format byte");
		ft_printf("Size : [%[[FG_RED,SP_RST]d] Bytes | ", instruction->size);
		*size += instruction->size;
		ft_printf("Total size : [%[[FG_YEL,SP_RST]d] bytes\n", *size);

}
