/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:33:23 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/23 13:24:32 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**  Remplis une salle avec les données disponibles
*/

t_bool	ft_create_room(char *str, int i_r, t_room **room)
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
	if (!(ft_check_int(&(room[i_r]->pos[0]), words[1])
		&& ft_check_int(&(room[i_r]->pos[1]), words[2])))
	{
		ft_free_tab(words, 0);
		return (FALSE);
	}
	room[i_r]->name = words[0];
	room[i_r]->num_room = i_r;
	room[i_r]->nb_link = 0;
	room[i_r]->links = NULL;
	ft_free_tab(words, 1);
	return (TRUE);
}

/*
**  Compte le nombre de salles
*/

int		ft_count_rooms(t_lst *lst)
{
	int		nbr_rooms;

	nbr_rooms = 0;
	while (lst && (
		ft_nbr_words_charset(lst->str, " \t") == 3 || *lst->str == '#'))
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

int		*ft_tab_start_end(t_lst *lst, int nb, int start)
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
		while (lst->type != (start ? 1 : 2))
		{
			if (*lst->str != '#')
				j++;
			lst = lst->next;
		}
		back[i] = j++;
		lst = lst->next;
		i++;
	}
	return (back);
}

t_bool	ft_init_rooms(t_data *data, t_lst **lst)
{
	if (!(data->start = ft_tab_start_end(*lst, data->nb_start, 1)))
		return (FALSE);
	if (!(data->end = ft_tab_start_end(*lst, data->nb_end, 0)))
		return (FALSE);
	if ((data->nb_rooms = ft_count_rooms(*lst)) < 2)
	{
		data->nb_rooms = 0;
		return (FALSE);
	}
	return (TRUE);
}

/*
**  Créé la liste des salles
*/

t_bool	ft_check_rooms(t_data *data, t_lst **lst)
{
	int		i;

	if (!ft_init_rooms(data, lst))
		return (FALSE);
	if (!(data->rooms = malloc(sizeof(t_room*) * (data->nb_rooms + 1))))
		return (FALSE);
	i = 0;
	while (i < data->nb_rooms)
	{
		if (data->option & 1)
			ft_putendl((*lst)->str);
		if ((*lst)->type >= 0)
		{
			if (!ft_create_room((*lst)->str, i, data->rooms))
			{
				data->nb_rooms = i;
				return (FALSE);
			}
			i++;
		}
		*lst = (*lst)->next;
	}
	if (!lst || !ft_verif_no_double(data->rooms, data->nb_rooms))
		return (FALSE);
	return (TRUE);
}
