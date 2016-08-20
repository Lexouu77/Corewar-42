/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 21:57:10 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 22:23:35 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_vm_data	*init_data(void)
{
	t_vm_data *arena;

	arena = ft_memalloc(sizeof(t_vm_data));
	arena->mem_size = MEM_SIZE * sizeof(int);
	arena->field = ft_memalloc(arena->mem_size);
	arena->process_field = ft_memalloc(arena->mem_size);
	arena->fresh_field = ft_memalloc(arena->mem_size);
	arena->color_field = ft_memalloc(arena->mem_size);
  arena->mem_size = MEM_SIZE;
	arena->next_cycle_check = CYCLE_TO_DIE;
	arena->cycles_to_die = CYCLE_TO_DIE;
	arena->cycle_delta = CYCLE_DELTA;
	arena->number_of_checks++;
	arena->process_next_number++;
	return (arena);
}
