/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:13:14 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/06 18:17:10 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit(char c)
{
	char print[2];
	char *tofree;

	if (c)
	{
		print[0] = c;
		print[1] = '\0';
		ft_putendl((tofree = ft_strjoin("lem-in: illegal option -- ", print)));
		free(tofree);
	}
	ft_putendl("usage: ./lem-in [-e] < file");
	exit(0);
}

void	ft_add_option(char c, t_data *data)
{
	int add;

	add = 0;
	if (c == 'e')
		add = 1;
	if (!(data->option & add))
		data->option += add;
}

void	ft_check_option(t_data *data, int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		if (*av[i] != '-')
			ft_exit('\0');
		j = 1;
		while (av[i][j])
		{
			if (!ft_strchr("e", av[i][j]))
				ft_exit(av[i][j]);
			else
				ft_add_option(av[i][j], data);
			j++;
		}
		i++;
	}
}

void	ft_init_struct(t_data *data)
{
	data->nb_rooms = 0;
	data->nb_start = 0;
	data->nb_end = 0;
	data->start = NULL;
	data->end = NULL;
	data->rooms = NULL;
	data->option = 0;
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

	ft_init_struct(&data);
	if (ac > 1)
		ft_check_option(&data, ac, av);
	if (!ft_parse(&data))
		return (ft_invalide_file());
	ft_resolve(&data);
	return (0);
}
