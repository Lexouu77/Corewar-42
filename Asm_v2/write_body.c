/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:24:12 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/07 05:43:01 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_op_tab[];

static void	write_param(int fd, t_instruction *instr)
{
	int	i;

	i = -1;
	while (++i < instr->number_of_args)
	{
		if (instr->args_type[i] == 'r')
			ft_printf_fd(fd, " r");
		else if (instr->args_type[i] == 'd')
			ft_printf_fd(fd, " %%");
		else
			ft_printf_fd(fd, " ");
		ft_printf_fd(fd, "%d", instr->args_value[i]);
		if (i + 1 < instr->number_of_args)
			ft_printf_fd(fd, ",");
	}
	ft_printf_fd(fd, "\n");
}

void	write_body(int fd, t_instruction *instr)
{
	t_instruction	*p_instr;

	p_instr = instr;
	while (p_instr)
	{
		ft_printf_fd(fd, "\t %s", g_op_tab[p_instr->op_code - 1].name);
		write_param(fd, p_instr);
		p_instr = p_instr->next;
	}
}
