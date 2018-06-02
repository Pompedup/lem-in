/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:06:51 by abezanni          #+#    #+#             */
/*   Updated: 2018/06/02 18:13:23 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define TRUE 1
# define FALSE 0

# include <fcntl.h>
# include "../../libft/libft.h"
# include <stdio.h>

typedef char	t_bool;

typedef	struct s_lst	t_lst;

struct			s_lst
{
	char		*str;
	int			type;
	t_lst		*next;
};

typedef	struct s_link
{
	char		*cmt;
	int			link;
}				t_link;

typedef struct	s_room
{
	char		*name;
	char		*cmt;
	int			num_room;
	t_link		**links;
	int			pos[2];
}				t_room;

typedef struct	s_data
{
	int			nb_rooms;
	int			nb_ant;
	int			nb_start;
	int			nb_end;
	int			*start;
	int			*end;
	t_room		**rooms;
}				t_data;


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
t_bool			ft_free_t_data(t_data *data);

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




// test_file.c
void	ft_print_struct(t_data *data);
void	ft_print_data_lst(t_lst *lst, t_data *data);
void	ft_print_data(t_data *data);
void	ft_print_rooms(t_data *data);

#endif
