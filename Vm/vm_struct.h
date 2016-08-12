/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 08:28:41 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/12 16:55:49 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCT_H
# define VM_STRUCT_H

typedef struct		s_instr
{
	char			op_code;
	unsigned char			format;
	int				number_of_args;
	int				fd;
	int				i;
}					t_instr;

typedef struct		s_proc
{
	int				*reg;
	int				number;
	int				owner;
	int				pc;
	int				carry;
	int				lives;
	int				is_waiting;
	int				cycles_waiting;
	int				cycles_to_wait;
	struct s_player	*father;
	struct s_proc	*prev;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_player
{
	int				still_in_game;
	int				alive;
	int				validity;
	char			*filename;
	int				number_of_player;
	int				bytes_size;
	int				number_of_process;
	char			*name;
	char			*comment;
	int				cycle_of_last_live;
	int				period_live_number;
	int				to_kill;
	struct s_proc	*process;
	struct s_proc	*last_process;
	struct s_player	*next;
	struct s_player	*prev;
}					t_player;

typedef struct		s_vm_data
{
	int				process_next_number;
	int				winner;
	int				number_of_valid_player;
	int				max_checks;
	int				decrementing;
	int				cycles_to_dump;
	int				cycles_to_loop_dump;
	int				cycles_to_die;
 	int				cycle_delta;
	int				number_of_checks;
	int				nbr_live;
	int				period_live_number;
	int				number_of_reg;
	int				next_cycle_check;
	int				cycles;
	int				number_of_players;
	int				mem_size;
	int				log_file;
	int				fd;
	int				dump;
	int				color;
	int				graph;
	int				loop_dump;
	int				verbosity;
	int				pause;
	int				*color_field;
	int				*field;
	int				*process_field; // use proc->pc to get it.
	int				*fresh_field;
	int				*tmp_args_value;
	struct s_player *last_player;
	struct s_player	*players;
}					t_vm_data;

/*
** Next process number
** Winner
** Number of players able to play.
** MAX_CHECKS
** Am i decrementing ?
** CYCLE_TO_DUMP
** CYCLE_TO_DUMP with loop -> -l bonus
** CYCLE_TO_DIE
** CYCLE_DELTA
** Number of check done
** NBR_LIVE
** Number of lives done throught the period
** REG_NUMBER
** Number of the next cycle check
** Number of the actual cycle.
** Number of players
** MEM_SIZE
** -f bonus, create a Corewar.log file
** fd to write
** -d bonus dump the field then exit
** to delete
** -g TODO :
** -l bonus dump each cycles_to_loop_dump without exiting
** -v bonus display some usefull information
** pause -> graphic mode.
** Array which contains the owner of the tile needed to display the color in
** ^^^^ graphic mode
** Array which contains the memory and its value
** Array which contains the process location
** Array which contains the location of last cycle written data
** temp
** Linked list on the last player since we're starting from the last
** ^^^ in the instructions execution
** Linked list with all players, starting from the first
*/

#endif
