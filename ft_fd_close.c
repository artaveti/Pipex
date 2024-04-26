/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:28:59 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/13 14:31:26 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

void	ft_fd_close(int **fd, int fd_quant)
{
	int	i;

	i = 0;
	while (i < fd_quant)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	return ;
}
