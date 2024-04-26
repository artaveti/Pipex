/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_for_pipex.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:33:48 by artaveti          #+#    #+#             */
/*   Updated: 2023/07/14 17:07:35 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FOR_PIPEX_H
# define LIB_FOR_PIPEX_H

# include <unistd.h> // execve(); pipe(); fork(); dup(); dup2();
					//close(); read(); access(); write(); unlink();
# include <stdlib.h> // exit(); malloc(); free();
# include <stdio.h> // perror();
# include <sys/wait.h> // wait(); waitpid();
# include <fcntl.h> // open();
# include <errno.h> // perror(); errno;
# include <string.h> // strerror();

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct Variables
{
	int		num;
	int		fd_quant;
	int		*fd_middle;
	int		**fd;
	char	**path_arr;
	int		file1_fd;
	int		file2_fd;
	int		first_fork;
	int		last_fork;
	int		middle_fork;
	char	**argv_for_execve;
	char	**prog_paths;
}	t_variables;

char	**ft_split(char const	*s, char c);
char	*ft_strchr(const char	*s, int c);
char	*ft_strjoin(char const	*s1, char const	*s2);
size_t	ft_strlen(const	char	*s);
size_t	ft_strncmp(const char	*s1, const char	*s2, size_t	n);
char	**ft_prog_names_join(char	**path_arr, char	*prog_name);
size_t	ft_strl_spc(const char	*s);
char	*ft_strjoin_space(char const	*s1, char const	*s2);
int		ft_arr_count(char	**array);
int		ft_fd_count(char	**argv);
char	**ft_make_path_arr(char	**envp);
int		ft_num_if_access(char	**prog_paths);
int		ft_first_fork(int **fd, char **path_arr, char **argv, char **envp);
int		ft_last_fork(int **fd, char **path_arr, char **argv, char **envp);
int		ft_middle_fork(int **fd, int *fd_middle, char **argv, char **envp);
char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_get_line(char	*left_str);
char	*ft_new_left_str(char	*left_str);
size_t	ft_gstrlen(char	*s);
char	*ft_gstrchr(char *s, int c);
void	ft_err_argc(int argc, char **argv);
int		**ft_make_and_open_pipes(int fd_quant);
void	ft_fd_close(int **fd, int fd_quant);
int		*ft_make_fdmiddle(void);
void	ft_change_fdmiddle(int **fd, int *fd_middle, char **argv, int num);
void	ft_make_num_fdquant(int *num, int *fd_quant, char **argv);
void	ft_execve_firstfork(char **path_arr, char **argv, char **envp);
void	ft_execve_middlefork(int *fd_middle, char **argv, char **envp);
void	ft_execve_lastfork(int argc_in_lf, char **path_arr,
			char **argv, char **envp);
void	ft_make_file1fd(int *file1_fd, char **argv);

#endif
