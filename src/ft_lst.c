/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:37:13 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/06 19:03:53 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**  Détruis les listes
*/

t_bool	ft_destroy(t_lst *lst)
{
	t_lst *tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->str);
		free(lst);
		lst = tmp;
	}
	return (FALSE);
}

/*
**  Libère les éléments un par un
*/

void	ft_free_item(t_lst **lst)
{
	t_lst *tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp->str);
	free(tmp);
}

/*
**  Créé un nouvel élément de type lst
*/

t_lst	*ft_lst_new(char *str, int passage)
{
	t_lst *lst;

	if (!(lst = malloc(sizeof(t_lst))))
		return (NULL);
	lst->str = str;
	lst->entrance = passage % 2;
	lst->wayout = passage / 2;
	lst->next = NULL;
	return (lst);
}

/*
**  Envoie un élément a la fin de ma liste
*/

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
