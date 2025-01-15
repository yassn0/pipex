/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:38:37 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/08 12:09:59 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void *ft_memset(void *s, int c, size_t n)
{
		size_t            i;
	size_t	i;
	size_t	i;

		i = 0;
		while (i < n)
		{
			((unsigned char *)s)[i] = c;
			i++;
		}
		return (s);
}*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
		char src[20];
		char dst[20];

		ft_memset(src, 'F', 10);
		printf("%s\n", src);
		ft_memcpy(dst, src, 9);
		printf("%s\n", dst);

}*/