/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_for_testing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:15:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/04 17:00:04 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_values(t_path ***back)
{
	int j;
	int i;
	int d;

	d = 0;
	printf("--------------------------------\n");
	while (back[d])
	{

		printf("Indice : %d\n\n", d);
		j = 0;
		while (back[d][j])
		{
			i = 0;
			while (i < back[d][j]->len)
			{
				printf("%d %s", back[d][j]->way[i], i
					< back[d][j]->len - 1 ? "-" : "");
				i++;
			}
			printf("\nways->len %d\n\n\n\n", back[d][j]->len);
			j++;
		}
		d++;
	}
}

void	ft_print_data(t_data *data)
{
	t_room	**test;
	int		i;
	int		j;

	test = data->rooms;
	i = 0;
	while (i < data->nb_rooms)
	{
		j = 0;
		printf("\nnom de la room %s\n", test[i]->name);
		printf("\ntest[i]->num_room %d\n", test[i]->num_room);
		printf("\nroom dindice  	%d\nqui a  %d link\n", i, test[i]->nb_link);
		while (j < test[i]->nb_link)
		{
			printf("\nlie a la room dindice : %d\n", test[i]->links[j++]);
			ft_putnbrendl(test[i]->links[j++]);
		}
		i++;
	}
	printf("\n\n\n");
}

void	ft_print_rooms(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_rooms)
	{
		printf("name room   %s\n", data->rooms[i]->name);
		i++;
	}
	i = 0;
	while (i < data->nb_start)
	{
		printf("\nEntree :%d\n", data->start[i++]);
		ft_putendl(data->rooms[data->start[i++]]->name);
	}
	i = 0;
	while (i < data->nb_end)
	{
		printf("Sortie :%d\n", data->end[i++]);
		ft_putendl(data->rooms[data->end[i++]]->name);
	}
}
