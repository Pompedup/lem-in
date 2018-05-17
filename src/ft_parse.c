/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adibou <adibou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:34:16 by abezanni          #+#    #+#             */
/*   Updated: 2018/05/17 11:31:45 by adibou           ###   ########.fr       */
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

/*
**  Récupère les lignes dans une liste chainée
*/

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

void	ft_print_data_lst(t_lst *lst, t_data *data)
{
	ft_putendl("");
	ft_putnbrendl(data->nb_entrance);
	ft_putnbrendl(data->nb_wayout);
	ft_putendl("");
	while (lst)
	{
		ft_putendl(lst->str);
		lst = lst->next;
	}
	ft_putendl("");
}

void	ft_print_data(t_data *data)
{
	t_room **test;
	int i;
	int j;

	test = data->rooms;
	i = 0;
	while (i < data->nb_rooms)
	{
		j = 0;
		printf("\n\n\nindice  		%d\nnb link			%d\n", i, test[i]->nb_link);
		while (j < test[i]->nb_link)
			ft_putnbrendl(test[i]->links[j++]);
		i++;
	}
}

void	ft_print_rooms(t_data *data)
{
	int i = 0;

	while (i < data->nb_rooms)
	{
		printf("%d\n%s\n\n\n\n\n", i,
		data->rooms[i]->name);
		i++;
	}
	i = 0;
	while (i < data->nb_entrance)
		printf("Entree%d\n\n\n", data->entrance[i++]);
	i = 0;
	while (i < data->nb_wayout)
		printf("Sortie%d\n\n\n", data->wayout[i++]);
}

/*
**  Lis le fichier envoyé en paramètre, le test et retourne les
**  données s'il est valide
*/

t_bool	ft_parse(char *name, t_data *data)
{
	int		fd;
	t_lst	*lst;

	fd = open(name, O_RDONLY);
	lst = NULL;
	data->nb_rooms = 0;
	data->nb_entrance = 0;
	data->nb_wayout = 0;
	data->entrance = NULL;
	data->wayout = NULL;
	data->rooms = NULL;
	ft_putendl("WeGo");
	if (!(ft_get_lines(fd, &lst, data)))
		return (FALSE);
	ft_putendl("GetLines");
	if (!ft_verify_files(lst))
		return (ft_destroy(lst));
	ft_print_data_lst(lst, data);
	ft_putendl("Donnees correctes");
	if (!data->nb_entrance || !data->nb_wayout || !lst)
		return (ft_destroy(lst));
	ft_putendl("Entree Sortie Donnes");
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
