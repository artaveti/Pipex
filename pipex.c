/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:37:22 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/15 18:11:23 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_variables	v;

	ft_err_argc(argc, argv);
	ft_make_num_fdquant(&v.num, &v.fd_quant, argv);
	v.path_arr = ft_make_path_arr(envp);
	v.fd = ft_make_and_open_pipes(v.fd_quant);
	v.fd_middle = ft_make_fdmiddle();
	v.first_fork = fork();
	if (v.first_fork == 0)
		ft_first_fork(v.fd, v.path_arr, argv, envp);
	while (++v.num < v.fd_quant - 1)
	{
		ft_change_fdmiddle(v.fd, v.fd_middle, argv, v.num);
		v.middle_fork = fork();
		if (v.middle_fork == 0)
			ft_middle_fork(v.fd, v.fd_middle, argv, envp);
	}
	v.last_fork = fork();
	if (v.last_fork == 0)
		ft_last_fork(v.fd, v.path_arr, argv, envp);
	ft_fd_close(v.fd, v.fd_quant);
	while (wait(NULL) != -1)
		;
	exit(EXIT_SUCCESS);
}
	//system("leaks pipex");