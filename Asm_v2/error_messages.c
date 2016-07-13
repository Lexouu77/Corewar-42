/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:46:10 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/24 09:18:56 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char			*g_error_messages[19] = {
	"no error",
	"no filename given",
	"given file is not a .s file",
	"file could not be read",
	"empty file",
	"multiple name definitions",
	"multiple comment definitions",
	"missing name",
	"missing comment",
	"invalid character",
	"invalid instruction",
	"invalid instruction format",
	"invalid number of parameters",
	"invalid register",
	"unknown label",
	"missing magic code",
	"missing instructions",
	"multiple instructions",
	"couldn't create the .cor file"
};
