/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_and_wait.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 22:21:58 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 07:13:51 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	dump_and_wait(t_vm_data *arena)
{
	display_field(arena);
	ft_printf("Press Enter to continue.\n");
	manage_keys(arena);
}
