# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 17:20:33 by artaveti          #+#    #+#              #
#    Updated: 2023/07/21 14:30:09 by artaveti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
ARCHIVEFILE = pipex.a
HEADER = lib_for_pipex.h
SOURCES = pipex.c ft_prog_names_join.c ft_split.c ft_strchr.c\
 			ft_strjoin_space.c ft_strjoin.c ft_strlen.c ft_strl_spc.c\
  			ft_arr_count.c ft_fd_count.c ft_make_path_arr.c\
			ft_num_if_access.c ft_first_fork.c ft_last_fork.c ft_middle_fork.c\
			ft_strncmp.c get_next_line.c ft_gstrlen.c ft_gstrchr.c ft_err_argc.c\
			ft_make_and_open_pipes.c ft_fd_close.c ft_make_fdmiddle.c\
			ft_change_fdmiddle.c ft_make_num_fdquant.c ft_execve_firstfork.c\
			ft_execve_middlefork.c ft_execve_lastfork.c ft_make_file1fd.c
OBJS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)
$(NAME): $(ARCHIVEFILE)
	$(CC) $(CFLAGS) $(ARCHIVEFILE) -o $(NAME)
$(ARCHIVEFILE): $(OBJS) $(HEADER)
	$(AR) $(ARCHIVEFILE) $(OBJS)
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS) $(ARCHIVEFILE)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
