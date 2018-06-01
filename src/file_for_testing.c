/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_for_testing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:15:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/01 18:42:01 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_values(t_path ***back)
{
	int j;
	int i;
	int d;

	d = 0;
	while (back[d])
	{
		printf("Indice : %d\n\n\n", d);
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
			printf("\nways->len %d\n", back[d][j]->len);
			printf("\n");
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
	while (i < data->nb_entrance)
	{
		printf("\nEntree :%d\n", data->entrance[i++]);
		ft_putendl(data->rooms[data->entrance[i++]]->name);
	}
	i = 0;
	while (i < data->nb_wayout)
	{
		printf("Sortie :%d\n", data->wayout[i++]);
		ft_putendl(data->rooms[data->wayout[i++]]->name);
	}
}
