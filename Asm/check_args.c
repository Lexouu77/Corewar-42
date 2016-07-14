/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 23:41:39 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/14 23:48:00 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_args(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!argv[i] || !ft_strlen(argv[i]) || !ft_strcmp(argv[i], "-a")) // TODO : Stock -a flag
			continue ;
		if (was_already_called(argv, i))
			ft_printf("already called");
		else if (is_a_cor_file(argv[i]))
			ft_printf("Is a cor_file");
//			disassemble(argv[i]);
		else if (is_a_s_file(argv[i]))
			ft_printf("Is a s_file");
//			display_error(i, argv); //data ?
		else
//			display_success(argv[i]); // TODO : if [*].s then print [*].cor
			ft_printf("error\n");
	}
}
