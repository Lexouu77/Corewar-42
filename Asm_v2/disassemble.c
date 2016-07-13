/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 08:20:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/12 06:03:03 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "time.h"

static void			write_head(int fd, t_header header)
{
	char		text[100];
	time_t		now;
	struct tm	*t;

	now = time(NULL);
	t = localtime(&now);
	strftime(text, sizeof(text) - 1, "%c", t);
	ft_printf_fd(fd, "# File generated the %s\n", text);
	ft_printf_fd(fd, "# Total size : %u bytes \n", header.prog_size);
	ft_printf_fd(fd, ".name \"%s\"\n", header.prog_name);
	ft_printf_fd(fd, ".comment \"%s\"\n\n", header.comment);
}

static int			display_error(char *message, char *file)
{
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s ", "->");
	ft_printf("%[[FG_MAG,SP_RST]s ", file);
	ft_printf(": %s\n", message);
	return (0);
}

static int			make_file(char *file, int reading_fd)
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
	write_head(writing_fd, header);
	get_body(reading_fd, &instr, header.prog_size);
	write_body(writing_fd, instr);
	return (1);
}

void				disassemble(char *file)
{
	int			fd;
	const int	len = ft_strlen(file);

	if ((fd = open(file, O_RDONLY)) == -1)
		return ((void)display_error("Couldn't open the file", file));
	file[len] = 0;
	file[len - 1] = 0;
	file[len - 2] = 0;
	file[len - 3] = 's';
	if (make_file(file, fd))
		print_success(file);
}
