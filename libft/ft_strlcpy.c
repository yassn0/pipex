/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:08:42 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/09 16:12:31 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (size == 0)
		return ((size_t)ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (src[i2] != '\0')
		i2++;
	if (size > 0)
		dest[i] = '\0';
	return (i2);
}
// #include <stdio.h>

// int main()
// {
// 	char src[10] = "hello";
// 	char dest[10] = "";
// 	printf("%d\n", ft_strlcpy(dest, src, 0));
// }