/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_asm_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 00:45:54 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 00:54:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_asm_header(int fd, t_header header)
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
