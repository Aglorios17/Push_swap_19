/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:12:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/31 17:39:41 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min(t_pile *pile)
{
	int	i;
	int	min;

	i = 0;
	min = pile->a[i];
	while (pile->a[i])
	{
		if (pile->a[i] < min)
			min = pile->a[i];
		i++;
	}
	i = 0;
	while (pile->a[i])
	{
		if (min == pile->a[i++])
			break ;
	}
	while (i > 1)
	{
		rotate(pile->a);
		ft_putstr_fd("ra\n", 1);
		i--;
	}
	push_b(pile);
	ft_putstr_fd("pb\n", 1);
	return (0);
}

int	algo(t_pile *pile)
{
	int	i;

	i = 0;
	while (pile->arg_nb_a)
		find_min(pile);
	while (pile->arg_nb_b)
	{
		push_a(pile);
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}

// Work inprogress

/*int    fill_chunk(t_pile *pile, t_data *data)
{
    int i;
    
    i = 0;
    data->min = ft_min(pile->a);
    while (i < pile->arg_nb_a)
    {
        if (data->min == pile->a[i])
        {
            data->row = i;
            break ;
        }
        i++;
    }
    i = 0;
    if (data->row > pile->arg_nb_a / 2)
    {
        while (data->row < pile->arg_nb_a)
        {
            rev_rot(pile->a);
            data->row++;
        }
        rev_rot(pile->a);
    }
    else
    {
        while (data->row)
        {
            rotate(pile->a);
            data->row--;
        }
    }
    push_b(pile);
    return (0);
}

int        algo(t_pile *pile)
{
    int i;
    t_data *data;
    
    i = 0;
    data = ft_calloc(1, sizeof(t_data));
    data->chunk_nb = 5;
    data->chunk_size = pile->arg_nb_a / data->chunk_nb;
    if (pile->arg_nb_a % data->chunk_size != 0)
        data->chunk_nb++;
    while (data->chunk_nb)
    {
        while (data->chunk_size)
        {
            fill_chunk(pile, data);
            data->chunk_size--;
        }
        data->chunk_nb--;
    }
    return (0);
}*/