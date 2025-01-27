/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:06:51 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/23 13:34:55 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strdup_path(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	i = i - 5;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 5;
	while (src[i])
	{
		str[j] = src[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*get_path(char **cmd_flags, char *var_path)
{
	char	**all_path;
	char	*path_slash;
	char	*path;
	int		i;

	all_path = ft_split(var_path, ':');
	i = 0;
	if (!all_path)
		return (NULL);
	while (all_path[i])
	{
		path_slash = ft_strjoin(all_path[i], "/");
		path = ft_strjoin(path_slash, cmd_flags[0]);
		free(path_slash);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		if (path)
			free(path);
		i++;
	}
	free_tab(all_path);
	if (var_path)
		free(var_path);
	return (NULL);
}

char	*path_cmd(char *command, char **envp, char **cmd_flags)
{
	char	*var_path_tmp;
	char	*var_path;
	int		i;

	i = 0;
	if (!cmd_flags)
		return (NULL);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	var_path_tmp = ft_strnstr(envp[i], "PATH", 4);
	var_path = ft_strdup_path(var_path_tmp);
	if (!var_path || !var_path_tmp)
		return (NULL);
	return (get_path(cmd_flags, var_path));
}
