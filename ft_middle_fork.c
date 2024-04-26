/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:30:24 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/15 17:25:40 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

int	ft_middle_fork(int **fd, int *fd_middle, char **argv, char **envp)
{
	int	fd_quant;

	fd_quant = ft_fd_count(argv);
	dup2(fd_middle[0], STDIN_FILENO);
	dup2(fd_middle[1], STDOUT_FILENO);
	ft_fd_close(fd, fd_quant);
	ft_execve_middlefork(fd_middle, argv, envp);
	perror("Error in Middle fork");
	exit(EXIT_FAILURE);
}
