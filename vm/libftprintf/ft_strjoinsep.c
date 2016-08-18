/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinsep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:12 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:12 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>

char	*ft_strjoinsep(const char *s1, const char *s2, char sep)
{
	char	*res;
	size_t	size1;
	size_t	size2;

	if (*s1 == '\0')
		return (ft_strdup(s2));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (size1 + size2 + 2))))
		ft_malloc_error();
	ft_memcpy((void*)res, (void*)s1, size1);
	if (res)
		res[size1] = sep;
	ft_memcpy((void*)res + size1 + (res ? 1 : 0), (void*)s2, size2);
	res[size1 + size2 + (res ? 1 : 0)] = '\0';
	return (res);
}
