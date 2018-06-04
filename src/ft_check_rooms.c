/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:33:23 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/04 16:31:36 by ccoupez          ###   ########.fr       */
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
	if (!(ft_check_int(&(room[i_r]->pos[0]), words[1]) &&
		ft_check_int(&(room[i_r]->pos[1]), words[2])))
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
	if (!ft_verif_no_double(data->rooms, data->nb_rooms))
		return (FALSE);
	return (TRUE);
}
