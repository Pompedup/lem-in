/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:33:23 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/06 19:00:24 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Teste les noms et les positions
*/

t_bool	ft_check_name_and_pos(t_room *room, t_room **rooms, int nbr_rooms)
{
	int i;

	i = 0;
	while (i < nbr_rooms)
	{
		if (!ft_strcmp(room->name, rooms[i]->name))
			return (FALSE);
		if (room->pos[0] == rooms[i]->pos[0]
			&& room->pos[1] == rooms[i]->pos[1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
**	Verifie qu'il n'y a aucune salle avec le meme nom ou les memes positions
*/

t_bool	ft_verif_no_double(t_room **rooms, int nbr_rooms)
{
	int i;

	i = 0;
	while (i < nbr_rooms - 1)
	{
		if (!ft_check_name_and_pos(rooms[i], rooms + i + 1, nbr_rooms - i - 1))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
**  Remplis une salle avec les données disponibles
*/

t_bool	ft_init_room(char *str, int i_r, t_room **room)
{
	char	**words;

	words = ft_split_charset(str, " \t");
	if (*words[0] == 'L')
		return (FALSE);
	if (!(room[i_r] = malloc(sizeof(t_room))))
		return (FALSE);
	if (!(ft_check_int(&(room[i_r]->pos[0]), words[1]) &&
		ft_check_int(&(room[i_r]->pos[1]), words[2])))
		return (FALSE);
	room[i_r]->name = words[0];
	room[i_r]->num_room = i_r;
	free(words[1]);
	free(words[2]);
	free(words);
	return (TRUE);
}

/*
**  Compte le nombre de salles
*/

int		ft_count_rooms(t_lst *lst)
{
	int		nbr_rooms;

	nbr_rooms = 0;
	while (ft_nbr_words_charset(lst->str, " \t") == 3)
	{
		nbr_rooms++;
		lst = lst->next;
	}
	return (nbr_rooms);
}

/*
**	Cree les tableaux d'entree ou de sortie
*/

int		*ft_table_entrance_wayout(t_lst *lst, int nb, int entrance)
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
		back[i] = j;
		lst = lst->next;
		i++;
	}
	return (back);
}

/*
**  Créé la liste des salles
*/

t_bool	ft_check_rooms(t_data *data, t_lst **lst)
{
	int		i;

	ft_free_item(lst);
	if (!(data->entrance =
		ft_table_entrance_wayout(*lst, data->nb_entrance, 1)))
		return (FALSE);
	if (!(data->wayout = ft_table_entrance_wayout(*lst, data->nb_wayout, 0)))
		return (FALSE);
	if ((data->nbr_rooms = ft_count_rooms(*lst)) < 2)
		return (FALSE);
	if (!(data->rooms = malloc(sizeof(t_room*) * data->nbr_rooms)))
		return (FALSE);
	i = 0;
	while (i < data->nbr_rooms)
	{
		ft_init_room((*lst)->str, i, data->rooms);
		ft_free_item(lst);
		i++;
	}
	if (!ft_verif_no_double(data->rooms, data->nbr_rooms))
		return (FALSE);
	return (TRUE);
}
