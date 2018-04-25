/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:37:13 by abezanni          #+#    #+#             */
/*   Updated: 2018/04/25 18:08:02 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_lst	*ft_lst_new(char *str)
{
	t_lst *lst;

	if (!(lst = malloc(sizeof(t_lst))))
		return (NULL);
	lst->str = str;
	lst->next = NULL;
	return (lst);
}

void	ft_lst_pushback(t_lst **begin, t_lst *to_add)
{
	t_lst *tmp;

	if (!*begin)
		*begin = to_add;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_add;
	}
}
