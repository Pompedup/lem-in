/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:39:42 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/04 18:11:03 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_remove_walk(t_walk **p_walks, t_walk *walks)
{
	t_walk *tmp;

	if (*p_walks == walks)
		*p_walks = walks->next;
	else
	{
		tmp = *p_walks;
		while (tmp->next != walks)
			tmp = tmp->next;
		tmp->next = walks->next;
	}
	free(walks);
}

void	ft_make_forward(t_data *data, t_walk **p_walks)
{
	t_walk *walks;
	t_walk *tmp;

	walks = *p_walks;
	while (walks)
	{
		printf("L%d-%s ", walks->ant, data->rooms[walks->myway->way[walks->i++]]->name);
		if (walks->i == walks->myway->len)
		{
			tmp = walks;
			walks = walks->next;
			ft_remove_walk(p_walks, tmp);
		}
		else
			walks = walks->next;
	}
	printf("\n");
}

t_bool	ft_add_ant(t_walk **walk, int nb, t_path *way)
{
	t_walk *to_add;
	t_walk *tmp;

	if (!(to_add = malloc(sizeof(t_walk))))
		return (FALSE);
	to_add->ant = nb;
	to_add->myway = way;
	to_add->i = 1;
	to_add->next = NULL;
	if (!(*walk))
		*walk = to_add;
	else
	{
		tmp = *walk;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_add;
	}
	return (TRUE);
}

int		ft_check_opti_way(int nb_ant, t_path ***ways)
{
	(void)ways;
	if (nb_ant == 1)
		return (0);
	return (0);
}

t_bool   send_ant(t_path ***back, t_data *graph)
{
	int		opti_ways;
	int		i;
	int		num_ant;
	t_walk	*walks;

	walks = NULL;
	num_ant = 0;
	int j = 1;
	while (num_ant < graph->nb_ant)
	{
		opti_ways = ft_check_opti_way(graph->nb_ant - num_ant, back);
		i = 0;
		while (i <= opti_ways)
			ft_add_ant(&walks, ++num_ant, back[opti_ways][i++]);
		printf("%d\n", j++);
		ft_make_forward(graph, &walks);
	}
	while (walks)
	{
		printf("%d\n", j++);
		ft_make_forward(graph, &walks);
	}
	return (TRUE);
}
