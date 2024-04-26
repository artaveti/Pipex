/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:08:57 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/12 19:09:07 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

int	ft_fd_count(char **argv)
{
	int	i;

	if (!argv || !argv[0])
	{
		return (0);
	}
	i = 0;
	while (argv[i] != NULL)
	{
		i++;
	}
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		return (i - 5);
	}
	else
	{
		return (i - 4);
	}
}
