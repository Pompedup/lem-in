/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:34:16 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/03 15:44:26 by abezanni         ###   ########.fr       */
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
	free(str);
	return (TRUE);
}

/*
**	Passes les lignes non importantes
*/

t_bool	ft_go_to_the_room(int fd, char **line, t_lst *lst)
{
	*(*line + 1) = 0;
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

t_bool	ft_get_ants(t_data *data, char *line)
{
	if (ft_check_int(data->nb_ant))
		return (FALSE);
	return (TRUE);
}

/*
**  Récupère les lignes dans une liste chainée
*/

t_bool	ft_get_lines(t_lst **lst, t_data *data, int step)
{
	char *line;

	while (get_next_line(0, &line))
	{
		ft_putendl(line);
		if (step == 0 && !ft_check_int(data->nb_ant, line))
			return (FALSE);
		else if (step == 1)
	}
	return (TRUE);
}



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


/*
**  Lis le fichier envoyé en paramètre, le test et retourne les
**  données s'il est valide
*/

t_bool	ft_parse(char *name, t_data *data)
{
	int		fd;
	int		step;
	t_lst	*lst;

	step = 0;
	lst = NULL;
	data->nb_rooms = 0;
	data->nb_entrance = 0;
	data->nb_wayout = 0;
	data->entrance = NULL;
	data->wayout = NULL;
	data->rooms = NULL;
	//ft_putendl("WeGo");
	if (!(ft_get_lines(&lst, data, step)))
		return (ft_destroy(lst));
	//ft_putendl("GetLines");
	//if (!ft_verify_files(lst))
	//	return (ft_destroy(lst));
	//ft_print_data_lst(lst, data);
	//ft_putendl("Donnees correctes");







	if (!data->nb_entrance || !data->nb_wayout || !lst)
		return (ft_destroy(lst));
	//ft_putendl("Entree Sortie Donnes");
	if (!ft_check_int(&(data->nb_ant), lst->str))
		return (ft_destroy(lst));
	ft_putendl("Les fourmiiiiies");
	if (!(ft_check_rooms(data, &lst)))
		return (ft_destroy(lst));
	ft_print_rooms(data);
	ft_putendl("Les salles sont pretes");
	ft_print_data_lst(lst, data);
	if (!(ft_check_links(data, lst)))
		return (ft_destroy(lst));
	ft_print_data(data);
	ft_putendl("Les salles sont pretes");
	return (TRUE);
}
