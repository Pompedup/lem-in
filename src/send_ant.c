/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:39:42 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/06 17:31:35 by ccoupez          ###   ########.fr       */
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

char	*concatene(int nb, char *name)
{
	char *back;
	char *tofree;

	if (!(back = malloc(sizeof(char) * (ft_nbr_len(nb) + ft_strlen(name) + 4))))
		return (NULL);
	back[0] = 'L';
	back[1] = '\0';
	ft_strcat(back, (tofree = ft_itoa(nb)));
	free(tofree);
	ft_strcat(back, "-");
	ft_strcat(back, name);
	ft_strcat(back, " ");
	return (back);
}

void	ft_make_forward(t_data *data, t_walk **p_walks)
{
	t_walk	*walks;
	t_walk	*tmp;
	char	*print;
	char	*tmpc;
	int		i;

	print = ft_strnew(0);
	walks = *p_walks;
	while (walks)
	{
		tmpc = data->rooms[walks->myway->way[walks->i++]]->name;
		print = ft_strmjoin(print, concatene(walks->ant, tmpc), 3);
		if (walks->i == walks->myway->len)
		{
			tmp = walks;
			walks = walks->next;
			ft_remove_walk(p_walks, tmp);
		}
		else
			walks = walks->next;
	}
	i = ft_strlen(print);
	print[i - 1] = '\n';
	ft_putstr(print);
	free(print);
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

t_bool	send_ant(t_path ***back, t_data *graph)
{
	int		opti_ways;
	int		i;
	int		num_ant;
	t_walk	*walks;

	walks = NULL;
	num_ant = 0;
	while (num_ant < graph->nb_ant)
	{
		opti_ways = ft_check_opti_way(graph->nb_ant - num_ant, back);
		i = 0;
		while (i <= opti_ways)
			ft_add_ant(&walks, ++num_ant, back[opti_ways][i++]);
		ft_make_forward(graph, &walks);
	}
	while (walks)
		ft_make_forward(graph, &walks);
	return (TRUE);
}
