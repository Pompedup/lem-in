/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:13:14 by abezanni          #+#    #+#             */
/*   Updated: 2018/04/25 20:08:57 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_invalide_file(void)
{
	ft_putendl("ERROR");
	return (0);
}

t_bool	ft_destroy(t_lst *lst)
{
	t_lst *tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->str);
		free(lst);
		lst = tmp;
	}
	return (FALSE);
}

t_bool	ft_get_lines(int fd, t_lst **lst, t_lst **begin, t_lst **end)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		if (!ft_strcmp("##start", line))
		{
			free(line);
			if (!get_next_line(fd, &line))
				return (ft_destroy(*lst));
			*begin = ft_lst_new(line);
			ft_lst_pushback(lst, *begin);
		}
		else if (!ft_strcmp("##end", line))
		{
			free(line);
			if (!get_next_line(fd, &line))
				return (ft_destroy(*lst));
			*end = ft_lst_new(line);
			ft_lst_pushback(lst, *end);
		}
		else
			ft_lst_pushback(lst, ft_lst_new(line));
	}
	return (TRUE);
}

t_bool	ft_parse(char *name, t_data *data)
{
	int		fd;
	t_lst	*lst;
	t_lst	*begin;
	t_lst	*end;

	fd = open(name, O_RDONLY);
	lst = NULL;
	begin = NULL;
	end = NULL;
	if (!(ft_get_lines(fd, &lst, &begin, &end)))
		return (FALSE);
	if (!begin || !end || !lst)
		return (ft_destroy(lst));
	if (!ft_check_int(&(data->nbr_ant), lst->str))
		return (ft_destroy(lst));
	if (!(ft_check_rooms(data, &lst, begin, end)))
		return (ft_destroy(lst));
	return (TRUE);
}

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
	return (0);
}
