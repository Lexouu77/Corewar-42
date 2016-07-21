/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferujoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:23:12 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/06 17:12:07 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			bufferujoin(t_info *list, int c)
{
	const int	len = uc_to_str(list, c);

	bufferjoin(list, list->tmp_second, len);
	free(list->tmp_second);
}
