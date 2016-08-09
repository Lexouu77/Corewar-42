/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_asm_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 00:46:31 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/03 19:20:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			create_asm_file(char *file, int reading_fd)
{
	int				writing_fd;
	t_header		header;
	t_instruction	*instr;

	instr = NULL;
	ft_bzero(&header, sizeof(t_header));
	if (!read(reading_fd, &header, sizeof(t_header)))
		return (display_error("File is empty.", file));
	byte_swap(&header.magic, 4);
	byte_swap(&header.prog_size, 4);
	if (header.magic != COREWAR_EXEC_MAGIC)
		return (display_error("Wrong COREWAR_EXEC_MAGIC", file));
	if (!ft_strlen(header.prog_name))
		return (display_error("Missing prog_name", file));
	if (!header.prog_size)
		return (display_error("Prog_size is null", file));
	if (!ft_strlen(header.comment))
		return (display_error("Missing comment", file));
	if ((writing_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		return (display_error("Couldn't create the file", file));
	write_asm_header(writing_fd, header);
	get_asm_body(reading_fd, &instr, header.prog_size);
	write_asm_body(writing_fd, instr);
	free_list(instr);
	return (1);
}
