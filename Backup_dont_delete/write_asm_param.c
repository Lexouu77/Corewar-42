/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_asm_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 06:48:29 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 07:02:35 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_asm_param(int fd, t_instruction *instr)
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
