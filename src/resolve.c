/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:17:36 by ccoupez           #+#    #+#             */
/*   Updated: 2018/05/31 14:54:10 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*int		all_visited(t_data *data)
{
	int i;
	t_room **graph;

	i = 0;
	graph = data->rooms;
	while (i < data->nb_rooms)
	{
		if (graph[i]->visited == 0 && graph[i]->num_room != data->wayout[0])
			return (0);
		i++;
	}
	return (1);
}*/

/*int			on_the_way(t_path *path, int actual)
{
	int i;

	i = 0;
	while (path->way[i] != -1)
	{
		if (path->way[i] == actual)
			return(1);
		i++;
	}
	return (0);
}*/

/*t_path		*deep_course(t_data *graph, t_path_info *i_path)
{
	//int		*tab;
	int		i;
	int 	i_r;
	int 	j;
	//t_room *r;

	i_r = graph->entrance[0];
	graph->rooms[i_r]->visited = 1;
	i = 0;
	printf("end :%d\n", graph->wayout[0]);
	while(i_r != graph->wayout[0])
	{
		j = 0;
		printf("salle actuelle %d\n", graph->rooms[i_r]->num_room);
		while (j < graph->rooms[i_r]->nb_link)
		{
			//if (graph->rooms[graph->rooms[i_r]->links[j]]->visited == 0)
			//{
			//	printf("lié a la salle %d\n", graph->rooms[i_r]->links[j]);
			//}

			if (graph->rooms[i_r]->links[j] == graph->wayout[0])
			{
				printf("on a trouve la fin STOP\n");
				i_path->begin->way[i] = graph->rooms[i_r]->num_room;
				i_path->begin->len = i + 1;
				//ici repartir en recursif un cran en avant 
				//mettre le chemin davant en view et tenter un autre
				//parcours en profondeur
				//ex notre way la cest 0 1 3
				//avec la salle actuel 3 on accede a end donc
				//on revient a la salle actuel 1 et on prend pas la room 3 mais la 4 
				//et on test un nouveau chemin salle actuel 4...
				
				return (i_path->begin);
			}
			if (graph->rooms[graph->rooms[i_r]->links[j]]->num_room != i_path->begin->way[i - 1])
			{
				printf("lié a la salle %d\n", graph->rooms[i_r]->links[j]);
			}
			j++;
		}
		j = 0;
		//while (graph->rooms[graph->rooms[i_r]->links[j]]->visited != 0)
		while (on_the_way(i_path->begin, graph->rooms[i_r]->links[j]) && j < graph->rooms[i_r]->nb_link)
			j++;
		//graph->rooms[graph->rooms[i_r]->links[j]]->visited = 1;
		i_path->begin->way[i] = graph->rooms[i_r]->num_room;
		i_r = graph->rooms[i_r]->links[j];
		i++;
	}
	return (0);
}*/

/*int		course_in_width(t_data *graph, t_path_info *i_path, int *fifo)
{
	int		i;
	int		len_fifo;
	t_room	*actual;

	(void)i_path;
	len_fifo = 1; 
	while (fifo[0] != -1)
	{
		actual = graph->rooms[fifo[0]];
		printf("------actual room visited :%d \n", fifo[0]);
		actual->visited = 1;
		i = 0;
		printf("nb-links :%d \n", actual->nb_link);
		while (i < actual->nb_link)
		{
			printf("voisin :%d \n", actual->links[i]);
			if (actual->links[i] == graph->wayout[0])
				return (1);
			if (graph->rooms[actual->links[i]]->visited == 0 && actual->links[i] != graph->wayout[0])
			{
				printf("voisin non visite :%d \n", actual->links[i]);
				fifo[len_fifo++] = actual->links[i];
			}
			i++;
		}
		fifo = unmark(fifo);
		len_fifo--;
		i = 0;
		while (fifo[i] != -1)
		{
			printf("fifo[i] :%d\n", fifo[i]);
			i++;
		}
	}
	return (1);
}*/

/*int		*unmark(int *fifo)
{
	int i;

	i = 0;
	while (fifo[i] != -1)
	{
		fifo[i] = fifo[i + 1];
		i++;
	}
	return (fifo);
}

int		*mark(int *fifo, int num)
{
	int i;

	i = 0;
	while (fifo[i] != -1)
		i++;
	fifo[i] = num;
	return (fifo);
}*/


/*int	course_in_width(t_data *graph, int *fifo)
{
	int a;
	int		i;
	int		*ftmp;
	t_path 	*ways;
	t_room	*actual;

	if (fifo[0] == -1)
		return (0);
	i = 0;
	while (fifo[i] != -1)
	{
		printf("111fifo[i] :%d\n", fifo[i]);
		i++;
	}
	ways = new_lst_path(graph->nb_rooms);
	i = 0;
	while (fifo[i] != -1)
		graph->rooms[fifo[i++]]->visited = 2;
	ftmp = fifo;
	while (fifo[0] != -1 && graph->rooms[fifo[0]]->visited == 2)
	{
		printf("--------actual room :%d \n", fifo[0]);
		actual = graph->rooms[fifo[0]];
		
		i = 0;
		while (i < actual->nb_link)
		{
			if (graph->rooms[actual->links[i]]->visited == 2)
				printf("parent :%d \n", actual->links[i]);
			if (graph->rooms[actual->links[i]]->visited < 2)
				printf("enfant :%d \n", actual->links[i]);
			if (actual->links[i] == graph->wayout[0])
			{
				printf("-----------------------------wayout\n");
			//	return (1);
			}
			else if (graph->rooms[actual->links[i]]->visited == 0) // && actual->links[i] != graph->wayout[0])
			{
				printf("enfant -jamais- visité:%d \n", actual->links[i]);
				fifo = mark(fifo, actual->links[i]);
				graph->rooms[actual->links[i]]->visited = 1;
			}
			i++;
		a = 0;
		while (fifo[a] != -1)
		{
			printf("fifo[i] :%d\n", fifo[a]);
			a++;
		}
		}	
		fifo = unmark(fifo);
		i = 0;
		//while (fifo[i] != -1)
		//{
			//printf("fifo[i] :%d\n", fifo[i]);
			//i++;
	//	}
	}
	printf("------recursifff\n");
	course_in_width(graph, fifo);
	while (ftmp[i] != -1)
	{
		printf("333fifo[i] :%d\n", fifo[i]);
		i++;
	}
	printf("sortit\n");
	return (1);
}*/

void	mark(t_path *path, int num)
{
	int i;

	i = 0;
	while (path->way[i] != -1)
		i++;
	path->way[i] = num;
}

void	unmark(t_path *path)
{
	int i;

	i = 0;
	while (path->way[i] != -1)
		i++;
	path->way[i - 1] = -1;
}

int		not_on_the_way(t_path *path, int actual)
{
	int i;

	i = 0;
	while (path->way[i] != -1)
	{
	//	printf("path->way[i] %d\n", path->way[i]);
	//	printf("actual %d\n",actual);
		if (path->way[i] == actual)
		{
			printf("on the way\n");
			return(0);
		}
		i++;
	}
	printf("not  on the way\n");
	return (1);
}

int		not_visited(int *visited, int voisin)
{
	int i;

	i = 0;
	while (visited[i] != -1)
	{
	//	printf("path->way[i] %d\n", path->way[i]);
	//	printf("actual %d\n",actual);
		if (visited[i] == voisin)
		{
			printf("visited\n");
			return(0);
		}
		i++;
	}
	visited[i] = voisin;
	printf("not visited\n");
	return (1);
}

t_path	*deep_course(t_data *graph, t_path *path, t_room *room)
{
	int i;
	int j = 0;
	int a = 0;
///	int		*visited;
	t_path *new_path;

	while (a < graph->nb_rooms)
	{	
			printf("path->way[a] %d\n", path->way[a]);
			a++;
	}
	if (room == graph->rooms[graph->wayout[0]]) // ou tout mes voisin ont ete visite..
	{
		//mark(path, room->num_room);
		printf("WE FIND THE END!!!!!!!!\n");
		//while (path->way[j] != -1)
		//{
			//printf("path->way[j] :%d\n", path->way[j]);
			//j++;
		//}
		new_path = new_lst_path(graph->nb_rooms);
		path->next = new_path;
		new_path->prev = path;
		while (path->way[j] != -1)
		{
			new_path->way[j] = path->way[j];
			j++;
		}
		return (new_path);
	}
//	if (!(visited= (int *)malloc(sizeof(int) * graph->nb_rooms + 1)))
	//	return (NULL);
	//ft_intset(visited, -1, graph->nb_rooms + 1);
	i = 0;
	mark(path, room->num_room);
	while (i < room->nb_link)
	{
		printf("------------actual room %d\n", room->num_room);
		printf("-kid room %d\n", room->links[i]);
		if (not_on_the_way(path, room->links[i])) // && not_visited(visited, room->links[i]))
		{
			printf("recursiff---------->>>>>>>\n");
			path = deep_course(graph, path, graph->rooms[room->links[i]]);
		}
		i++;
	}
	printf("we have no more possibilities!!!!!!!!!!!!!!!\n");
	unmark(path);
	j = 0;
	while (path->way[j] != -1)
	{
		printf("path->way[j] :%d\n", path->way[j]);
		j++;
	}
	return (path);
}

int     resolve(t_data *data)
{
	//int			i = 0;
	//int			*fifo;
	t_path 		*ways;
	//t_path_info	i_path;

	//i_path.begin = NULL;
	//i_path.end = NULL;
	//i_path.nb_path = 0;
	//if (!(fifo = malloc(sizeof(int) * (data->nb_rooms * data->nb_rooms))))
	//	return (0);
	//ft_intset(fifo, -1, data->nb_rooms);
	//printf("heollo\n");
	ways = new_lst_path(data->nb_rooms);
	deep_course(data, ways, data->rooms[data->entrance[0]]);
	//lst_path_pback(&i_path, ways);
	//fifo[0] = data->entrance[0];
	//course_in_width(data, fifo);

//	printf("ways->len : %d\n", ways->len);
//	
//	while (i < data->nb_rooms)
//	{
//		printf("ways->way[i] : %d\n", i_path.begin->way[i]);
//		i++;
//	}
	return (0);
   
}