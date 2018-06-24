/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:06:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/24 15:33:28 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define TRUE 1
# define FALSE 0

# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef char	t_bool;

typedef	struct s_lst	t_lst;

struct				s_lst
{
	char			*str;
	int				type;
	t_lst			*next;
};

typedef struct		s_room
{
	int				num_room;
	int				nb_link;
	int				*links;
	char			*name;
	int				pos[2];
}					t_room;

typedef struct		s_data
{
	int				nb_rooms;
	int				nb_ant;
	int				nb_start;
	int				nb_end;
	int				*start;
	int				*end;
	t_room			**rooms;
	int				option;
}					t_data;

typedef struct		s_path
{
	int				*way;
	int				len;
	struct s_path	*next;
}					t_path;

typedef struct		s_walk
{
	int				ant;
	t_path			*myway;
	int				i;
	struct s_walk	*next;
}					t_walk;

/*
**	check_opti_way.c
*/

int					ft_check_opti_way(int nb_ant, t_path ***ways);

/*
**	cmd.c
*/

t_bool				cmd_valide(t_data *data, t_lst *lst, int i);

/*
**	check_double_rooms.c
*/

t_bool				ft_verif_no_double(t_room **rooms, int nbr_rooms);

/*
**	check_links.c
*/

t_bool				ft_check_links(t_data *data, t_lst *lst);

/*
**	check_option.c
*/

void				ft_check_option(t_data *data, int ac, char **av);

/*
**	check_rooms.c
*/

t_bool				ft_check_rooms(t_data *data, t_lst **lst);

/*
**	free_struct.c
*/

void				ft_print_free_lst(t_lst *lst, t_bool print);
void				ft_free_tab(char **tab, int i);
void				ft_free_t_data(t_data *data);
void				ft_free_t_path(t_path ***best_path, t_path *paths);

/*
**	lst.c
*/

t_bool				ft_destroy(t_data *data, t_lst *lst);
void				ft_free_item(t_lst **lst);
t_lst				*ft_lst_new(char *str, int passage);
void				ft_lst_pushback(t_lst **begin, t_lst *to_add);

/*
**	parse.c
*/

t_bool				ft_check_int(int *value, char *str);
t_bool				ft_parse(t_data *data, t_lst **lst);

/*
**	resolve.c
*/

t_bool				ft_resolve(t_data *data, t_lst *lst);
int					*ft_intset(int *tab, int c, size_t n);

/*
**	lst_path.c
*/

t_path				*ft_lst_path_new(int *way, int max);
void				ft_lst_path_pushback(t_path **begin, t_path *to_add);
void				ft_change_place(t_path *a, t_path *b);

/*
**	search_ways
*/

void				ft_search_ways(t_data *data, t_path **ways);

/*
**	search_best_ways.c
*/

t_path				***ft_search_best_ways(t_path *ways, t_data *data);

/*
**	verify_link.c
*/

t_bool				ft_corrects_links(t_data *data, t_lst *lst);

/*
**	send_ant.c
*/
t_bool				send_ant(t_path ***back, t_data *graph);
#endif
