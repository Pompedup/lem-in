/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:44:33 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/03 17:59:57 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void	ft_print_room(t_room **rooms)
{
	while (*rooms)
	{
		ft_putendl((*rooms)->name);
		rooms++;
	}
}

void	ft_print_links(int *tab, int nb, int start)
{
	int i;

	i = 0;
	ft_putendl("");
	ft_putendl(start ? "start" : "end");
	while (i < nb)
		ft_putnbrendl(tab[i++]);
}

void	ft_print_struct(t_data *data)
{
	if (data->rooms)
		ft_print_room(data->rooms);
	if (data->start)
		ft_print_links(data->start, data->nb_start, 1);
	if (data->end)
		ft_print_links(data->end, data->nb_end, 0);
}
