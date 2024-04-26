/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_and_open_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:54:30 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/15 17:06:47 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"	

int	**ft_make_and_open_pipes(int fd_quant)
{
	int	i;
	int	**fd;

	i = 0;
	fd = (int **)malloc(sizeof(int *) * (fd_quant));
	if (!fd)
	{
		perror("Can't allocate memory in ft_make_and_open_pipes()");
		exit(EXIT_FAILURE);
	}
	while (i < fd_quant)
	{
		fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!fd[i])
		{
			perror("Can't allocate memory in ft_make_and_open_pipes()");
			exit(EXIT_FAILURE);
		}
		if ((pipe(fd[i]) < 0))
			perror("Can't create pipes");
		i++;
	}
	return (fd);
}
