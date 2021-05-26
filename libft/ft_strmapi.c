/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 23:38:49 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/23 07:07:19 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	result = ft_strdup(s);
	if (!s || !f || !result)
		return (NULL);
	i = 0;
	while (result[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
