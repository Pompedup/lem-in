/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:15:15 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/01 15:47:00 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Dis si la salle est dans le liens
*/

char	*ft_islinked(char *link, char *name, int len_name)
{
	char	*answer;

	if ((answer = ft_strstr(link, name)))
	{
		if (answer == link && answer[len_name] == '-')
			return (answer);
		else if (answer[-1] == '-' && answer[len_name] == '\0')
			return (answer);
	}
	return (NULL);
}

/*
**	Retourne la salle liee
*/

int		ft_reach_link(char *link, t_room **rooms, int nbr_rooms, int to_test)
{
	int		i;

	i = 0;
	while (i < nbr_rooms)
	{
		if (i != to_test)
		{
			if (ft_islinked(link, rooms[i]->name, ft_strlen(rooms[i]->name)))
				return (i);
		}
		i++;
	}
	return (-1);
}

/*
**	Je sais pu pour le moment
**	Bah en faite, ca tri cree les liens !!!!
*/

t_bool	ft_parse_link(t_lst *lst, t_room **rooms, int nbr_rooms, int to_test)
{
	int		i_tab;
	char	*pos;
	int		len;

	len = ft_strlen(rooms[to_test]->name);
	i_tab = 0;
	if (rooms[to_test]->nb_link == 0)
		return (TRUE);
	if (!(rooms[to_test]->links =
	malloc(sizeof(int) * rooms[to_test]->nb_link)))
		return (FALSE);
	while (lst && i_tab < rooms[to_test]->nb_link)
	{
		if ((pos = ft_islinked(lst->str, rooms[to_test]->name, len)))
		{
			rooms[to_test]->links[i_tab] =
			ft_reach_link(lst->str, rooms, nbr_rooms, to_test);
			i_tab++;
		}
		lst = lst->next;
	}
	return (TRUE);
}

/*
**	Teste les noms des liens pour verifier s'ils sont tous repertories
*/

t_bool	ft_verif_links_names(t_room **rooms, int nbr_rooms, char *link)
{
	int i;
	int j;
	int	dash;

	i = 0;
	while (i < nbr_rooms && !(dash =
		ft_strstrtochar(link, rooms[i]->name, '-')))
		i++;
	if (!dash)
		return (FALSE);
	rooms[i]->nb_link++;
	j = 0;
	while (j < nbr_rooms && ft_strcmp(rooms[j]->name, link + dash + 1))
		j++;
	rooms[j]->nb_link++;
	return (j == nbr_rooms || i == j ? FALSE : TRUE);
}

/*
**	Verifier si la liste est correcte
*/

t_bool	ft_corrects_links(t_data *data, t_lst *lst)
{
	while (lst)
	{
		if (!(ft_verif_links_names(data->rooms, data->nb_rooms, lst->str)))
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

/*
**	Tri un tableau d'int et precise s'il n'y a pas des doubles
*/

t_bool	ft_sort_table(int *tab, int size)
{
	int i;
	int swap;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] == tab[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
**	Cherche les liens entre les salles
*/

t_bool	ft_check_links(t_data *data, t_lst *lst)
{
	int i;

	if (!ft_corrects_links(data, lst))
		return (FALSE);
	i = 0;
	while (i < data->nb_rooms)
	{
		if (!ft_parse_link(lst, data->rooms, data->nb_rooms, i))
			return (FALSE);
		if (data->rooms[i]->nb_link > 1 &&
		!ft_sort_table(data->rooms[i]->links, data->rooms[i]->nb_link))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
