/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:11 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:11 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ns;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		ns = ft_strnew(i);
		if (ns)
		{
			ns = ft_strcpy(ns, s1);
			ns = ft_strcat(ns, s2);
			return (ns);
		}
	}
	return (NULL);
}
