/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:30:28 by ccoupez           #+#    #+#             */
/*   Updated: 2018/05/31 12:14:48 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	*ft_intset(int *tab, int c, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
	{
		//printf("i %zu\n", i);
		tab[i] = c;
	}
		
	return (tab);
}

t_path	*new_lst_path(int nb_rooms)
{
	t_path	*link;

	if (!(link = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	if (!(link->way = (int *)malloc(sizeof(int) * nb_rooms + 1)))
		return (NULL);
	ft_intset(link->way, -1, nb_rooms + 1);
	link->len = 0;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

/*void	lst_path_pback(t_path_info *dlist, t_path *new)
{
	if (dlist->begin == NULL)
		dlist->begin = new;
	else
		dlist->end->next = new;
	dlist->end = new;
}*/

/*void	free_lst_path(t_path *lst)
{
	//a voir avec adrien!!
}*/