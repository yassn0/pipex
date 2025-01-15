/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:08:06 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 16:55:46 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_i(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_getline(char *stock)
{
	int		i;
	int		j;
	int		len_line;
	char	*line;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		len_line = i + 1;
	else
		len_line = i;
	line = malloc(len_line + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stock[j];
		j++;
	}
	if (stock[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_keep_after(char *stock)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\0')
		return (NULL);
	i++;
	dst = malloc(ft_strlen(stock) - i + 1);
	if (!dst)
		return (NULL);
	while (stock[i])
		dst[j++] = stock[i++];
	dst[j] = '\0';
	return (dst);
}
