/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_format_byte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 09:18:22 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 11:54:55 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	stock_format_byte(t_instruction *instruction, char *s, int shift)
{
	if (shift == 6)
		instruction->size++;
	if (s[0] == 'r')
		instruction->format |= REG_CODE << shift;
	else if (s[0] == DIRECT_CHAR)
		instruction->format |= DIR_CODE << shift;
	else
		instruction->format |= IND_CODE << shift;
}
