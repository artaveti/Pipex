/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:15 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/15 17:25:54 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

int	ft_last_fork(int **fd, char **path_arr, char **argv, char **envp)
{
	int	fd_quant;
	int	argc_in_lf;
	int	file2_fd;

	fd_quant = ft_fd_count(argv);
	argc_in_lf = ft_arr_count(argv);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		file2_fd = open(argv[argc_in_lf - 1], O_CREAT | O_RDWR
				| O_APPEND, 0644);
	else
		file2_fd = open(argv[argc_in_lf - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(fd[fd_quant - 1][0], STDIN_FILENO);
	dup2(file2_fd, STDOUT_FILENO);
	close(file2_fd);
	ft_fd_close(fd, fd_quant);
	ft_execve_lastfork(argc_in_lf, path_arr, argv, envp);
	perror("Error in Last fork");
	exit(EXIT_FAILURE);
}
