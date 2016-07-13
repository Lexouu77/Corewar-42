/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:09:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/18 18:26:02 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_bonus_flags(char *flag, t_asm_data *data)
{
	if (!ft_strcmp(flag, "-a"))
	{
		data->display_byte_info = 1;
		return (1);
	}
	return (0);
}
