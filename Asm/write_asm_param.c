/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_asm_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 06:48:29 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 10:27:20 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_asm_param(int fd, t_instruction *instr)
{
	int	i;

	i = -1;
	while (++i < instr->number_of_args)
	{
		if (instr->parameter_type[i] == 'r')
			ft_printf_fd(fd, " r");
		else if (instr->parameter_type[i] == 'd')
			ft_printf_fd(fd, " %%");
		else
			ft_printf_fd(fd, " ");
		ft_printf_fd(fd, "%d", instr->parameter_value[i]);
		if (i + 1 < instr->number_of_args)
			ft_printf_fd(fd, ",");
	}
	ft_printf_fd(fd, "\n");
}
