/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:14 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*mappedstr;

	if (!s || !f)
		return (NULL);
	mappedstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mappedstr)
		return (NULL);
	i = -1;
	while (s[++i])
		mappedstr[i] = f(s[i]);
	mappedstr[i] = '\0';
	return (mappedstr);
}
