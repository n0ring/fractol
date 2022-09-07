/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:23:48 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:23:50 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*next;
	t_list	*newlst;
	t_list	*newel;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		next = lst->next;
		newel = ft_lstnew((*f)(lst->data));
		if (!newel)
		{
			ft_lstclear(&newlst);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newel);
		lst = next;
	}
	return (newlst);
}
