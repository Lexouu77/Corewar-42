/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameter_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:51:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/22 21:22:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_parameter_size(int op_code, int var_code)
{
	if (var_code == REG_CODE)
		return (REG_SIZE);
	if (var_code == IND_CODE)
		return (IND_SIZE);
	else
		return (g_op_tab[op_code - 1].byte_dir ? DIR_SIZE : IND_SIZE);
}
