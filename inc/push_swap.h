/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:09:11 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/02 14:28:45 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_data
{
	int	min;
	int	max;
	int	row;
	int	chunk_nb;
	int	chunk_size;
	int *ref;
	int *refchunk;
}			t_data;

/* Main */

void	pile_doublons(int arg, t_pile *pile);
void	pile_arg(char *arg, t_pile *pile);
int		algo_main(t_pile *pile);

/* Operations */
int		swap(int *tab);
int		swap_ss(int *tab1, int *tab2);
int		rotate(int *pile);
int		rot_rot(int *pile);
int		rev_rot_rot(int *tab1, int *tab2);
int		push_a(t_pile *pile);
int		push_b(t_pile *pile);

/* Algo */
int		algo_main(t_pile *pile);
int		algo_3nba(int *pile, int arg_nb);
int		algo_5nb(t_pile *pile);
int		algo(t_pile	*pile);

/* Utils */
int		*ft_tabcpy(int *dest, int *src);
int		*tabncopy(int *src, int start, int end, int len);
int		*addfronttab(int *tab, int add);
int		*ft_addbacktab(int *tab, int add);
int		ft_max(int *pile);
int		ft_min(int *pile);
int		ft_row(int *tab, int find);
int		*tabncpy(int *src, int start, int end, int len);
int		occurence(int *tab, int nb, int len);


#endif
