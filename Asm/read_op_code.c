/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_op_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 04:26:59 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/10 16:43:13 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		read_op_code(int fd, t_instruction *instr, int *i)
{
	if (!read(fd, &instr->op_code, 1))
		return (0);
	if (instr->op_code < 1 || instr->op_code > 16)
	{
		ft_printf_fd(2, "ERROR : Invalid op_code.\n");
		exit(-1);
	}
	*i = *i - 1;
	return (1);
}
