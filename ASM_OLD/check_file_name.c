/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:53:54 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/17 13:55:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					is_valid_filename(char *filename, t_asm_data *data)
{
	const int		len = ft_strlen(filename);

	if (len == 0)
		data->error = EMPTY_FILENAME;
	else if (len < 3 || ft_strcmp(filename + len - 2, ".s"))
		data->error = NOT_A_DOT_S_FILE;
	return (data->error ? 0 : 1);
}
