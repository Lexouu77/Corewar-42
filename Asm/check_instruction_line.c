/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:23:44 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/22 00:18:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NL node->line_number
#define NSTRING node->line + index
#define N_ARG "Incorrect number of parameters"
#define NO_ARG "No parameters used"
#define N_A number_of_args
#define D_ERR(arg) display_error_line(arg, file, NL, -1)

int			check_instruction_line(char *file, t_data *data, t_file_line *node,
			int index)
{
	char			*instruction;
	int				number_of_args;
	int				i;
	int				len;

	data->has_instructions = 1;
	if (ft_is_str_space(node->line + index))
		return (display_error_line("Missing instruction", file, NL, -1));
	len = get_shorten_len(NSTRING);
	instruction = ft_strndup(NSTRING, len);
	if ((i = does_instruction_exist(instruction)) == -1)
		return (display_instruction_error(NL, file, index, instruction));
	free(instruction);
	number_of_args = get_number_of_arg(NSTRING + len);
	if (number_of_args != g_op_tab[i].arg_number)
		return (!N_A ? D_ERR(NO_ARG) : D_ERR(N_ARG));
	return (check_instruction_parameters(file, node, index + len, i));
}
