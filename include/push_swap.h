/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:11:14 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/26 18:54:53 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include <stdio.h> // for debugging
# define DB(A) printf("%d\n", A);
# define DS(S) printf("%s\n", S);

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define IS_INT(V) V >= INT_MIN && V <= INT_MAX
# define DP 6

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
** For dynamic programing, we going to need this specific structure:
*/

typedef struct		s_dyn
{
	int				mv[DP];
	int				size;
	int				nb;
}					t_dyn;

/*
** Lib
*/

t_list				*ft_lstnew(void);
t_list				*ft_lstappend(t_list *list, int v);
void				ft_lstdellastone(t_list *l);
int					ft_isdigit(int c);
int					ft_strisdigit(char *s);
long				ft_atoi(const char *str);
int					ft_isascending(int a, int b);
int					ft_isdescending(int a, int b);
int					ft_issortasc(t_list *l);
int					ft_issortdes(t_list *l);
int					ft_error(void);
long				ft_power(int nb, int exp);

/*
** ft_parsing.c
*/

t_list				*ft_parsing(int ac, char **av);
int					ft_check(t_list *list, char *av);
int					ft_isint(t_list *list, char *av);
int					ft_isunique(t_list *list, int v);

/*
** ft_operations.c
*/

t_list				*ft_swap(t_list *l, t_list *mv, int ab);
t_list				*ft_push_a(t_list *la, t_list *lb, t_list *mv);
t_list				*ft_push_b(t_list *la, t_list *lb, t_list *mv);
t_list				*ft_rotate(t_list *l, t_list *mv, int ab);
t_list				*ft_revrotate(t_list *l, t_list *mv, int ab);

/*
** ft_dynamicalgorithm.c
*/

t_list				*ft_dyn_clean(t_list *l, t_list *mv);
t_list				*ft_dyn_selectmove(t_list *l, t_list *mv);
t_list				*ft_dyn_copy(t_list *mv, t_list *sol);
int					ft_dyn_explore(t_list *l, t_list *mv, t_list *sol, long count);
t_list				*ft_dyn_resolve(t_list *l, t_list *mv);

/*
** ft_sortcocktail.c
*/

t_list				*ft_sortcocktail_a(t_list *l, t_list *mv);

/*
** ft_sortmin.c
*/

int					ft_findmin(t_list *l);
t_list				*ft_sortmin(t_list *la, t_list *lb, t_list *mv);

/*
** ft_optimization.c
*/

int					ft_locateit(t_list *l, int min);
t_list				*ft_isreverse(t_list *l, t_list *mv);

/*
** ft_display.c
*/

void				ft_display(t_list *mv);

/*
** Guests and bonus
*/

int					ft_printf(const char *format, ...);
void				ft_print_la(t_list *l);
void				ft_print_lb(t_list *l);

#endif
