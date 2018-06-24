/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:34:16 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/24 16:33:38 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Verifie si le fichier est sensé
*/

t_bool	ft_verify_files(t_lst *lst)
{
	if (!lst || ft_nbr_words_charset(lst->str, " \t") != 1)
		return (FALSE);
	lst = lst->next;
	if (!lst || ft_nbr_words_charset(lst->str, " \t") != 3)
		return (FALSE);
	while (lst && ft_nbr_words_charset(lst->str, " \t") == 3)
		lst = lst->next;
	while (lst && ft_nbr_words_charset(lst->str, " \t") == 1)
		lst = lst->next;
	if (lst)
		return (FALSE);
	return (TRUE);
}

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
	if ((*str == '+' && !*(str + 1))
		|| !ft_strisall(*str == '+' ? str + 1 : str, ISDIGIT))
		return (FALSE);
	*value = ft_atoi(str);
	return (TRUE);
}

/*
**	Verifie de quelle commande il s'agit et l'ajoute
*/

t_bool	ft_check_cmd(t_data *data, t_lst **lst, char *line)
{
	int type;

	type = -2;
	if (!ft_strcmp("##start", line))
	{
		type = 1;
		data->nb_start++;
	}
	else if (!ft_strcmp("##end", line))
	{
		type = 2;
		data->nb_end++;
	}
	else
		return (FALSE);
	ft_lst_pushback(lst, ft_lst_new(line, -type));
	get_next_line(0, &line);
	while (line && *line == '#')
	{
		ft_lst_pushback(lst, ft_lst_new(line, -3));
		get_next_line(0, &line);
	}
	if (line)
		ft_lst_pushback(lst, ft_lst_new(line, type));
	return (TRUE);
}

/*
**  Récupère les lignes dans une liste chainée
*/

t_lst	*ft_get_lines(t_lst *lst, t_data *data)
{
	char	*line;
	t_lst	*tmp;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strnstr(line, "##", 2))
		{
			if (!ft_check_cmd(data, &lst, line))
				ft_lst_pushback(&lst, ft_lst_new(line, -3));
		}
		else if (*line == '#')
			ft_lst_pushback(&lst, ft_lst_new(line, -3));
		else
			ft_lst_pushback(&lst, ft_lst_new(line, 0));
	}
	if ((!data->nb_start || !data->nb_end) && data->option & 1)
	{
		tmp = lst;
		while (tmp)
		{
			ft_putendl(tmp->str);
			tmp = tmp->next;
		}
	}
	return (lst);
}

/*
**  Lis le fichier envoyé en paramètre, le test et retourne les
**  données s'il est valide
*/

t_bool	ft_parse(t_data *data, t_lst **lst)
{
	t_lst	*tmp;

	if (!(*lst = ft_get_lines(*lst, data)))
		return (FALSE);
	tmp = *lst;
	if (!data->nb_start || !data->nb_end || !tmp)
		return (ft_destroy(data, *lst));
	while (*(tmp->str) == '#')
	{
		if (data->option & 1)
			ft_putendl(tmp->str);
		if ((tmp->str)[1] == '#')
			return (ft_destroy(data, *lst));
		tmp = tmp->next;
	}
	if (data->option & 1)
		ft_putendl(tmp->str);
	if (!ft_check_int(&(data->nb_ant), tmp->str))
		return (ft_destroy(data, *lst));
	tmp = tmp->next;
	if (!(ft_check_rooms(data, &tmp)))
		return (ft_destroy(data, *lst));
	if (!(ft_check_links(data, tmp)))
		return (ft_destroy(data, *lst));
	return (TRUE);
}
