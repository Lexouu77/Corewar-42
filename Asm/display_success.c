/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_success.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 00:32:24 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 00:38:27 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				display_success(char *filename)
{
	ft_printf("%[[FG_GRE,SP_RST]s : %[[FG_YEL,SP_RST]s created!\n", 
			"SUCCESS", filename);
}
