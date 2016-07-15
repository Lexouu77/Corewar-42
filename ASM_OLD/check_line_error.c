/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:52:26 by sjulliot          #+#    #+#             */
/*   Updated: 2016/07/15 09:12:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
extern t_op g_op_tab[17];

void				check_label_name(char *name, t_asm_data *data)
{
	while (*name)
	{
		if (!ft_strchr(LABEL_CHARS, *name))
		{
			data->error = INVALID_CHARACTER;
			return ;
		}
		name ++;
	}
}

int					ft_strcount(char *str, char c)
{
	int				res;

	res = 0;
	while (*str)
	{
		res += (*str == c);
		str ++;
	}
	return (res);
}

int					check_instruction_name(char *name, t_asm_data *data)
{
	int				i;

	i = -1;
	while (++i < 17)
		 if (!ft_strcmp(g_op_tab[i].name, name))
			 return (1);
	data->error = INVALID_INSTRUCTION;
	return (0);
}

int					get_instruction_params_number(char *name)
{
	int				i;

	i = -1;
	while (++i < 17)
		 if (!ft_strcmp(g_op_tab[i].name, name))
			 return (g_op_tab[i].arg_number);
	return (0);
}

int					get_param_type(char *instruction_name, int param_index)
{
	int				i;

	i = -1;
	while (++i < 17)
		 if (!ft_strcmp(g_op_tab[i].name, instruction_name))
			 return (g_op_tab[i].args_type[param_index]);
	return (0);
}

int					infere_param_type(char *param, t_asm_data *data)
{
	const size_t	len = ft_strlen(param);

	if (len == 0)
	{
		data->error = INVALID_INSTRUCTION_FORMAT;
		return (-1);
	}
	if (param[0] == 'r')
		return (T_REG);
	if (ft_isdigit(param[0]))
		return (T_IND);
	if (ft_strlen(param) <= 1)
	{
		data->error = INVALID_INSTRUCTION_FORMAT;
		return (-1);
	}
	if (param[0] == DIRECT_CHAR && param[1] == LABEL_CHAR)
		return (T_LAB);
	else
		return (T_DIR);
}

int					is_number(const char *str)
{
	while (str && *str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void				check_reg_format(char *param, t_asm_data *data)
{
	int		reg_nb;

	reg_nb = ft_atoi(param + 1);
	if (ft_strlen(param) <= 1 || !is_number(param + 1) || 
			(reg_nb > REG_NUMBER || reg_nb < 1))
	{
		data->error = INVALID_REGISTER;
		return ;
	}
}

void				check_param_format(char *inst, int param_index, char *param, t_asm_data *data)
{
	int				allowed_types;
	int				given_type;

	allowed_types = get_param_type(inst, param_index);
	given_type = infere_param_type(param, data);
	if (data->error)
		return ;
	if (!(given_type & allowed_types))
	{
*/		/*
		ft_printf("jolie erreur %s param %s\n", inst, param);
		ft_printf("param index %d\n", param_index);
		ft_printf("given_type %d\nallowed %d", given_type, allowed_types);
		*/
/*		data->error = INVALID_INSTRUCTION_FORMAT;
		return ;
	}
	if (given_type & T_REG)
		check_reg_format(param, data);
}*//*

char				**ft_strsplit_first(char *str, char sep)
{
	char			**res;
	char			*sep_pos;
	int				params_nb;

	sep_pos = ft_strchr(str, sep);
	params_nb = 1 + (sep_pos ? 1 : 0);
	res = ft_memalloc((params_nb + 1) * sizeof(char*));
	if (params_nb == 1)
		res[0] = str;
	else
	{
		res[0] = ft_strndup(str, sep_pos - str);
		res[1] = ft_strndup(sep_pos + 1, ft_strlen(sep_pos + 1));
	}
	return (res);
}

int					check_instruction_params(char **splited, t_asm_data *data)
{
	int				params_nb;
	int				correct_params_nb;

	correct_params_nb = get_instruction_params_number(splited[0]);
	params_nb = 0;
	while (splited[params_nb + 1] != NULL)
		params_nb++;
	if (params_nb != correct_params_nb)
	{
		data->error = INVALID_PARAMS_NUMBER;
		return (0);
	}
	while (params_nb -- > 1 && !data->error)
	{
		check_param_format(splited[0], params_nb - 1, splited[params_nb], data);
	}
	return (data->error ? 0 : 1);
}

void				check_instruction(char *instruction, t_asm_data *data)
{
	 char **splited;
	 int	i;

	if (!ft_strchr(instruction, ' '))
	{
		data->error = INVALID_PARAMS_NUMBER;
		return ;
	}
	i = -1;
	if (ft_strstr(instruction, ",,"))
	{
		data->error = INVALID_INSTRUCTION_FORMAT;
		return ;
	}
	if ((splited = ft_strmultisplit(instruction, " ,")) == NULL) // TODO reset epur_str et coder un strsplit avec plusieurs separateurs
		ft_malloc_error();
	check_instruction_name(splited[0], data) && check_instruction_params(splited, data);
}

void				check_labeled_line(char *line, t_asm_data *data)
{
	char			**splited;

	if (!ft_strchr(line, ' '))
	{
		data->error = INVALID_PARAMS_NUMBER;
		return ;
	}
	if ((splited = ft_strsplit(line, LABEL_CHAR)) == NULL)
		ft_malloc_error();
	check_label_name(splited[0], data);
	check_instruction(splited[1], data);
}
*/
int					check_line_error(char *line)/*, t_asm_data *data, int line_number)*/
{
	(void)line;
	/*if (ft_strchr(line, LABEL_CHAR))
	{
		check_labeled_line(line, data);
		if (data->error)
		{
			data->error = NO_ERROR;
			check_instruction(line, data);
		}
	}
	else
		check_instruction(line, data);
	if (data->error)
		data->line_number_of_error = line_number;*/
//	return (data->error ? 1 : 0);
	return (0);
}
