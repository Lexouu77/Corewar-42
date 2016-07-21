/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 21:56:19 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 23:32:20 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		stock_name(t_file_line *node, t_data *data, int i)
{
	data->name = ft_strndup(node->line + i, ft_strxlen(node->line + i, '"'));
	free(node->line);
	return (1);
}
