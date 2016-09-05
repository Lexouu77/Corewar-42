/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 05:52:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 07:15:12 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*join_buffer(char *buffer, char *str, int *len, int len_to_add)
{
	char	*new;
	int		i;
	int		j;

	j = -1;
	i = -1;
	if (!(new = malloc(sizeof(char) * (*len + len_to_add + 1))))
		ft_malloc_error();
	new[*len + len_to_add] = 0;
	while (buffer && ++i < *len)
		new[i] = buffer[i];
	i = *len - 1;
	while (++i < *len + len_to_add)
		new[i] = str[++j];
	*len = *len + len_to_add;
	if (buffer)
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
		va_start(args, format);
		new_str = ft_printf_str(&new_len, format, args);
		va_end(args);
		buffer = join_buffer(buffer, new_str, &len, new_len);
	}
	if (flush)
	{
		write(1, buffer, len);
		new_len = len;
		len = 0;
		free(buffer);
		buffer = NULL;
		return (new_len);
	}
	return (0);
}
