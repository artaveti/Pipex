/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:51:55 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/15 17:46:34 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

int	ft_first_fork(int **fd, char **path_arr, char **argv, char **envp)
{
	int		fd_quant;
	int		file1_fd;

	fd_quant = ft_fd_count(argv);
	ft_make_file1fd(&file1_fd, argv);
	dup2(file1_fd, STDIN_FILENO);
	dup2(fd[0][1], STDOUT_FILENO);
	ft_fd_close(fd, fd_quant);
	unlink("h_d");
	if ((close(file1_fd) < 0))
	{
		perror("Cant close argv[1]");
		exit(EXIT_FAILURE);
	}
	ft_execve_firstfork(path_arr, argv, envp);
	perror("Error in First fork");
	exit(EXIT_FAILURE);
}
