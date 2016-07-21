/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_parameters.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 15:06:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/21 22:48:11 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NL node->line_number
#define NS node->line
#define IDX index
#define FL file
#define EM0 "Unknown parameter type"
#define EM1 "Invalid register number"
#define EM2 "Parameter type not supported by the instruction"
#define EM3 "Parameter value is not a digit"
#define EM4 "No label called"

int		check_instruction_parameters(char *file, t_file_line *node, int index,
		int opc)
{
	int	i;
	int	type;
	int	tmp;

	i = -1;
	while (++i < MAX_ARGS_NUMBER && (index = go_to_next_param(NS, index)) != -1)
	{
		if ((type = get_parameter_define_type(NS, index)) == -1)
			return (display_error_line(EM0, FL, NL, IDX));
		if (!(type & g_op_tab[opc].args_type[i]))
			return (display_error_line(EM2, FL, NL, IDX));
		if (type == T_REG && NS[index + 1] && !ft_isdigit(NS[index + 1]))
			return (display_error_line(EM3, FL, NL, IDX + 1));
		if (type == T_DIR && NS[index + 1] && NS[index + 1] != LABEL_CHAR &&
				NS[index + 1] && !ft_isdigit(NS[index + 1]))
			return (display_error_line(EM3, FL, NL, IDX + 1));
		if (type == T_DIR && NS[index + 1] && NS[index + 1] == LABEL_CHAR &&
				NS[index + 2] && ft_isspace(NS[index + 2]))
			return (display_error_line(EM1, FL, NL, IDX + 2));
		tmp = ft_atoi(NS + IDX + 1);
		if (type == T_REG && (tmp > REG_NUMBER || tmp <= 0))
			return (display_error_line(EM1, FL, NL, IDX + 1));
	}
	return (1);
}

