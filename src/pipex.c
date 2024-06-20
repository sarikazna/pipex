/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:24:19 by srudman           #+#    #+#             */
/*   Updated: 2024/06/20 15:08:06 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	execute(t_cmd_strt *full_cmd, char **envp)
{
	return (execve(full_cmd->cmd, full_cmd->flag, envp));
}

void	child_process(t_pipex_strt **data, char **envp, int pipefd[2])
{
	if ((*data)->infile_valid == true)
	{
		if (dup2((*data)->infile, STDIN_FILENO) < 0)
			pipex_exit(*data, DUP_ERR, "dup2 failed");
		if (dup2(pipefd[1], STDOUT_FILENO) < 0)
			pipex_exit(*data, DUP_ERR, "dup2 failed");
		close (pipefd[0]);
		close ((*data)->infile);
		execute((*data)->full_cmd[0], envp);
	}
}

void	parent_process(t_pipex_strt **data, char **envp, int pipefd[2])
{
	pid_t	pid2;

	if ((*data)->outfile_valid == true)
	{
		if (dup2((*data)->outfile, STDOUT_FILENO) < 0)
			pipex_exit(*data, DUP_ERR, "dup2 failed");
		if (dup2(pipefd[0], STDIN_FILENO) < 0)
			pipex_exit(*data, DUP_ERR, "dup2 failed");
		close (pipefd[1]);
		close ((*data)->outfile);
		pid2 = fork();
		if (pid2 < 0)
			pipex_exit(*data, FORK_ERR, "Fork failed");
		if (!pid2)
			execute((*data)->full_cmd[1], envp);
	}
}

void	pipex(t_pipex_strt **data, char **envp, int cmd_nbr)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;
	int		i;

	if (pipe(pipefd) == -1)
		pipex_exit(*data, PIPE_ERR, "pipe");
	pid = fork();
	if (pid < 0)
		pipex_exit(*data, FORK_ERR, "Fork failed");
	if (!pid)
		child_process(data, envp, pipefd);
	else
		parent_process(data, envp, pipefd);
	i = 0;
	while (i <= cmd_nbr)
	{
		waitpid(-1, &status, 0);
		i++;
	}
}
