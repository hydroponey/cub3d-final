/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:21:10 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/23 20:01:19 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*empty_str(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	const char		*end;
	size_t			len;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (empty_str());
	while (*s1 != '\0' && is_in_set(*s1, set))
		s1++;
	len = ft_strlen(s1);
	end = s1 + len;
	while (len > 0 && is_in_set(s1[len-- - 1], set))
		end = s1 + len;
	if (end < s1)
		len = 1;
	else
		len = end - s1 + 1;
	trimmed = (char *)malloc(sizeof(char) * len);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1, len);
	return (trimmed);
}
