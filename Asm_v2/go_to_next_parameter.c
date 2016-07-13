/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_next_parameter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:26:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/17 17:33:54 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*go_to_next_parameter(char *line)
{
	while (*line && *line != 32 && *line != ',')
		++line;
	while (*line && (*line == 32 || *line == ','))
		++line;
	return (line);
}
