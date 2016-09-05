/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 05:26:16 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 05:49:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_terminal(t_vm_data *arena)
{
	if ((arena->term_name = getenv("TERM")) == NULL)
		ft_error("getenv(\"TERM\") returned NULL.\n ");
	if (tgetent(NULL, arena->term_name) == -1)
		ft_error("tgetent returned -1.\n ");
	if (tcgetattr(0, &arena->term) == -1)
		ft_error("tcgetattr returned -1.\n ");
	arena->term.c_lflag &= ~(ICANON);
	arena->term.c_lflag &= ~(ECHO);
	arena->term.c_cc[VMIN] = 1;
	arena->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &arena->term) == -1)
		ft_error("tcsetattr returned -1.\n");
}

static void	reset_terminal(t_vm_data *arena)
{
	if (tcgetattr(0, &arena->term) == -1)
		ft_error("tcgetattr returned -1.\n");
	arena->term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &arena->term) == -1)
		ft_error("tcsetattr returned -1.\n");
}

static void	change_loop_value(t_vm_data *arena, int value)
{
	if (value == 113 && arena->cycles_to_loop_dump - 10 > 0)
	{
		arena->cycles_to_loop_dump -= 10;
		display_field(arena);
	}
	if (value == 119 && arena->cycles_to_loop_dump - 1 > 0)
	{
		arena->cycles_to_loop_dump--;
		display_field(arena);
	}
	if (value == 101 && arena->cycles_to_loop_dump + 1 < 1001)
	{
		arena->cycles_to_loop_dump++;
		display_field(arena);
	}
	if (value == 114 && arena->cycles_to_loop_dump + 10 < 1001)
	{
		arena->cycles_to_loop_dump += 10;
		display_field(arena);
	}
}

void		manage_keys(t_vm_data *arena)
{
	char	c[3];

	if ((getenv("TERM")) == NULL)
		ft_error("Getenv returned NULL.\n");
	init_terminal(arena);
	int	x = 5;
	while (x)
	{
		read(0, c, 3);
		if (c[0] == 10)
			break ;
		if (c[0] == 113 || c[0] == 119 || c[0] == 101 || c[0] == 114)
			change_loop_value(arena, c[0]);
		if (c[0] == 3 || c[0] == 4)
			exit(0);
	}
	reset_terminal(arena);
}
