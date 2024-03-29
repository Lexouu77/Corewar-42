/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fctrl(int nb)
{
	if (nb < 0)
		return (0);
	return ((nb == 0) ? 1 : nb * ft_fctrl(nb - 1));
}
