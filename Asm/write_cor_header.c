/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 21:46:53 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/06 13:30:20 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_cor_header(int fd, t_data *data)
{
	t_header	header;

	ft_bzero(&header, sizeof(t_header));
	header.magic = COREWAR_EXEC_MAGIC;
	byte_swap(&header.magic, 4);
	ft_strcpy((char*)&(header.prog_name), data->name);
	header.prog_size = data->total_file_size;
	byte_swap(&header.prog_size, 4);
	ft_strcpy((char*)&(header.comment), data->comment);
	write(fd, &header, sizeof(t_header));
}
