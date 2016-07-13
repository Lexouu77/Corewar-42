/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 20:21:54 by sjulliot          #+#    #+#             */
/*   Updated: 2016/05/02 16:27:47 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

char		*ft_strjoin_and_free(char *s1, const char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}
