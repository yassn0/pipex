/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:15:15 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 12:56:08 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*new;
	int		i;

	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
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

// int	main(void)
// {
// 	char	s1[10] = "sdfhuakfh";
// 	char	s2[10] = "swq";
// 	char	*new;

// 	new = ft_strjoin(s1, s2);
// 	printf("%s", new);
// }
