/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:16:19 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/15 09:33:07 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*str;

	i = 0;
	str = (char *)s1;
	n_len = ft_strlen((char *)s2);
	if (n_len == 0 || s1 == s2)
		return (str);
	while (str[i] != '\0' && i < len)
	{
		c = 0;
		while (str[i + c] != '\0' && s2[c] != '\0' && str[i + c] == s2[c] && i
			+ c < len)
			c++;
		if (c == n_len)
			return (str + i);
		i++;
	}
	return (0);
}

// int main()
// {
// 	const char *str = "Bonjour Pierre gsdfgdgfk";
// 	const char *find = "Pierre";
// 	const char *new = ft_strnstr(str,find, 9);
// printf("%s\n", new);
// 	}