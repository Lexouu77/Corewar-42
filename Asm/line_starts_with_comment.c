/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_starts_with_comment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:08:49 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/16 23:47:05 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		line_starts_with_comment(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (!s[i])
		return (0);
	if (s[i] == '#' || s[i] == ';' || (s[i + 1] && s[i] == '/' && s[i] == '/'))
		return (1);
	return (0);
}
