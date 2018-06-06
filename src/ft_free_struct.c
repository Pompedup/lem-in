/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:44:33 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/06 18:09:56 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_free_lst(t_lst *lst, t_bool print)
{
	t_lst *tmp;

	while (lst)
	{
		if (print)
			ft_putendl(lst->str);
		tmp = lst->next;
		free(lst->str);
		free(lst);
		lst = tmp;
	}
	ft_putendl("");
}

void	ft_free_tab(char **tab, int i)
{
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_free_rooms(t_room **rooms, int nb_rooms)
{
	int i;

	i = 0;
	while (i < nb_rooms)
	{
		if (rooms[i]->links)
			free(rooms[i]->links);
		free(rooms[i]->name);
		free(rooms[i]);
		i++;
	}
	free(rooms);
}

void	ft_free_t_data(t_data *data)
{
	if (data->rooms)
		ft_free_rooms(data->rooms, data->nb_rooms);
	if (data->start)
		free(data->start);
	if (data->end)
		free(data->end);
}

void	ft_free_t_path(t_path ***best_path, t_path *paths)
{
	int		i;
	t_path	*tmp;

	i = 0;
	while (best_path[i])
		free(best_path[i++]);
	free(best_path);
	while (paths)
	{
		tmp = paths->next;
		free(paths->way);
		free(paths);
		paths = tmp;
	}
}
