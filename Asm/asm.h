/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 18:07:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/14 19:03:15 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "./libftprintf/ft_printf.h"
# include "op.h"

void						check_args(int argc, char **argv);

/* DISPLAY FUNCTIONS */

void						display_usage(void);

/* TEST FUNCTIONS */

int							is_a_cor_file(char *filename);
int							is_a_s_file(char *filename);
int							is_only_flags_or_nothing(int argc, char **argv);


#endif
