/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:23:09 by aglorios          #+#    #+#             */
/*   Updated: 2021/05/31 15:54:53 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../libft/inc/libft.h"
# include <stdio.h>

typedef struct s_pile
{
	int		*a;
	int		*b;
	int		arg_nb_a;
	int		arg_nb_b;
	int		first_b_malloc;
	int		first_a_malloc;
}			t_pile;

int		checker_algo(t_pile *pile);
void	arg_is_str(char *av, t_pile *pile);
void	arg_is_str2(t_pile *pile, int b, char **str);
int		is_sort(int *pile, int len);
void	pile_doublons(int arg, t_pile *pile);
void	pile_arg(char *arg, t_pile *pile);

/* Operations */
int		swap(int *tab);
int		swap_ss(int *tab1, int *tab2);
int		rotate(int *pile, int len);
int		rot_rot(int *pile, int len);
int		rev_rot_rot(int *tab1, int *tab2, int len1, int len2);
int		rev_rot(int *tab1, int *tab2, int len1, int len2);
int		push_a(t_pile *pile);
int		push_b(t_pile *pile);

/* Utils */
int		*ft_tabcpy(int *dest, int *src, int len);
int		*addfronttab(int *tab, int add, int len);
int		*ft_addbacktab(int *tab, int add, int len);

int		get_next_linec(int fd, char **line);
int		ft_strlen2c(char *str);
int		is_linec(char *save);
void	norme_gnlc(char *reste, int i, int *j, char *new);

#endif
