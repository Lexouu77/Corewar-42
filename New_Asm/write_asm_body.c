/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_asm_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 01:04:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 07:06:29 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_asm_body(int fd, t_instruction *instr)
{
	t_instruction	*p_instr;

	p_instr = instr;
	while (p_instr)
	{
		ft_printf_fd(fd, "\t %s", g_op_tab[p_instr->op_code - 1].name);
		write_asm_param(fd, p_instr);
		p_instr = p_instr->next;
	}
}
