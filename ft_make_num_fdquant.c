/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_num_fdquant.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:31:31 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/14 16:31:33 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_pipex.h"

void	ft_make_num_fdquant(int *num, int *fd_quant, char **argv)
{
	*num = -1;
	*fd_quant = ft_fd_count(argv);
	return ;
}
