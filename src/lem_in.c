/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:13:14 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/01 15:57:05 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_struct(t_data *data)
{
	int i = 0;
	t_room *room;

	if (data)
	{
		if (data->rooms)
		{
			while (i < data->nb_rooms)
			{
				room = data->rooms[i];
				ft_putendl(room->name);
				ft_putnbrendl(room->num_room);
			//	ft_putnbrendl(room->pos[0]);
			//	ft_putnbrendl(room->pos[1]);
				i++;
			}
		}
	}
}

/*
**  Affiche une erreur
*/

int		ft_invalide_file(void)
{
	ft_putendl_fd("ERROR", 2);
	return (0);
}

/*
**  Ai-je besoin de le préciser ?
*/

int		main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		ft_putendl("usage: lem-in source_file");
		exit(0);
	}
	if (!ft_parse(av[1], &data))
		return (ft_invalide_file());
	resolve(&data);
	//ft_print_struct(&data);
	return (0);
}
