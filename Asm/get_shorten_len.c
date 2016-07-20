/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shorten_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:42:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 17:44:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_shorten_len(char *s)
{
	const int	space_len = ft_strxlen(s, 32);
	const int	separator_len = ft_strxlen(s, SEPARATOR_CHAR);

	return (space_len < separator_len ? space_len : separator_len);
}
