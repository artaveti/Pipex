/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_if_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:34:42 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/12 19:35:09 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

int	ft_num_if_access(char	**prog_paths)
{
	int	i;

	i = 0;
	while (prog_paths[i] != NULL)
	{
		if ((access(prog_paths[i], F_OK) == 0))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
