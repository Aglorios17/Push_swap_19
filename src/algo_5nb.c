/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:19:44 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/03 12:22:40 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test2(t_pile *pile)
{
	int	loop;
	int	i;

	i = 0;
	printf("pile a : ");
	if (pile->a)
	{
		for (loop = 0; loop < pile->arg_nb_a; loop++)
			printf("%d ", pile->a[loop]);
	}
	printf("\npile b : ");
	if (pile->b)
	{
		while (pile->b[i])
			i++;
		for (loop = 0; loop < i; loop++)
			printf("%d ", pile->b[loop]);
	}
	printf("\n");
}

int	find_min_5nb(t_pile *pile)
{
	int	i;
	int	min;

	min = 0;
	i = 0;
	while (i < pile->arg_nb_a)
	{
		if (pile->a[i] > pile->b[0])
		{
			min = i;
			break ;
		}
		i++;
	}	
	return (min);
}

int	ft_resort_tab(t_pile *pile)
{
	int	i;
	int	min;
	int	row;

	i = 0;
	min = pile->a[0];
	row = 0;
	while (i < pile->arg_nb_a)
	{
		if (min > pile->a[i])
		{
			min = pile->a[i];
			row = i;
		}
		i++;
	}
	if (row > 0 && row <= 2)
	{
		while (row--)
		{
			rotate(pile->a, pile->arg_nb_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	if (row > 2)
	{
		while (!(pile->a[0] == min))
		{
			rot_rot(pile->a, pile->arg_nb_a);
			ft_putstr_fd("rra\n", 1);
		}
	}
	return (0);
}

int	algo_5nb(t_pile *pile)
{
	int	i;
	int	row;
	int	min;

	i = 0;
	row = 0;
	min = 0;
	if (pile->arg_nb_a == 5)
		i = 2;
	else
		i = 1;
	while (i--)
	{
		push_b(pile);
		ft_putstr_fd("pb\n", 1);
	}
	if (pile->arg_nb_b > 1 && pile->b[0] > pile->b[1])
	{
		swap(pile->b, pile->arg_nb_b);
		ft_putstr_fd("sb\n", 1);
	}
	algo_3nba(pile->a, 3);
	while (pile->arg_nb_b)
	{
		row = find_min_5nb(pile);
		if (row == 1)
		{
			rotate(pile->a, pile->arg_nb_a);
			ft_putstr_fd("ra\n", 1);
		}
		else if (row == 2 && pile->arg_nb_a == 3)
		{
			rot_rot(pile->a, pile->arg_nb_a);
			ft_putstr_fd("rra\n", 1);
		}
		else if (row == 0 && pile->arg_nb_a == 4)
		{
			if (pile->a[0] < pile->b[0] || pile->b[0] > ft_max(pile->a)
				|| pile->b[0] < ft_min(pile->a))
				ft_resort_tab(pile);
		}
		else if (row == 2 && pile->arg_nb_a == 4)
		{
			rot_rot(pile->a, pile->arg_nb_a);
			rot_rot(pile->a, pile->arg_nb_a);
			ft_putstr_fd("rra\nrra\n", 1);
		}
		else if (row == 3 && pile->arg_nb_a == 4)
		{
			rot_rot(pile->a, pile->arg_nb_a);
			ft_putstr_fd("rra\n", 1);
		}
		push_a(pile);
		ft_putstr_fd("pa\n", 1);
	}
	ft_resort_tab(pile);
	return (0);
}
