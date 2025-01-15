/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:17:39 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/08 13:57:12 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>

// void *ft_memset(void *s, int c, size_t n)
// {
// 		size_t	i;
// 		i = 0;
// 		while (i < n)
// 		{
// 			((unsigned char *)s)[i] = c;
// 			i++;
// 		}
// 		return (s);
// }
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const void	*tmp;

	i = 0;
	tmp = src;
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)tmp)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)tmp)[i - 1];
			i--;
		}
	}	
	return (dest);
}

// int	main(void)
// {
// 		char src[20] = "";
// 		char dest[20] = "AB";
// 		ft_memmove(&dest[1], src, 1);
// 		printf("%s\n", src);
// 		printf("%s\n", dest);
// 		char src2[20] = "";
// 		char dest2[20] = "AB";
// 		memmove(&dest2[1], src2, 1);
// 		printf("%s\n", src2);
// 		printf("%s\n", dest2);
// }