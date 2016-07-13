/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 06:34:50 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/04 22:12:33 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_op_tab[];

static void		write_header(t_asm_data *data, int fd)
{
	t_header	header;

	ft_bzero(&header, sizeof(t_header));
	header.magic = COREWAR_EXEC_MAGIC;
	byte_swap(&header.magic, 4);
	ft_strcpy((char*)&(header.prog_name), data->name);
	header.prog_size = data->total_size;
	byte_swap(&header.prog_size, 4);
	ft_strcpy((char*)&(header.comment), data->comment);
	write(fd, &header, sizeof(t_header));
}

static void		swap_and_write(t_instruction *instr, int fd)
{
	int		i;

	i = -1;
	write(fd, &(instr->op_code), sizeof(instr->op_code));
	if (g_op_tab[instr->op_code - 1].byte_param)
		write(fd, &(instr->format), sizeof(instr->format));
	while (++i < instr->number_of_args)
	{
		byte_swap(&(instr->args_value[i]), instr->args_byte_size[i]);
		write(fd, &(instr->args_value[i]), instr->args_byte_size[i]);
	}
}

static void		write_instructions(t_asm_data *data, int fd)
{
	t_label			*label;
	t_instruction	*instr;

	label = data->labels;
	while (label)
	{
		instr = label->instructions;
		while (instr)
		{
			swap_and_write(instr, fd);
			instr = instr->next;
		}
		label = label->next;
	}
}

int				create_file(char *file, t_asm_data *data)
{
	int	fd;

	//if (check_unknown_label_call(data) || check_param(data) || check_reg_value(data) //TODO 
		//return (0);
	get_distance_to_label(data);
	if (data->display_byte_info)
		display_info(data);
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		data->error = CANT_CREATE;
		return (0);
	}
	write_header(data, fd);
	write_instructions(data, fd);
	free(file);
	close(fd);
	return (1);
}
