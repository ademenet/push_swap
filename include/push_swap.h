/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:11:14 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/19 16:47:10 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include <stdio.h> // for debugging

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define IS_INT(V) V >= INT_MIN && V <= INT_MAX

/*
** I dunno if I'm going to use those:
*/

int					g_min;
int					g_max;
int					g_pivot;

/*
** Same here, could be useful in order to call functions and/or displaying:
*/

typedef enum		e_move
{
	SA, SB, SS,
	PA, PB,
	RA, RB, RR,
	RRA, RRB, RRR
}					t_move;

/*
** This is my structure list:
*/

typedef struct		s_node
{
	int				v;
	struct s_node	*next;
}					t_node;

/*
** This help me to keep pointers and easily do operations:
*/

typedef struct		s_list
{
	int				len;
	t_node			*head;
	t_node			*tail;
}					t_list;

/*
** Lib
*/

t_list			*ft_lstnew(void);
t_list			*ft_lstappend(t_list *list, int v);
int				ft_isdigit(int c);
int				ft_strisdigit(char *s);
long			ft_atoi(const char *str);
int				ft_isascending(int a, int b);
int				ft_isdescending(int a, int b);
int				ft_issortasc(t_list *l);
int				ft_issortdes(t_list *l);
int				ft_error(void);

/*
** ft_parsing.c
*/

t_list			*ft_parsing(int ac, char **av);
int				ft_check(t_list *list, char *av);
int				ft_isint(t_list *list, char *av);
int				ft_isunique(t_list *list, int v);

/*
** ft_operations.c
*/

void			ft_swap(t_list *l);
void			ft_push_a(t_list *la, t_list *lb);
void			ft_push_b(t_list *la, t_list *lb);
void			ft_rotate(t_list *l);
void			ft_revrotate(t_list *l);

/*
** ft_solving.c
*/

// void			ft_quicksort(t_list *la, t_list *lb);
void			ft_sort_a(t_list *la);
// void			ft_sort_b(t_list *lb);
int				ft_findmax(t_list *l);

int				ft_printf(const char *format, ...);

/*
** Debug - to be cleaned
*/

void			print_la(t_list *l);
void			print_lb(t_list *l);

#endif
