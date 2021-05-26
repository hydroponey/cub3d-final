/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:00:54 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/23 19:46:47 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*s;
	unsigned char	*d;

	if (dst == src)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	while (i < len)
	{
		if (src < dst)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
		else
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
