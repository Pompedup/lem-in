/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:00:33 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/01 21:02:32 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**  Compte le nombre de salles
*/

int		ft_count_rooms(t_lst *lst)
{
	int		nbr_rooms;

	nbr_rooms = 0;
	while (ft_nbr_words_charset(lst->str, " \t") == 3 || *lst->str == '#')
	{
		if (*lst->str != '#')
			nbr_rooms++;
		lst = lst->next;
	}
	return (nbr_rooms);
}

/*
**	Cree les tableaux d'entree ou de sortie
*/

int		*ft_tab_start_end(t_lst *lst, int nb, int entrance)
{
	int *back;
	int i;
	int j;

	if (!(back = malloc(sizeof(int) * nb)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb)
	{
		while ((entrance ? lst->entrance : lst->wayout) == 0)
		{
			j++;
			lst = lst->next;
		}
		back[i] = j++;
		lst = lst->next;
		i++;
	}
	return (back);
}

t_bool	ft_init_data(t_data *data, t_lst **lst)
{
	if (!(data->entrance = ft_tab_start_end(*lst, data->nb_entrance, 1)))
		return (FALSE);
	if (!(data->wayout = ft_tab_start_end(*lst, data->nb_wayout, 0)))
		return (FALSE);
	if ((data->nb_rooms = ft_count_rooms(*lst)) < 2)
	{
		data->nb_rooms = 0;
		return (FALSE);
	}
	return (TRUE);
}

/*
**  Remplis une salle avec les données disponibles
*/

t_bool	ft_init_room(char *str, int i_r, t_room **room, char *cmt)
{
	char	**words;

	words = ft_split_charset(str, " \t");
	if (*words[0] == 'L' || ft_strchr(words[0], '-'))
	{
		ft_free_tab(words, 0);
		return (FALSE);
	}
	if (!(room[i_r] = malloc(sizeof(t_room))))
	{
		ft_free_tab(words, 0);
		return (FALSE);
	}
	if (!(ft_check_int(&(room[i_r]->pos[0]), words[1]) &&
		ft_check_int(&(room[i_r]->pos[1]), words[2])))
	{
		ft_free_tab(words, 0);
		return (FALSE);
	}
	room[i_r]->name = words[0];
	room[i_r]->cmt = cmt;
	room[i_r]->num_room = i_r;
	room[i_r]->nb_link = 0;
	room[i_r]->links = NULL;
	ft_free_tab(words, 1);
	return (TRUE);
}
