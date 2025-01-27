/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:19:16 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/22 13:54:26 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*clean_stock(char **stock)
{
	if (stock && *stock)
	{
		free(*stock);
		*stock = NULL;
	}
	return (NULL);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		len;
	char	*new;
	int		i;

	i = 0;
	len = ft_strlen_i((char *)s1) + ft_strlen_i((char *)s2);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s1 && *s1)
		new[i++] = *s1++;
	while (s2 && *s2)
		new[i++] = *s2++;
	new[len] = '\0';
	return (new);
}

int	is_in(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line2(char **stock, char **tmp)
{
	char	*line;

	if (!(*stock) || !(**stock))
		return (clean_stock(stock));
	line = ft_getline(*stock);
	if (!line)
		return (clean_stock(stock));
	*tmp = *stock;
	*stock = ft_keep_after(*tmp);
	free(*tmp);
	tmp = NULL;
	if (!line)
		clean_stock(stock);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*tmp;
	int			nb_byte;
	char		buffer[BUFFER_SIZE + 1];

	nb_byte = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (clean_stock(&stock));
	while (nb_byte > 0)
	{
		nb_byte = read(fd, buffer, BUFFER_SIZE);
		if (nb_byte < 0)
			return (clean_stock(&stock));
		buffer[nb_byte] = '\0';
		tmp = stock;
		stock = ft_strjoin(tmp, buffer);
		if (tmp)
			free(tmp);
		if (!stock)
			return (clean_stock(&stock));
		if (is_in(stock))
			break ;
	}
	return (get_next_line2(&stock, &tmp));
}

// int	main(int argc, char **argv)
// {
// 	int fd;
// 	char *line;
// 	(void)argc;

// 	fd = open(argv[1], O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }