/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_file1fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:19:19 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/15 17:06:30 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

void	ft_make_file1fd(int *file1_fd, char **argv)
{
	char	*line;

	if (ft_strlen(argv[1]) == 8 && !ft_strncmp(argv[1], "here_doc", 8))
	{
		*file1_fd = open("h_d", O_CREAT | O_RDWR | O_TRUNC, 0644);
		line = get_next_line(STDIN_FILENO);
		while (ft_strncmp(line, argv[2], ft_strlen(argv[2]))
			|| ft_strncmp(line, argv[2], ft_strlen(line) - 1))
		{
			write(*file1_fd, line, ft_strlen(line));
			free(line);
			line = get_next_line(STDIN_FILENO);
		}
		free(line);
		close(*file1_fd);
		*file1_fd = open("h_d", O_RDONLY, 0644);
	}
	else
		*file1_fd = open(argv[1], O_RDONLY, 0644);
	if (*file1_fd < 0)
		perror("Can't open argv[1]");
	return ;
}
