/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:18:24 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/23 06:47:30 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	leftcat(char *s, char c)
{
	int	len;

	len = ft_strlen(s);
	while (len)
	{
		s[len] = s[len - 1];
		len--;
	}
	s[0] = c;
}

char	*ft_itoa(int n)
{
	char			*nbr;
	long			long_nb;

	nbr = malloc(sizeof(char) * 12);
	if (!nbr)
		return (NULL);
	ft_memset(nbr, 0, 12);
	long_nb = n;
	if (long_nb == 0)
	{
		nbr[0] = '0';
		nbr[1] = '\0';
		return (nbr);
	}
	if (n < 0)
		long_nb *= -1;
	while (long_nb > 0)
	{
		leftcat(nbr, (char)(long_nb % 10) + '0');
		long_nb /= 10;
	}
	if (n < 0)
		leftcat(nbr, '-');
	return (nbr);
}
