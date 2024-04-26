/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_fdmiddle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:00:29 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/13 16:22:40 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

void	ft_change_fdmiddle(int **fd, int *fd_middle, char **argv, int num)
{
	fd_middle[0] = fd[num][0];
	fd_middle[1] = fd[num + 1][1];
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		fd_middle[2] = num + 4;
	}
	else
	{
		fd_middle[2] = num + 3;
	}
	return ;
}
