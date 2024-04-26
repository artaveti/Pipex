/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_fdmiddle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:36:31 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/13 13:37:31 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

int	*ft_make_fdmiddle(void)
{
	int	*fd_middle;

	fd_middle = (int *)malloc(sizeof(int) * 3);
	if (!fd_middle)
	{
		perror("Can't allocate memory in ft_make_fdmiddle()");
		exit(EXIT_FAILURE);
	}
	fd_middle[0] = 0;
	fd_middle[1] = 0;
	fd_middle[2] = 0;
	return (fd_middle);
}
