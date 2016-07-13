/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinsep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oceyral <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:32:01 by oceyral           #+#    #+#             */
/*   Updated: 2016/05/02 16:29:52 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>

char *ft_strjoinsep(const char *s1, const char *s2, char sep)
{
	char	*res;
	size_t	size1;
	size_t	size2;

	if (*s1 == '\0')
		return (ft_strdup(s2));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (size1 + size2 + 2))))
		return (NULL);
	ft_memcpy((void*)res, (void*)s1, size1);
	if (res)
		res[size1] = sep;
	ft_memcpy((void*)res + size1 + (res ? 1 : 0), (void*)s2, size2);
	res[size1 + size2 + (res ? 1 : 0)] = '\0';
	return (res);
}
