/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 05:52:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 06:14:06 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*join_buffer(char *buffer, char *str, int *len, int len_to_add)
{
	char	*new;
	int		i;

	i = -1;
	if (!(new = malloc(sizeof(char) * (*len + len_to_add + 1))))
		ft_malloc_error();
	new[*len + len_to_add] = 0;
	while (++i < *len)
		new[i] = buffer[i];
	i--;
	while (++i < *len + len_to_add)
		new[i] = str[i];
	*len = *len + len_to_add;
	free(buffer);
	free(str);
	return (new);
}

int			ft_printf_buffed(int flush, char *format, ...)
{
	static char	*buffer = NULL;
	static int	len = 0;
	int			new_len;
	char		*new_str;
	va_list		args;

	if (!flush || format)
	{
		new_len = 0;
		va_start (args, format);
		new_str = ft_printf_str(&new_len, format, args);
		va_end (args);
		if (buffer == NULL)
			buffer = new_str;
		if (buffer == NULL)
			len = new_len;
		else
			buffer = join_buffer(buffer, new_str, &len, new_len);
	}
	if (flush)
	{
		write(1, buffer, len);
		len = 0;
		free(buffer);
		buffer = NULL;
		return (len);
	}
	return (0);
}
