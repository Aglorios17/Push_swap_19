/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:27:24 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/26 18:57:38 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	max_handlera(int *pile)
{
	int	i;
	int	row;
	int	max;

	i = 0;
	row = 0;
	max = pile[i];
	while (pile[i])
	{
		if (max < pile[i])
		{
			max = pile[i];
			row = i;
		}
		i++;
	}
	if (row == 0)
	{
		rotate(pile);
		ft_putstr_fd("ra\n", 1);
	}
	if (row == 1)
	{
		rot_rot(pile);
		ft_putstr_fd("rra\n", 1);
	}
	return (0);
}

int	min_handlera(int *pile)
{
	int	i;
	int	row;
	int	min;

	i = 0;
	row = 0;
	min = pile[i];
	while (pile[i])
	{
		if (min > pile[i])
		{
			min = pile[i];
			row = i;
		}
		i++;
	}
	if (row == 1)
	{
		swap(pile);
		ft_putstr_fd("sa\n", 1);
	}
	return (0);
}

int	algo_3nba(int *pile, int arg_nb)
{
	if (arg_nb == 1)
		return (0);
	if (arg_nb == 2)
	{
		if (pile[0] > pile[1])
		{
			swap(pile);
			ft_putstr_fd("sa\n", 1);
		}
		else
			return (0);
	}
	if (arg_nb == 3)
	{
		max_handlera(pile);
		min_handlera(pile);
	}
	return (0);
}
