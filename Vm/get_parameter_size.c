/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameter_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:51:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 21:16:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_parameter_size(int op_code, int var_code)
{
	if (var_code == REG_CODE)
		return (1);
	if (var_code == IND_CODE)
		return (IND_SIZE);
	else if (var_code == DIR_CODE)
		return (!g_op_tab[op_code - 1].byte_dir ? DIR_SIZE : IND_SIZE);
	return (0);
}
