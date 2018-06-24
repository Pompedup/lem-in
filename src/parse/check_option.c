/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:18:53 by ccoupez           #+#    #+#             */
/*   Updated: 2018/06/24 15:23:03 by ccoupez          ###   ########.fr       */
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
