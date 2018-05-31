#include "lem_in.h"

void	ft_print_data_lst(t_lst *lst, t_data *data)
{
	ft_putendl("");
	ft_putnbrendl(data->nb_entrance);
	ft_putnbrendl(data->nb_wayout);
	ft_putendl("");
	while (lst)
	{
		ft_putendl(lst->str);
		lst = lst->next;
	}
	ft_putendl("");
}

void	ft_print_data(t_data *data)
{
	t_room **test;
	int i;
	int j;

	test = data->rooms;
	i = 0;
	while (i < data->nb_rooms)
	{
		j = 0;
		printf("\n\n\nindice  		%d\nnb link			%d\n", i, test[i]->nb_link);
		while (j < test[i]->nb_link)
			ft_putnbrendl(test[i]->links[j++]);
		i++;
	}
}

void	ft_print_rooms(t_data *data)
{
	int i = 0;

	while (i < data->nb_rooms)
	{
		printf("%d\n%s\n\n\n\n\n", i,
		data->rooms[i]->name);
		i++;
	}
	i = 0;
	while (i < data->nb_entrance)
		printf("Entree%d\n\n\n", data->entrance[i++]);
	i = 0;
	while (i < data->nb_wayout)
		printf("Sortie%d\n\n\n", data->wayout[i++]);
}

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
				ft_putnbrendl(room->pos[0]);
				ft_putnbrendl(room->pos[1]);
				i++;
			}
		}
	}
}
