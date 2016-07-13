/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinsep_and_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 21:44:42 by sjulliot          #+#    #+#             */
/*   Updated: 2016/05/02 16:30:12 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

char			*ft_strjoinsep_and_free(char *s1, const char *s2, char c)
{
	char		*tmp;

	tmp = ft_strjoinsep(s1, s2, c);
	free(s1);
	return (tmp);
}
