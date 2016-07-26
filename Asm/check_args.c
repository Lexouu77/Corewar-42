/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 23:41:39 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/26 07:01:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_args(int argc, char **argv)
{
	int		i;
	t_data	*data;

	i = 0;
	data = ft_memalloc(sizeof(t_data));
	while (++i < argc)
	{
		if (!argv[i] || !ft_strlen(argv[i]) || !ft_strcmp(argv[i], "-a")
				|| was_already_called(argv, i))
			continue ;
		if (argv[i - 1] && !ft_strcmp(argv[i - 1], "-a"))
			data->display_byte_info = 1;
		if (is_a_cor_file(argv[i]))
			disassemble(argv[i]);
		else if (is_a_s_file(argv[i]))
			assemble(argv[i], data);
		else
			display_error("Invalid filename", argv[i]);
		reset_data_struct(data);
	}
	free(data);
}
