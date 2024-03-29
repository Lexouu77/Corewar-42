/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 00:21:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 14:56:12 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void						disassemble(char *file)
{
	int			fd;
	const int	len = ft_strlen(file);
	char		*new_file;
	char		*tmp;

	if (!is_file_valid(file))
		return ;
	if ((fd = open(file, O_RDONLY)) == -1)
		return ((void)display_error("Couldn't open the file", file));
	tmp = ft_strndup(file, len - 4);
	new_file = ft_strjoin(tmp, ".s");
	free(tmp);
	if (create_asm_file(new_file, fd))
		display_success(new_file);
	free(new_file);
}
