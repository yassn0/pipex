/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:04:20 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/20 13:37:02 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	free_tab(char **tab);
char	*path_cmd(char *command, char **envp, char **cmd_flags);
char	*get_path(char **cmd_flags, char *var_path);
void	close_exit(char **cmd_flags, int *fd_link);
void	close_exit_2(char **cmd_flags);

void	execute_with_stdin(char **av, char **envp, int fd_out);
void	execute_fisrt_command_in_stdout(char **av, char **envp);
void	limiter(char *limiter, char **av, char **envp);
void	main_case(int ac, char **av, char **envp);

#endif