/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_extern.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjivas <adjivas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 16:01:34 by adjivas           #+#    #+#             */
/*   Updated: 2016/09/13 16:12:38 by adjivas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_EXTERN_H
# define VM_EXTERN_H

# include "vm_struct.h"

extern int32_t	core_init(void);

extern int32_t	core_start();
extern int32_t	core_end();
extern int32_t	core_idle(int32_t *field, int32_t *color, int32_t *proc);

int32_t			core_display_info(t_vm_data *arena);
int32_t			core_display_info_player(t_vm_data *arena);

#endif
