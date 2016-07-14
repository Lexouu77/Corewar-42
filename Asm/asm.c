/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:43:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/14 23:48:01 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern char * g_error_messages[];

int		main(int argc, char **argv)
{
	if (argc == 1 || is_only_flags_or_nothing(argc, argv))
		display_usage();
	else
		check_args(argc, argv);
	return (0);
}
