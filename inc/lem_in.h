/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:06:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/04 16:38:11 by ccoupez          ###   ########.fr       */
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
	int				chosen;
	struct s_path	*next;
}					t_path;

typedef struct		s_walk
{
	int				ant;
	int				i_w[3];
}					t_walk;

/*
**  lem-in.c
*/


/*
**	ft_check_links.c
*/

t_bool			ft_check_links(t_data *data, t_lst *lst);

/*
**	ft_check_rooms.c
*/

t_bool			ft_check_rooms(t_data *data, t_lst **lst);

/*
**	ft_free_struct.c
*/

void			ft_free_tab(char **tab, int i);
void			ft_free_t_data(t_data *data);

/*
**	ft_lst.c
*/

t_bool			ft_destroy(t_lst *lst);
void			ft_free_item(t_lst **lst);
t_lst			*ft_lst_new(char *str, int passage);
void			ft_lst_pushback(t_lst **begin, t_lst *to_add);

/*
**	ft_parse.c
*/

t_bool			ft_check_int(int *value, char *str);
t_bool			ft_parse(t_data *data);

/*
**	resolve.c
*/

int     		ft_resolve(t_data *data);
int				*ft_intset(int *tab, int c, size_t n);

/*
**	ft_lst_path.c
*/

t_path	*ft_lst_path_new(int *way, int max);
void	ft_lst_path_pushback(t_path **begin, t_path *to_add);
void	ft_change_place(t_path *a, t_path *b);

/*
**	testing file
*/

void	print_values(t_path ***back);

/*
**	ft_search_ways
*/

void	ft_search_ways(t_data *data, t_path **ways);

/*
**	ft_search_best_ways.c
*/

t_bool	ft_search_best_ways(t_path *ways, t_data *data);

/*
**	testing file
*/
void	ft_print_data(t_data *data);
void	print_values(t_path ***back);
void	ft_print_struct(t_data *data);

/*
**	send_ant.c
*/
void    send_ant(t_path ***back, t_data *graph, int nb_ways);
#endif
