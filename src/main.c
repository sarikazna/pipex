/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:08:04 by srudman           #+#    #+#             */
/*   Updated: 2024/06/20 15:07:50 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* Before we can start running the pipe we have to open both, infile and 
outfile, but we only open them if they are valid (i.e. 
(*data)->infile_valid == true). If we already know they are invalid, we
don't do anything and the fd of that will remain to be -1.
If the outfile does not exist, the open() function creates it and assignes
permissions to it the same way pipe does it (0644 means read/write for owner,
read-only for group and others). */

void	open_files(t_pipex_strt **data, char *infile_argv, char *outfile_argv)
{
	if ((*data)->infile_valid == true)
	{
		(*data)->infile = open(infile_argv, O_RDONLY);
		if ((*data)->infile == -1)
		{
			(*data)->infile_valid = false;
			put_error(-12, infile_argv);
		}
	}
	if ((*data)->outfile_valid == true)
	{
		(*data)->outfile = open(outfile_argv,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if ((*data)->outfile == -1)
		{
			(*data)->outfile_valid = false;
			put_error(-12, outfile_argv);
		}
	}
}

/* We ran checks on the number of arguments, check if the infile is existing
and is readable. We initialise the stack and performing parsing. */

int	main(int argc, char **argv, char **envp)
{
	t_pipex_strt	*data;

	data = NULL;
	data_init(&data);
	if (!(argc == 5))
		pipex_exit(data, INV_ARGS, argv[1]);
	check_files(argc, argv, &data);
	parse_input(argc, argv, envp, &data);
	open_files(&data, argv[1], argv[argc - 1]);
	pipex(&data, envp, argc - 3);
	pipex_exit(data, END, "Happy End\n");
}
