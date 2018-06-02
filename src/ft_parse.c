/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:12:54 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/02 18:22:30 by abezanni         ###   ########.fr       */
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
**Enregistre les commentaires
*/

t_bool	ft_save_comment(int fd, char **line, t_lst **lst)
{
  char *cmt;
  t_bool hash;
  
  if (!ft_strcmp("##start", *line) || !ft_strcmp("##end", *line))
      return (FALSE);
  cmt = *line;
  hash = TRUE;
  while (hash)
  {
    if (!get_next_line(fd, line))
      return (FALSE);
    if (!ft_strcmp("##start", *line) || !ft_strcmp("##end", *line))
      return (TRUE);
    if (**line == '#')
      ft_strmjoin(cmt, *line, 3);
    else
      hash = FALSE;
  }
  ft_lst_pushback(lst, ft_lst_new(cmt, 3));
	return (TRUE);
}

int ft_type(char *line)
{
	if (!ft_strcmp("##start", line))
		return (1);
	else if (!ft_strcmp("##end", line))
		return (2);
	else if (*line == '#')
		return (3);
	else
		return (0);
}

/*
**  Récupère les lignes dans une liste chainée
*/

t_bool	ft_get_lines(int fd, t_lst **lst, t_data *data)
{
	char *line;
	int type;

	while (get_next_line(fd, &line))
	{
		type = ft_type(line);
		if (type == 3)
		{
			if (!ft_save_comment(int fd, char **line, t_lst **lst))
				return (FALSE);
			type = ft_type(line);
		}
		if (type == 1 || type == 2)
		{
			if (type == 1)
              data->nb_start++;
          	else
              data->nb_end++;
			free(line);
			if (!get_next_line(fd, &line))
				return (FALSE);
		}
		ft_lst_pushback(lst, ft_lst_new(line, type));
	}
	return (TRUE);
}

t_bool			ft_parse(t_data *data)
{
	t_lst	*lst;

	if (!(ft_get_lines(0, &lst, data)))
		return (ft_destroy(lst));
}
