/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_path_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:33:07 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/12 19:33:16 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

char	**ft_make_path_arr(char	**envp)
{
	int		i;
	int		j;
	char	**path_arr;

	i = 0;
	j = 0;
	if (!envp)
	{
		return (NULL);
	}
	while (envp[i] != NULL)
	{
		j = 0;
		while (envp[i][j] == "PATH="[j])
		{
			if (j == 4)
			{
				path_arr = ft_split(ft_strchr(envp[i], '/'), ':');
				break ;
			}
			j++;
		}
		i++;
	}
	return (path_arr);
}
