/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_asm_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 16:17:52 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 19:27:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	delete_cor_file(char **stock_place)
{
	const char	*envp[] = {"LALALALAALALALA.", 0};
	int			pid;
	int			status;

	pid = fork();
	if (pid < 0)
		ft_error("Fork returned -1.\n");
	else if (!pid)
	{
		status = execve("/bin/rm", &stock_place[0], (char**)envp);
		exit(status);
	}
	else
	{
		if (waitpid(pid, &status, 0) < 0)
			ft_error("Waitpid returned -1");
	}
}

static void	execute_asm(char **stock_place)
{
	const char	*envp[] = {"LALALALAALALALA.", 0};
	int			pid;
	int			status;

	pid = fork();
	if (pid < 0)
		ft_error("Fork returned -1.\n");
	else if (!pid)
	{
		status = execve("../Asm/asm", &stock_place[0], (char**)envp);
		exit(status);
	}
	else
	{
		if (waitpid(pid, &status, 0) < 0)
			ft_error("Waitpid returned -1");
	}
}

void		assemble_asm_file(t_player *player)
{
	char		*new_file;
	char		*tmp;
	char		**stock_place;

	stock_place = ft_memalloc(sizeof(char*) * 3);
	stock_place[0] = ft_strdup("asm");
	new_file = ft_strndup(player->filename, ft_strlen(player->filename) - 2);
	tmp = player->filename;
	player->filename = ft_strjoin(new_file, ".cor");
	free(new_file);
	stock_place[1] = player->filename;
	if (access(player->filename, F_OK))
		delete_cor_file(stock_place);
	stock_place[1] = tmp;
	execute_asm(stock_place);
	if (access(player->filename, F_OK) == -1)
		player->validity = 0;
	free(tmp);
	free(stock_place[0]);
	free(stock_place);
}
