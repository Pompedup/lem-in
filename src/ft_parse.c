/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:34:16 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/06 14:42:34 by abezanni         ###   ########.fr       */
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
	if ((*str == '+' && !*(str + 1)) ||
		!ft_strisall(*str == '+' ? str + 1 : str, ISDIGIT))
		return (FALSE);
	*value = ft_atoi(str);
	return (TRUE);
}

/*
**	Verifie de quelle commande il s'agit et l'ajoute
*/

void	ft_check_cmd(t_data *data, t_lst **lst, char *line)
{
	int type;

	type = -2;
	ft_lst_pushback(lst, ft_lst_new(line, -1));
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
	get_next_line(0, &line);
	ft_lst_pushback(lst, ft_lst_new(line, type));
}

/*
**  Récupère les lignes dans une liste chainée
*/

t_lst	*ft_get_lines(t_lst *lst, t_data *data)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (ft_strnstr(line, "##", 2))
			ft_check_cmd(data, &lst, line);
		else if (*line == '#')
			ft_lst_pushback(&lst, ft_lst_new(line, -1));
		else
			ft_lst_pushback(&lst, ft_lst_new(line, 0));
	}
	return (lst);
}

/*
**  Lis le fichier envoyé en paramètre, le test et retourne les
**  données s'il est valide
*/

t_bool	ft_parse(t_data *data)
{
	t_lst	*lst;
	t_lst	*save_first;

	lst = NULL;
	if (!(lst = ft_get_lines(lst, data)))
		return (FALSE);
	save_first = lst;
	if (!data->nb_start || !data->nb_end || !lst)
		return (ft_destroy(save_first));
	if (data->option & 1)
		ft_putendl(lst->str);
	if (!ft_check_int(&(data->nb_ant), lst->str))
		return (ft_destroy(save_first));
	lst = lst->next;
	if (!(ft_check_rooms(data, &lst)))
		return (ft_destroy(save_first));
	if (!(ft_check_links(data, lst)))
		return (ft_destroy(save_first));
	ft_print_free_lst(save_first, !(data->option & 1));
	return (TRUE);
}
