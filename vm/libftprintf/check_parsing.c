/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:43 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_alphabetic_type(char c)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == '%')
		return (1);
	else
		return (0);
}

int			is_special_type(char c)
{
	if (c == 'n' || c == 'p' || c == 'B' || c == 'b' || c == 'V' || c == 'v')
		return (1);
	else
		return (0);
}

int			is_a_sub_specifier(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 't' || c == 'L')
		return (1);
	else
		return (0);
}

int			is_a_valid_type(char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'p' || c == 'D'
			|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U'
			|| c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 'f'
			|| c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G'
		|| c == 'a' || c == 'A' || c == '%' || c == 'n' || c == 'v' ||
		c == 'V' || c == 'B' || c == 'b')
		return (1);
	else
		return (0);
}

int			is_a_good_flag_or_type(char *s)
{
	if (is_a_valid_type(*s) || is_a_sub_specifier(*s) || ft_isdigit(*s) ||
			*s == 32 || *s == 45 || *s == 43 || *s == 35 ||
			(*s == 46) || (*s == 91 && *(s + 1) == 91) ||
			(*s == 46 && *(s + 1) == 42) || *s == 42)
		return (1);
	else
		return (0);
}
