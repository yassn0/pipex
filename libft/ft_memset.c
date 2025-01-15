/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:09:12 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/07 07:08:09 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
		char buffer[21];
		char *string;

   ft_memset(buffer, 0, sizeof(buffer));
   string = (char *)ft_memset(buffer,'A', 10);
   printf("\nBuffer contents: %s\n", string);
   ft_memset(buffer+10, 'B', 10);
   printf("\nBuffer contents: %s\n", buffer);
}*/