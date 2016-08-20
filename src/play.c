/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:32:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/16 18:12:16 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern int32_t core_termion(int32_t *fields, int32_t *colors);

void			play(t_vm_data *arena)
{
	set_players_in_game(arena);
	while (1) //set un moment ou stop ? if cycle_delta == 1 ?
	{
    printf("%d\n", *arena->field);
    core_termion(arena->field, arena->color_field);
		//refresh_fresh_field(arena); // do it. check throught the real corewar asm.
		arena->cycles++;
		increment_waiting_time(arena);
		check_instruction_from_proc(arena);
		execute_instruction(arena);
		if (arena->dump && arena->cycles % arena->cycles_to_dump == 0)
			dump(arena);
		if (arena->loop_dump && arena->cycles % arena->cycles_to_loop_dump == 0)
				dump_and_wait(arena);
		if (arena->cycles == arena->next_cycle_check)
			if (!is_someone_in_game(arena))
				break ;
	}
//	kill_player(arena);
}
