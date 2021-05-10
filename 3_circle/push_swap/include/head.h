/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:06:13 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 17:26:18 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define ERROR					0
# define SUCESS					1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX	10240
# endif
typedef int			t_bool;
# define TRUE	(1)
# define FALSE	(0)
# define NULLPTR	(0)

int		cnt; //////////////////////////////////////

typedef struct	s_list
{
	int				num;
	float			chunk;
	char			com;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct	s_inf
{
	struct s_list	*a_h;
	struct s_list	*a_t;
	struct s_list	*b_h;
	struct s_list	*b_t;
	char			bonus;
	int				max;
}				t_inf;

typedef struct	s_pivot
{
	int				first;
	int				second;
}				t_pivot;

typedef struct	s_color
{
	char			*yes;
	char			*no;
}				t_color;

/////////////////////////////////////



void			ft_checker(t_inf *inf);


int				ft_cnt_chunk(t_list *list);
t_pivot			ft_find_pivot(t_list *list);
void			ft_back_a(t_inf *inf, float chunk);
int				ft_sorted_already(t_inf *inf);
void			ft_more_a(t_inf *inf, t_pivot pivot, int cnt_chunk, float chunk);
void			ft_more_a2(t_inf *inf);
void			ft_more_b(t_inf *inf, t_pivot pivot, int cnt_chunk, float chunk);

void			ft_sorted_excpet(t_inf *inf);

void			ft_sort_a(t_inf *inf, float chunk);
void			ft_sort_a2(t_inf *inf, float chunk);

void			ft_sort_b(t_inf *inf, float chunk);
///////////////////////////////////

int				ft_action_c(t_inf *inf, char *com);
void			ft_action(t_inf *inf, char *com);
int				ft_swap_tool(t_list **type);
int				ft_push_tool(t_list **dest, t_list **src);
int				ft_rotate_tool(t_list **head, t_list **tail);
int				ft_revrotate_tool(t_list **head, t_list **tail);
void			ft_htsetting(t_inf *inf);
int				ft_isnew(t_inf *inf, int num);

int				ft_make_list(int ac, char **av, t_inf *inf);
int				ft_make_list2(t_inf *inf, char **av, int i);

int				ft_make_split(int ac, char **av, t_inf *inf);
int				ft_make_split2(t_inf *inf, char **split);

int				ft_is_num(const char *nptr);

void			ft_three_a(t_inf *inf, float chunk);
void			ft_three_b(t_inf *inf, float chunk);
void			ft_two_a(t_inf *inf, float chunk);
void			ft_two_b(t_inf *inf, float chunk);


int				ft_is_ascending(t_list *list);
int				ft_is_descending(t_list *list);
int				ft_chunk_is_descending(t_list *list);

///////////////////////////////////ft_list
t_list			*ft_n_next_list(t_list *list, int n);
t_list			*ft_listnew(int num);
void			ft_listadd_front(t_list **list, t_list **new);
void			ft_listadd_back(t_list **list, t_list **new);
void			ft_listdelone(t_list **list);
void			ft_listexcpet(t_list **list);
void			ft_listclear(t_list **list);
static int		ft_isspace(char c);
int				ft_isdigit(int c);
int				ft_sign(int sign);
int				ft_is_num(const char *nptr);

int				ft_atoi(const char *nptr);
void			ft_bubblesort(int arr[], int size);
void			ft_free(void *memory);
void			ft_free2(char **s, int i);
int				ft_max(int n, ...);
int				ft_min(int n, ...);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putchar_fd(char c, int fd, char *color);
void			ft_putnbr_fd(int n, int fd, char *color);
void			ft_putnbr_fd2(int n, int fd, char *color);
char			**ft_split(char const *s, char c);


int				ft_numlen(int num);
t_bool			ft_malloc(void *target, size_t size);

int				ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strndup(const char *s, size_t len);
char			*ft_strchr(const char *s, char c);
int				get_next_line(int fd, char **line);
void			*ft_memset(void *s, int c, int n);

///////////////////////////
void			ft_show(t_inf *inf, char *com);
void			ft_show_head(t_inf *inf, char *com);

#endif