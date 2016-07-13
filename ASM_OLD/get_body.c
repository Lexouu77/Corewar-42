/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 15:44:19 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/09 02:06:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_op_tab[];

static int		read_op_code(int fd, t_instruction *instr, int *i)
{
	if (!read(fd, &instr->op_code, 1))
		return (0);
	*i = *i - 1;
	return (1);
}

/*
** 128 64 32 16 8 4 2 1
*/

static void		stock_param_types(t_instruction *instr)
{
	int	i;
	int	shift;

	i = -1;
	if (instr->number_of_args < 0 || instr->number_of_args > 5)
		return ;
	while (++i < instr->number_of_args)
	{
		shift = 6 - 2 * i;
		if (((instr->format >> shift) & 0x3) == REG_CODE)
			instr->args_type[i] = 'r';
		if (((instr->format >> shift) & 0x3) == IND_CODE)
			instr->args_type[i] = 'i';
		if (((instr->format >> shift) & 0x3) == DIR_CODE)
			instr->args_type[i] = 'd';
		if (instr->args_type[i] == 'r')
			instr->args_byte_size[i] = 1;
		if (instr->args_type[i] == 'i')
			instr->args_byte_size[i] = IND_SIZE;
		if (instr->args_type[i] == 'd')
			instr->args_byte_size[i] =
				(g_op_tab[instr->op_code - 1].byte_dir) ? IND_SIZE : DIR_SIZE;
		instr->bytes_size += instr->args_byte_size[i];
	}
}

static int		stock_fixed_param_types(int fd, t_instruction *instr, int *i)
{
	short	x;

	x = 0;
	if (g_op_tab[instr->op_code - 1].byte_param)
		return(1);
	if (!(instr->args_type = (char*)malloc(sizeof(char)
			* instr->number_of_args)) || !(instr->args_value =
				(int*)malloc(sizeof(int) * instr->number_of_args)) ||
				!(instr->args_byte_size =
			(int*)malloc(sizeof(int) * instr->number_of_args)))
		ft_malloc_error();
	instr->args_type[0] = 'd';
	instr->args_byte_size[0] =
		(g_op_tab[instr->op_code - 1].byte_dir) ? IND_SIZE : DIR_SIZE;
	if (!read(fd, &instr->args_value[0], instr->args_byte_size[0]))
			return (0);
	byte_swap(&instr->args_value[0], instr->args_byte_size[0]);
	if (instr->args_byte_size[0] == 2)
	{
			instr->args_value[0] &= 0x0000FFFF;
		/*if (instr->args_value[0] > 32767 || instr->args_value[0] < -32767)
		{
			x = instr->args_value[0]; // a add seulement dans la vm
			instr->args_value[0] = x; // ^ 
		}*/
	}
	instr->bytes_size += instr->args_byte_size[0];
	*i = *i - instr->args_byte_size[0];
	instr->number_of_args = g_op_tab[instr->op_code - 1].arg_number;
	return (1);
}

static int		read_format(int fd, t_instruction *instr, int *i)
{
	int	j;

	if (!g_op_tab[instr->op_code - 1].byte_param)
		return(1);
	j =-1;
	if (!read(fd, &instr->format, 1))
		return (0);
	*i = *i - 1;
	instr->number_of_args = g_op_tab[instr->op_code - 1].arg_number;
	if (!(instr->args_type = (char*)malloc(sizeof(char)
			* instr->number_of_args)) || !(instr->args_value =
				(int*)malloc(sizeof(int) * instr->number_of_args)) ||
				!(instr->args_byte_size =
			(int*)malloc(sizeof(int) * instr->number_of_args)))
		ft_malloc_error();
	stock_param_types(instr);
	while (++j < instr->number_of_args)
		*i -= instr->args_byte_size[j];
	return (1);
}

static int		read_param_value(int fd, t_instruction *instr)
{
	int			i;
	//short		x;

	i = -1;
	if (!g_op_tab[instr->op_code - 1].byte_param)
		return (1);
	while (++i < instr->number_of_args)
	{
		if (!read(fd, &instr->args_value[i], instr->args_byte_size[i]))
			return (0);
		byte_swap(&instr->args_value[i], instr->args_byte_size[i]);
		if (instr->args_byte_size[i] == 2)
		{
			instr->args_value[i] &= 0x0000FFFF;
			/*if (instr->args_value[i] > 32767 || instr->args_value[i] < -32767)
			{
				x = instr->args_value[i];
				instr->args_value[i] = x;
			}*/
		}
	}
	return (1);
}

void			get_body(int fd, t_instruction **instruction, unsigned int size)
{
	int				i;
	t_instruction	*instr;
	t_instruction	*tmp;

	i = size;
	instr = create_lst_instruction(NULL, i);
	*instruction = instr;
	while (i > 0)
	{
		if (!read_op_code(fd, instr, &i))
			break ;
		if (!read_format(fd, instr, &i))
			break ;
		if (!stock_fixed_param_types(fd, instr, &i))
			break ;
		if (!read_param_value(fd, instr))
			break ;
		instr->next = create_lst_instruction(NULL, i);
		tmp = instr;
		instr = instr->next;
	}
	if (instr->op_code <  1 || instr->op_code > 16 || instr->number_of_args)
	{
		free(instr);
		tmp->next = NULL;
	}
}
