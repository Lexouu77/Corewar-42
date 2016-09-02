/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_param_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 11:30:09 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/01 21:22:16 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_n_param_size(t_vm_data *arena, int n)
{
	if ((g_op_tab[arena->op_code - 1].args_type[n - 1] & T_REG) == T_REG)
		return (1);
	if ((g_op_tab[arena->op_code - 1].args_type[n - 1] & T_IND) == T_IND)
		return (IND_SIZE);
	return (!g_op_tab[arena->op_code - 1].byte_dir ? DIR_SIZE : IND_SIZE);
}
