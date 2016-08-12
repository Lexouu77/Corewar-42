/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 22:30:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/12 15:09:19 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "./libftprintf/ft_printf.h"
# include "op.h"
# include "vm_struct.h"

/*
** DISPLAY FUNCTIONS
*/

void			display_usage(void);

/*
** INITIALISATION FUNCTIONS
*/

t_vm_data		*init_data(void);

/*
** FREE FUNCTIONS
*/

void			free_arena(t_vm_data *arena);

/*
** PARSING FUNCTIONS
*/

void			parse_flag(int argc, char **argv, t_vm_data *arena);

#endif
