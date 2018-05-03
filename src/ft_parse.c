/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:34:16 by abezanni          #+#    #+#             */
/*   Updated: 2018/04/30 16:13:31 by adibou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**  Verifie si c'est un int positif
*/

t_bool	ft_check_int(int *value, char *str)
{
	int		len;
	len = ft_strlen(str);
	if ((*str != '+' && len > 10) || len > 11 || len == 0)
		return (FALSE);
	if (len > 9 && ft_strcmp(*str == '+' ? str + 1 : str, "2147483647") > 0)
		return (FALSE);
	if ((*str == '+' && !*(str + 1)) ||
		!ft_strisall(*str == '+' ? str + 1 : str, ISDIGIT))
		return (FALSE);
	*value = ft_atoi(str);
	return (TRUE);
}

/*
**	Enregistre le begin ou le end
*/

t_bool	ft_register_b_or_e(t_lst **lst, t_lst **b_or_e, char *line, int fd)
{
	free(line);
	if (!get_next_line(fd, &line))
		return (ft_destroy(*lst));
	if (ft_nbr_words_charset(line, " \t") != 3)
	{
		free(line);
		return (ft_destroy(*lst));
	}
	*b_or_e = ft_lst_new(line);
	ft_lst_pushback(lst, *b_or_e);
	return (TRUE);
}

/*
**  Récupère les lignes dans une liste chainée
*/

t_bool	ft_get_lines(int fd, t_lst **lst, t_lst **begin, t_lst **end)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		if (!ft_strcmp("##start", line))
		{
			if (!(ft_register_b_or_e(lst, begin, line, fd)))
				return (FALSE);
		}
		else if (!ft_strcmp("##end", line))
		{
			if (!(ft_register_b_or_e(lst, end, line, fd)))
				return (FALSE);
		}
		else if (*line == '#')
			free(line);
		else
			ft_lst_pushback(lst, ft_lst_new(line));
	}
	return (TRUE);
}

/*
**  Lis le fichier envoyé en paramètre, le test et retourne les
**  données s'il est valide
*/

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
	if (!(ft_check_rooms(data, &lst, &begin, &end)))
		return (ft_destroy(lst));
	if (begin || end)
		return (ft_destroy(lst));
	return (TRUE);
}