/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 22:21:51 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 22:22:56 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	dump(t_vm_data *arena)
{
	display_field(arena);
	exit(0); // set une var dans arena pour quitter et la check dans play
}
