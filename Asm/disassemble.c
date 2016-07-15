/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 00:21:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 07:12:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void						disassemble(char *file)
{
	int			fd;
	const int	len = ft_strlen(file);
	char		*new_file;
	char		*tmp;

	if (access(file, F_OK ) == -1)
		return ((void)display_error("File not existing", file));
	if (access(file, R_OK ) == -1)
		return ((void)display_error("Missing read rights on this file", file));
	if ((fd = open(file, O_RDONLY)) == -1)
		return ((void)display_error("Couldn't open the file", file));
	tmp = ft_strndup(file, len - 2);
	new_file = ft_strjoin(tmp, ".s");
	free(tmp);
	if (create_asm_file(file, fd))
		display_success(file);
	free(new_file);
}
