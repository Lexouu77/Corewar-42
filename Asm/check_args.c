/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 23:41:39 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 09:32:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_args(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!argv[i] || !ft_strlen(argv[i]) || !ft_strcmp(argv[i], "-a")
				|| was_already_called(argv, i))
			continue ;
		else if (is_a_cor_file(argv[i]))
			disassemble(argv[i]);
		else if (is_a_s_file(argv[i]))
			assemble(argv[i], argv[i - 1]);
		else
			display_error("Invalid filename", argv[i]);
	}
}
// TODO : Stock -a flag
