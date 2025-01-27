/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:41:28 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/27 13:42:56 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_cmd(char *av_cmd, char **envp, int fd_out)
{
	char	**cmd_flags;
	char	*path;
	int		i;

	i = -1;
	cmd_flags = ft_split(av_cmd, ' ');
	path = path_cmd(cmd_flags[0], envp, cmd_flags);
	if (!cmd_flags || !path)
	{
		if (cmd_flags)
			free_tab(cmd_flags);
		if (path)
			free(path);
		exit(1);
	}
	if (execve(path, cmd_flags, envp) == -1)
	{
		ft_putstr_fd("Error on execve\n", 1);
		exit(1);
	}
	free(path);
	free_tab(cmd_flags);
}

void	process(char *av_cmd, char **envp, int fd_in, int fd_out)
{
	pid_t	pid;
	int		fd_link[2];

	close(fd_in);
	pipe(fd_link);
	pid = fork();
	if (pid == 0)
	{
		close(fd_link[0]);
		dup2(fd_link[1], 1);
		close(fd_link[1]);
		close(fd_out);
		execute_cmd(av_cmd, envp, fd_out);
	}
	close(fd_link[1]);
	dup2(fd_link[0], 0);
	close(fd_link[0]);
	waitpid(pid, NULL, 0);
}

void	execute_last_cmd(char *av_cmd, char **envp, int fd_out)
{
	char	**cmd_flags;
	char	*path;

	cmd_flags = ft_split(av_cmd, ' ');
	path = path_cmd(av_cmd, envp, cmd_flags);
	if (!path || !cmd_flags)
	{
		if (cmd_flags)
			free_tab(cmd_flags);
		if (path)
			free(path);
		ft_putstr_fd("Error on path or cmd\n", 1);
		close(fd_out);
		exit(1);
	}
	dup2(fd_out, 1);
	close(fd_out);
	if (execve(path, cmd_flags, envp) == -1)
	{
		ft_putstr_fd("Command Error\n", 1);
		exit(1);
	}
	free(path);
	free_tab(cmd_flags);
}

void	main_case(int ac, char **av, char **envp)
{
	int	fd_out;
	int	fd_in;
	int	i;

	fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd_in = open(av[1], O_RDONLY, 0777);
	if (fd_out == -1 || fd_in == -1)
	{
		if (fd_in != -1)
			close(fd_in);
		if (fd_out != -1)
			close(fd_out);
		ft_putstr_fd("File Error\n", 1);
		exit(1);
	}
	dup2(fd_in, 0);
	dup2(fd_out, 1);
	process(av[2], envp, fd_in, fd_out);
	i = 3;
	while (i < ac - 2)
	{
		process(av[i], envp, 1, fd_out);
		i++;
	}
	execute_last_cmd(av[ac - 2], envp, fd_out);
}
