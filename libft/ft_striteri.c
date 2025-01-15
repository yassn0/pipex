/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:57:35 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/07 17:36:59 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void ft(unsigned int ind, char *c)
// {
// 	int	i;
// 	i = 0;
// 	ind = 0;
// 	while (c[i])
// 	{
// 		if (*c == 'A')
// 			*c = 'B';
// 		i++;
// 	}
// }

// int main()
// {
// 	char s[10] = "AAAk";
// 	ft_striteri(s, ft);
// 	printf("%s\n", s);
// }