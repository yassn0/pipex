/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:39:40 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/08 12:27:51 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

// char ft(unsigned int ind, char c)
// {
// 	c = 'A';
// 	ind = 0;
// 	return (c);
// }
// int main()
// {
// 	char s[10] = "Helloo";
// 	printf("%s\n", ft_strmapi(s, ft));
// }