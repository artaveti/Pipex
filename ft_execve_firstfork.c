/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_firstfork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:03:34 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/14 15:06:21 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

void	ft_execve_firstfork(char **path_arr, char **argv, char **envp)
{
	int		i;
	char	**argv_for_execve;
	char	**prog_paths;

	i = -1;
	if (ft_strlen(argv[1]) == 8 && !ft_strncmp(argv[1], "here_doc", 8))
		argv_for_execve = ft_split(argv[3], ' ');
	else
		argv_for_execve = ft_split(argv[2], ' ');
	if (argv_for_execve[0] == NULL)
		execve("", argv_for_execve, envp);
	else if (argv_for_execve[0][0] == '/' &&
			(access(argv_for_execve[0], F_OK)) == 0)
		execve(argv_for_execve[0], argv_for_execve, envp);
	else
	{
		prog_paths = ft_prog_names_join(path_arr, argv_for_execve[0]);
		while (prog_paths[++i] != NULL)
		{
			if ((access(prog_paths[i], F_OK) == 0))
				execve(prog_paths[i], argv_for_execve, envp);
		}
	}
	return ;
}
