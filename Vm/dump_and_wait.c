/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_and_wait.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 22:21:58 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 02:37:01 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	dump_and_wait(t_vm_data *arena)
{
	char	c[4096];

//	if (arena->cycles == 0)
//		return ;
	display_field(arena);
	ft_printf("Press a key to continue.\n");
	read(1, &c, 4096);
}
