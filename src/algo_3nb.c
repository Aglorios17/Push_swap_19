/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:27:24 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/12 13:51:08 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	row_handler(int *pile, int row, int len)
{
	if (row == 0)
	{
		rotate(pile, len);
		ft_putstr_fd("ra\n", 1);
	}
	if (row == 1)
	{
		rot_rot(pile, len);
		ft_putstr_fd("rra\n", 1);
	}
}

int	max_handlera(int *pile, int len)
{
	int	i;
	int	row;
	int	max;

	i = 0;
	row = 0;
	max = pile[i];
	while (i < len)
	{
		if (max < pile[i])
		{
			max = pile[i];
			row = i;
		}
		i++;
	}
	row_handler(pile, row, len);
	return (0);
}

int	min_handlera(int *pile, int len)
{
	int	i;
	int	row;
	int	min;

	i = 0;
	row = 0;
	min = pile[i];
	while (i < len)
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
		swap(pile, len);
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
			swap(pile, arg_nb);
			ft_putstr_fd("sa\n", 1);
		}
		else
			return (0);
	}
	if (arg_nb == 3)
	{
		max_handlera(pile, arg_nb);
		min_handlera(pile, arg_nb);
	}
	return (0);
}
