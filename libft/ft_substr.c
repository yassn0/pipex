/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:48:02 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/09 16:09:30 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (start + len > (long unsigned int)ft_strlen((char *)s))
		len = (size_t)ft_strlen((char *)s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main()
// {
// 	const char s[10] = "abcdef";
// 	char *dest = ft_substr(s, 1, 5);
// 	printf("%s\n", dest);
// }