/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:28:24 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/27 13:25:36 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_exit_2(char **cmd_flags)
{
	free_tab(cmd_flags);
	exit(1);
}

void	help_line(int pid_child, int fd_link[2], char **cmd_flags,
		char *path_cmd)
{
	close(fd_link[1]);
	dup2(fd_link[0], 0);
	waitpid(pid_child, NULL, 0);
	free_tab(cmd_flags);
	free(path_cmd);
}

void	execute_fisrt_command_in_stdout(char **av, char **envp)
{
	int		pid_child;
	int		fd_link[2];
	char	**cmd_flags;
	char	*path_cmd_1;
	int		answer;

	cmd_flags = ft_split(av[3], ' ');
	if (!cmd_flags)
		return ;
	path_cmd_1 = path_cmd(av[3], envp, cmd_flags);
	if (!path_cmd_1)
		close_exit_2(cmd_flags);
	answer = pipe(fd_link);
	pid_child = fork();
	if (answer == -1 || pid_child == -1)
		exit(1);
	if (pid_child == 0)
	{
		close(fd_link[0]);
		dup2(fd_link[1], 1);
		execve(path_cmd_1, cmd_flags, envp);
	}
	help_line(pid_child, fd_link, cmd_flags, path_cmd_1);
}

void	execute_with_stdin(char **av, char **envp, int fd_out)
{
	char	**cmd_flags;
	char	*path_cmd_1;

	cmd_flags = ft_split(av[4], ' ');
	if (!cmd_flags)
		return ;
	path_cmd_1 = path_cmd(av[4], envp, cmd_flags);
	if (!path_cmd_1)
		close_exit_2(cmd_flags);
	execve(path_cmd_1, cmd_flags, envp);
	free_tab(cmd_flags);
	free(path_cmd_1);
	exit(1);
}
