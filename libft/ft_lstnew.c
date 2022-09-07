/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:23:53 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:23:55 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = malloc(sizeof (t_list));
	if (!new)
		return (0);
	new->next = 0;
	new->data = data;
	new->prev = 0;
	new->index = 0;
	return (new);
}
