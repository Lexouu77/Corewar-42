/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:04:59 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/12 15:08:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	is_a_valid_flag(char *string)
{
	if (!ft_strcmp(string, "-c"))
		return (1);
	if (!ft_strcmp(string, "-d"))
		return (1);
	if (!ft_strcmp(string, "-l"))
		return (1);
	if (!ft_strcmp(string, "-v"))
		return (1);
	if (!ft_strcmp(string, "-g"))
		return (1);
	if (!ft_strcmp(string, "-f"))
		return (1);
	return (0);
}

static void	stock_flag(t_vm_data *arena, char *string, char *value)
{
	if (string[1] == 'f')
		arena->log_file = 1;
	if (string[1] == 'c')
		arena->color = 1;
	if (string[1] == 'g')
		arena->graph = 1;
	if (string[1] == 'l')
	{
		arena->loop_dump = 1;
		arena->dump = 0;
		if (value && ft_is_str_digit(value))
			arena->cycles_to_loop_dump = ft_atoi(value);
	}
	if (string[1] == 'd')
	{
		arena->dump = 1;
		arena->loop_dump = 0;
		if (value && ft_is_str_digit(value))
			arena->cycles_to_dump = ft_atoi(value);
	}
	if (string[1] == 'v')
		if (value && ft_is_str_digit(value))
			arena->verbosity = ft_atoi(value);
}

void		parse_flag(int argc, char **argv, t_vm_data *arena)
{
	int		i;

	i = 0;
	while (++i < argc)
		if (argv[i] && is_a_valid_flag(argv[i]))
			stock_flag(arena, argv[i], argv[i + 1]);
	if (arena->graph)
	{
		arena->color = 1;
		arena->log_file = 1;
		arena->dump = 0;
		arena->loop_dump = 0;
	}
	if (arena->loop_dump && !arena->cycles_to_loop_dump)
		arena->loop_dump = 0;
	if (arena->dump && !arena->cycles_to_dump)
		arena->dump = 0;
}
