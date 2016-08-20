/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferujoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:42 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:42 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			bufferujoin(t_info *list, int c)
{
	const int	len = uc_to_str(list, c);

	bufferjoin(list, list->tmp_second, len);
	free(list->tmp_second);
}
