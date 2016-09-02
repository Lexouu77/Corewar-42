/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 04:07:37 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 22:35:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			get_param_type(t_vm_data *arena, int param_number)
{
	return ((arena->format >> (6 - 2 * (param_number - 1))) & 3);
}
