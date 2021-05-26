/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:53:35 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/23 06:55:44 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occur;

	last_occur = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occur = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (last_occur);
}
