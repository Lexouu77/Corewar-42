/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_players_and_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:17:06 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/12 16:20:26 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	is_a_flag(char *s, int *i, char *next, int argc)
{
	if (!ft_strcmp(s, "-n") || !ft_strcmp(s, "-d") || !ft_strcmp(s, "-l") ||
			!ft_strcmp(s, "-c") || !ft_strcmp(s, "-v") || !ft_strcmp(s, "-g")
			|| !ft_strcmp(s, "-f"))
	{
		if ((!ft_strcmp(s, "-d") || !ft_strcmp(s, "-l") || !ft_strcmp(s, "-v"))
				&& *i < argc && next && ft_is_str_digit(next))
				*i = *i + 1;
		return (1);
	}
	return (0);
}

/*
** Get the desired number of the player and stock his filename in a new node.
** Add a new node for each file.
*/

void		stock_players_and_number(char **argv, t_vm_data *arena, int argc)
{
	int	i;
	int	number;

	i = 0;
	while (++i < argc)
	{
		number = -1;
		if (!argv[i] || !ft_strlen(argv[i]) || (argv[i + 1] &&
				is_a_flag(argv[i], &i, argv[i + 1], argc)))
			continue ;
		if (!ft_strcmp(argv[i - 1], "-n") && ft_is_str_digit(argv[i]))
			number = ft_atoi(argv[i++]);
		while (i < argc)
			if (!argv[i] || !ft_strlen(argv[i]) || (argv[i] &&
						ft_is_str_space(argv[i])))
				i++;
		if (is_a_flag(argv[i], &i, argv[i + 1], argc))
			continue ;
		if (i >= argc)
			break ;
		if (!arena->players)
			arena->players = create_new_player(number, argv[i]);
		else
			add_player(arena, number, argv[i]);
	}
}
