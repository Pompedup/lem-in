/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:30:28 by ccoupez           #+#    #+#             */
/*   Updated: 2018/05/31 16:36:53 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**  Créé un nouvel élément de type path
*/

t_path	*ft_lst_path_new(int *way, int max)
{
	t_path	*path;
	int		len;

	len = 0;
	while (way[len] != -1 && len < max)
		len++;
	if (!(path = malloc(sizeof(t_path))))
		return (NULL);
	path->len = len;
	if (!(path->way = malloc(sizeof(int) * len)))
		return (NULL);
	len = -1;
	while (++len < path->len)
		path->way[len] = way[len];
	path->next = NULL;
	return (path);
}

/*
**  Envoie un élément a la fin de ma liste de path
*/

void	ft_lst_path_pushback(t_path **begin, t_path *to_add)
{
	t_path *tmp;

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

void	change_place(t_path *a, t_path *b)
{
	int *swap_way;
	int swap_len;

	swap_way = a->way;
	swap_len = a->len;
	a->way = b->way;
	a->len = b->len;
	b->way = swap_way;
	b->len = swap_len;
}