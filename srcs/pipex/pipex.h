/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:32:19 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/16 17:15:57 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

char	*ft_strdup_path(char *src);
void	free_tab(char **tab);
char	*path_cmd(char *command, char **envp, char **cmd_flags);
char	*get_path(char **cmd_flags, char *var_path);
void	close_exit(char **cmd_flags, int *fd_link);

#endif