/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog_names_join.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:38:10 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/12 19:38:50 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

char	**ft_prog_names_join(char	**path_arr, char	*prog_name)
{
	int		i;
	char	**str_backslash;
	char	**prog_paths;

	i = 0;
	while (path_arr[i] != NULL)
	{
		i++;
	}
	str_backslash = (char **)malloc(sizeof(char *) * (i + 1));
	prog_paths = (char **)malloc(sizeof(char *) * (i + 1));
	str_backslash[i] = NULL;
	prog_paths[i] = NULL;
	i = 0;
	while (path_arr[i] != NULL)
	{
		str_backslash[i] = ft_strjoin(path_arr[i], "/");
		prog_paths[i] = ft_strjoin_space(str_backslash[i], prog_name);
		i++;
	}
	return (prog_paths);
}
