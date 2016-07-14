/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:01:33 by sjulliot          #+#    #+#             */
/*   Updated: 2016/07/14 04:02:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern char * g_error_messages[];

void				parse_opened_file(int fd, t_asm_data *data)
{
	int				line_nb;
	int				ret;
	char			*line;

	line_nb = 1;
	while (!data->error && (ret = get_next_line(fd, &line)) > 0)
	{
		epur_str(&line);
		if (*line)
		{
			if (line_is_name(line))
				extract_name_from_line(line, data);
			else if (line_is_comment(line))
				extract_comment_from_line(line, data);
			else
				push_lst_instruction(&(data->lines),
										create_lst_instruction(line, line_nb));
		}
		line_nb++;
		free(line);
	}
	if (!data->lines && !data->error)
		data->error = (ret == -1 ? UNREADABLE_FILE : EMPTY_FILE);
}

void				print_success(char *filename)
{
	ft_printf("%[[FG_GRE,SP_RST]s : %[[FG_YEL,SP_RST]s created!\n", 
			"SUCCESS", filename);
}

int					file_is_readable(char *filename, t_asm_data *data)
{
	int				fd;

	if ((fd = open(filename, O_RDONLY)) != -1)
		parse_opened_file(fd, data);
	else
		data->error = UNREADABLE_FILE;
	if (!data->error)
		data->base_filename = ft_strndup(filename, ft_strlen(filename) - 2);
	return (data->error ? 0 : 1);
}

void				print_error(int file_index, char **argv, t_asm_data *data)
{
	const char		*message = g_error_messages[data->error];

	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s ", "->");
	ft_printf("%[[FG_MAG,SP_RST]s ", argv[file_index]);
	if (data->line_number_of_error)
		ft_printf("at line [%[[FG_GRE,SP_RST]d] ", data->line_number_of_error);
	ft_printf(": %s\n", message);
}

static void			reset_data(t_asm_data *data, char *last_argument)
{
	int				old_bonus;

	old_bonus = ft_strcmp(last_argument, "-a");
	ft_bzero(data, sizeof(t_asm_data));
	data->display_byte_info = !old_bonus;
}

static char			*from_s_to_cor(char *file)
{
	char			*cor_file;
	const int		len = ft_strlen(file);

	if (len <= 2)
		return (NULL);
	cor_file = (char*)malloc(sizeof(char) * (len + 3));
	cor_file = ft_strcpy(cor_file, file);
	cor_file[len - 1] = 'c';
	cor_file[len] = 'o';
	cor_file[len + 1] = 'r';
	cor_file[len + 2] = 0;
	return (cor_file);
}

void				treat_all_files(int argc, char **argv)
{
	int				i;
	t_asm_data		data;
	char			*tmp;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-a"))
			continue ;
		tmp = from_s_to_cor(argv[i]);
		reset_data(&data, argv[i - 1]);
		if (is_a_cor_file(argv[i]))
			disassemble(argv[i]);
		else if (!is_valid_filename(argv[i], &data) ||
			!file_is_readable(argv[i], &data) ||
			!has_name(&data) ||
			!has_comment(&data) ||
			!lines_are_correct(&data) ||
			!create_file(tmp, &data))
			print_error(i, argv, &data);
		else
			print_success(tmp);
	}
}

int					main(int argc, char **argv)
{
	if (argc == 1)
		print_usage_and_exit();
	treat_all_files(argc, argv);
	return (0);
}
