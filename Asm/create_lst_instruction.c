/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 00:07:57 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/06 08:26:02 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Function which create a new t_instruction node.
** Take line of the .s file in parameter with it line number.
** Set the byte_size of the instruction to 1 since we need 1byte for the opcode.
*/

t_instruction		*create_lst_instruction(char *line, int line_number)
{
	t_instruction	*list;

	list = (t_instruction *)ft_memalloc(sizeof(t_instruction));
	if (line)
		list->raw_string = ft_strdup(line);
	list->size = 1;
	list->line_number = line_number;
	return (list);
}
