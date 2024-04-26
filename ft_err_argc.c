/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_argc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:58:28 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/15 18:37:03 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

void	ft_err_argc(int argc, char **argv)
{
	if (argc < 5)
	{
		write(1, "Wrong argcy quantity\n", 21);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(argv[1]) == 8 && !ft_strncmp(argv[1], "here_doc", 8)
		&& argc < 6)
	{
		write(1, "Wrong argcy quantity\n", 21);
		exit(EXIT_FAILURE);
	}
	return ;
}
