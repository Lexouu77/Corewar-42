/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:24 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:24 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isblankspace(char c)
{
	return ((c == 32 || c == 9 || c == 10) ? 1 : 0);
}

static int	ft_isstrempty(char *s)
{
	size_t len;

	len = ft_strlen(s);
	while (len > 0 && ft_isblankspace(*s))
	{
		--len;
		++s;
	}
	return ((!len) ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char const		*begin_s = s;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	if (ft_isstrempty((char*)s))
		return (ft_strdup(""));
	while (*s && ft_isblankspace(*s))
	{
		++start;
		++s;
	}
	while (*s)
		++s;
	--s;
	while (*s && ft_isblankspace(*s))
	{
		++end;
		--s;
	}
	return (ft_strsub(begin_s, start, ft_strlen(begin_s) - start - end));
}
