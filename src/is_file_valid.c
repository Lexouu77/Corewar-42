/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 08:39:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/12 16:33:42 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		is_file_valid(char *file)
{
	struct stat	stats;

	if (access(file, F_OK) == -1)
		return (display_error("File does not exist", file));
	if (access(file, R_OK) == -1)
		return (display_error("Missing read rights on this file", file));
	if (stat(file, &stats) == -1)
		ft_error("Stat returned -1.");
	if (!stats.st_size)
		return (display_error("Empty file", file));
	return (1);
}
