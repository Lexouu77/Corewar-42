/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:43:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/13 16:58:49 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern char * g_error_messages[];

int main(int argc, char **argv)
{
	if (argc == 1 || is_only_bonus(argc, argv))
		print_usage_and_exit();
	return (0);
}
