/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 08:28:41 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 12:43:40 by ahamouda         ###   ########.fr       */
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
** NEXT PROCESS IS NUMBER : n = n-1 + 1 | n0 = 1;
** WHO WON THE FIGHT ?
** ARE YOU ALL ABLE TO FIGHT ?
** Number of checks before decrementing cycles_to_die
** AM I DECREMENTING ? IF YES DECREMENT THE CYCLE_TO_DIE BY CYCLE_DELTA
** ^^^^^^^ EACH CYCLE CHECK !
** CYCLES TO DUMP -> -dump
** Cycles until death aka check aka WILL YOU DIEEEEE ?
** cycles to decrement DEATH WILL OCCURS FASTER
** number of checks atm; starting at 1 for the first check
** if number of live in the current check > this -> DECREMENTING !
** number of registers
** next check at cycle number.
** number of cycle.
** number of players.
** arena mem_zone
** arena -> contains the memory and its value
** arena process -> contains the process -> who owns the memory byte ?
** ^^^^^^^^ ? ->color in the graph display / color display N0NE/P1/P2/P3/P4
** HERE WILL RESIDE NEW MEMORY (BEST QUALITY !) Displaying with bold Color
** ^^^^^^^^^^^^ Aka the "i just wrote here" thing.
** dumping bonus. stop the vm and dump the memory;
** Color bonus for dump / loop_dump / verbosity;
** GRAPHIC IS MAGIC.
** Dump each cycles_to_loop_dump then stops and go on again ..
** verbosity : 0 - show essentials
**             1 - show lives
**             2 - show cycles and cycles to die if decrementing
**             4 - show deaths. ?? a bit annoying to do tbh :(
*/

#endif
