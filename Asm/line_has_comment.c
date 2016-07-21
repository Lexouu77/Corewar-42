/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_has_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:55:53 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 18:44:20 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		line_has_comment(char *s)
{
	if (ft_strstr(s, "#") || ft_strstr(s, "//") || ft_strstr(s, ";") ||
			ft_strchr(s, COMMENT_CHAR)) // TODO : Test it later
		return (1);
	return (0);
}
