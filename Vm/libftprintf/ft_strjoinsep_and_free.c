/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinsep_and_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:12 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:12 by ahamouda         ###   ########.fr       */
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
