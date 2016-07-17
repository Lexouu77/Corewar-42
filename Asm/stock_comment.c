/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 21:56:23 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 22:08:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		stock_comment(t_file_line *node, t_data *data, int i)
{
	data->comment = ft_strndup(node->line + i, ft_strxlen(node->line + i, '"'));
	free(node->line);
	return (1);
}
