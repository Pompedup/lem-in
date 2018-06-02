/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:12:54 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/02 18:21:46 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Passes les lignes non importantes
*/

t_bool	ft_go_to_the_room(int fd, char **line, t_lst *lst)
{
	ft_strdel(line);
	while (**line == '#' && ft_strcmp("##end", *line)
		&& ft_strcmp("##start", *line))
	{
		free(*line);
		if (!get_next_line(fd, line))
			return (ft_destroy(lst));
	}
	if (ft_nbr_words_charset(*line, " \t") != 3)
		return (ft_destroy(lst));
	return (TRUE);
}

/*
**  Récupère les lignes dans une liste chainée
*/

t_bool	ft_save_comment(int fd, char **line, )
{

	return (TRUE);
}

t_bool	ft_get_lines(int fd, t_lst **lst, t_data *data)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		if (!ft_strcmp("##start", line))
		{
			if (!ft_go_to_the_room(fd, &line, *lst))
				return (FALSE);
			ft_lst_pushback(lst, ft_lst_new(line, 1));
			data->nb_entrance++;
		}
		else if (!ft_strcmp("##end", line))
		{
			if (!ft_go_to_the_room(fd, &line, *lst))
				return (FALSE);
			ft_lst_pushback(lst, ft_lst_new(line, 2));
			data->nb_wayout++;
		}
		else if (*line != '\0' && *line != '#')
			ft_lst_pushback(lst, ft_lst_new(line, 0));
		else
			free(line);
	}
	return (TRUE);
}

t_bool			ft_parse(t_data *data)
{
	t_lst	*lst;

	if (!(ft_get_lines(0, &lst, data)))
		return (ft_destroy(lst));
}
