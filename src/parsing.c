/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:13:13 by srudman           #+#    #+#             */
/*   Updated: 2024/06/20 15:03:52 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_concatinate(t_pipex_strt *data, int j)
{
	int		i;
	char	*tmp_cmd;

	i = 0;
	tmp_cmd = NULL;
	while (data->full_cmd[j]->path[i])
	{
		tmp_cmd = ft_strjoin(data->full_cmd[j]->path[i],
				data->full_cmd[j]->cmd);
		if (!tmp_cmd)
		{
			free(tmp_cmd);
			pipex_exit(data, NO_MEMORY, NULL);
		}
		if (access(tmp_cmd, F_OK) == 0)
		{
			free(data->full_cmd[j]->cmd);
			data->full_cmd[j]->cmd = ft_strdup(tmp_cmd);
			free(tmp_cmd);
			break ;
		}
		else
			free(tmp_cmd);
		i++;
	}
}

void	parse_input_cmd(char *argv, t_pipex_strt *data, int j)
{
	int	i;

	i = 0;
	if (argv[0] == '\0')
	{
		put_error(CMD_NOT_FOUND, argv);
		data->full_cmd[j]->skip = true;
	}
	data->full_cmd[j]->flag = ft_split(argv, ' ');
	while (argv[i] && argv[i] != ' ')
		i++;
	data->full_cmd[j]->cmd = malloc(sizeof(char) * (i + 2));
	if (!data->full_cmd[j]->cmd)
		pipex_exit(data, NO_MEMORY, NULL);
	i = 0;
	data->full_cmd[j]->cmd[i] = '/';
	while (argv[i] && argv[i] != ' ')
	{
		data->full_cmd[j]->cmd[i + 1] = argv[i];
		i++;
	}
	data->full_cmd[j]->cmd[i + 1] = '\0';
	ft_concatinate(data, j);
}

int	parse_envp_path(char **envp, t_pipex_strt *data, int j)
{
	int	i;

	i = 0;
	if (envp[i] == NULL)
	{
		put_error(NO_PATH, "env");
		data->full_cmd[j]->skip = true;
		return (0);
	}
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	if (ft_strncmp("PATH=", envp[i], 5) != 0)
	{
		put_error(NO_PATH, "env");
		data->full_cmd[j]->skip = true;
		return (0);
	}
	data->full_cmd[j]->path = ft_split(envp[i] + 5, ':');
	i = 0;
	return (1);
}

/* I parse **envp to get the path to commands in my struct (*data)->cmd_path
I also allocate commands from the terminal input to my struct, specifically
to the (*data)->cmd_argv.*/

void	parse_input(int argc, char **argv, char **envp, t_pipex_strt **data)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	(*data)->full_cmd = malloc(sizeof(t_cmd_strt *) * (argc - i));
	if (!(*data)->full_cmd)
		pipex_exit(*data, NO_MEMORY, NULL);
	while (i < argc - 1)
	{
		cmd_strt_init(data, j);
		if (argv[i][0] == '/')
			(*data)->full_cmd[j]->cmd = strdup(argv[i]);
		else
		{
			if (!parse_envp_path(envp, *data, j))
				break ;
			parse_input_cmd(argv[i], *data, j);
		}
		check_input_cmd(*data, j++, i++, argc);
	}
	(*data)->full_cmd[j] = NULL;
}
