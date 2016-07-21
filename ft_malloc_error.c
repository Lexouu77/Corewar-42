/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 08:24:27 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/27 09:05:10 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_malloc_error(void)
{
	ft_putendl("Error : Memory Allocation Failed. Retry with more rights!");
	exit(-1);
}
