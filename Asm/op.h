/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 05:11:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/21 15:01:07 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define IND_SIZE 2
# define REG_SIZE 4
# define DIR_SIZE REG_SIZE

# define REG_CODE 1
# define DIR_CODE 2
# define IND_CODE 3

# define MAX_ARGS_NUMBER 4 // check les defines | check MAX_ARGS_NUMBER avec arg_number de g_op_tab
# define MAX_PLAYERS 4
# define MEM_SIZE (4*1024)
# define IDX_MOD (MEM_SIZE / 8)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR ','

# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"

# define REG_NUMBER 16

# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 50
# define NBR_LIVE 21
# define MAX_CHECKS 10

typedef char		t_arg_type;

# define T_REG 1
# define T_DIR 2
# define T_IND 4
# define T_LAB 8

# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct		s_header
{
	unsigned	int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned	int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_op
{
	char			*name;
	int				arg_number;
	int				args_type[MAX_ARGS_NUMBER];
	unsigned	int	op_code;
	int				cycles_to_process;
	char			*description;
	int				byte_param;
	int				byte_dir;
}					t_op;

/*
** t_op
** Name ?
** Number of args.
** Type of args accepted.
** op_code.
** number of cycles to before realisation of the instruction.
** Description lel.
** Do i need a byte to define the format of the args after the opcode ?
** DIRECT Args on : 4 bytes if 0 else, 2 bytes.
*/
#endif
