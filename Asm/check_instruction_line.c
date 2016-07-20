/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:23:44 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 18:03:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NL node->line_number
#define NSTRING node->line + index

int			check_instruction_line(char *file, t_data *data, t_file_line *node,
		int index)
{
	char	*instruction;
//	int		number_of_args; // faire un get nb_args;

	if (ft_is_str_blank(node->line + index))
		return (display_error_line("Missing instruction", file, NL, -1));
	instruction = ft_strndup(NSTRING, get_shorten_len(NSTRING));
	if (!does_instruction_exist(instruction))
		return (display_instruction_error(NL, file, index, instruction));
	(void)data;
	(void)file;
	ft_printf("[%s]\n", node->line + index);
	free(instruction);
	return (1);
}
