/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:54:40 by srudman           #+#    #+#             */
/*   Updated: 2024/04/20 14:27:03 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h> // can I use this?
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h> // needed?
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

enum e_pipex_error
{
	END = 1,
	CMD_NOT_FOUND = 0,
	NO_FILE = -1,
	NO_PERM = -2,
	INV_ARGS = -3,
	NO_MEMORY = -4,
	PIPE_ERR = -5,
	DUP_ERR = -6,
	FORK_ERR = -7,
	NO_PATH = -8,
	CMD_FAIL = -9
};

typedef struct s_cmd_strt
{
	char		**path;
	char		*cmd;
	char		**flag;
	bool		skip;
}	t_cmd_strt;

typedef struct s_pipex_strt
{
	t_cmd_strt	**full_cmd;
	int			infile;
	int			outfile;
	bool		infile_valid;
	bool		outfile_valid;
}	t_pipex_strt;

void	pipex_exit(t_pipex_strt *data, int err, char *argument);
void	put_error(int err, char *argument);
void	parse_input(int argc, char **argv, char **envp, t_pipex_strt **data);
void	data_init(t_pipex_strt **data);
void	cmd_strt_init(t_pipex_strt **data, int j);
void	check_files(int argc, char **argv, t_pipex_strt **data);
void	check_input_cmd(t_pipex_strt *data, int j, int i, int argc);
void	pipex(t_pipex_strt **data, char **envp, int cmd_nbr);

#endif