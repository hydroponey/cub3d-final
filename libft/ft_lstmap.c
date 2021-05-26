/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:20:33 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/23 19:54:27 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*new;
	t_list	*ret;
	void	*content;

	ret = NULL;
	if (lst == NULL || f == NULL)
		return (ret);
	cur = lst;
	while (cur)
	{
		content = f(cur->content);
		if (content)
		{
			new = ft_lstnew(content);
			if (!new)
			{
				ft_lstclear(&lst, del);
				return (NULL);
			}
			ft_lstadd_back(&ret, new);
		}
		cur = cur->next;
	}
	return (ret);
}
