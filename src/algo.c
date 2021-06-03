/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:12:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/03 12:16:37 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test3(t_pile *pile)
{
	int	loop;
	int	i;

	i = 0;
	printf("\npile a : ");
	if (pile->a)
	{
		for (loop = 0; loop < pile->arg_nb_a; loop++)
			printf("%d ", pile->a[loop]);
	}
	printf("\npile b : ");
	if (pile->b)
	{
		for (loop = 0; loop < pile->arg_nb_b; loop++)
			printf("%d ", pile->b[loop]);
	}
	printf("\n");
}

int ft_pos(int *pile, int pos, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (pile[i] == pos)
			return (i);
		i++;
	}
	return (0);
}

int	push_to_b(t_pile *pile, t_data *data, int i, int j)
{
	int start;
	int end;

	i = pile->arg_nb_a + 1;
	start = ((pile->arg_nb_a / data->chunk_nb) * (j));
	end = ((pile->arg_nb_a / data->chunk_nb) * (j + 1));
	data->chunk_size = end - start;
	data->refchunk = tabncpy(data->ref, start, end, pile->arg_nb_a);
	while (i--)
	{
		if (occurence(data->refchunk, pile->a[0], data->chunk_size) == 1 )
		{
			push_b(pile);
			ft_putstr_fd("pb\n", 1);
		}
		else if (i)
		{
			rotate(pile->a, pile->arg_nb_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	return (0);
}

int	push_to_a(t_pile *pile, t_data *data, int i)
{	
	while (pile->arg_nb_b)
	{
		data->max = ft_max(pile->b);
		i = ft_pos(pile->b, data->max, pile->arg_nb_b);
		while (pile->b[0] != data->max)
		{
			if (i > pile->arg_nb_b / 2)
			{
				rot_rot(pile->b, pile->arg_nb_b);
				ft_putstr_fd("rrb\n", 1);
			}
			else
			{
				rotate(pile->b, pile->arg_nb_b);
				ft_putstr_fd("rb\n", 1);
			}
		}
		push_a(pile);
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}

int	push_to_a_last_chunk(t_pile *pile, t_data *data, int i)
{	
	while (pile->arg_nb_b)
	{
		data->min = ft_max(pile->b);
		i = ft_pos(pile->b, data->min, pile->arg_nb_b);
		while (pile->b[0] != data->min)
		{
			if (i > pile->arg_nb_b / 2)
			{
				rot_rot(pile->b, pile->arg_nb_b);
				ft_putstr_fd("rrb\n", 1);
			}
			else
			{
				rotate(pile->b, pile->arg_nb_b);
				ft_putstr_fd("rb\n", 1);
			}
		}
	//	printf("push : %i", pile->b[0]);
	//	test3(pile);
		push_a(pile);
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}

int	fill_chunk(t_pile *pile, t_data *data, int i, int j)
{
	int pos;

	pos = 0;
	push_to_b(pile, data, i, j);
	push_to_a(pile, data, i);
	i = ft_max(data->refchunk);
	while (pile->a[pile->arg_nb_a - 1] != i)
	{
		rotate(pile->a, pile->arg_nb_a);
		ft_putstr_fd("ra\n", 1);
	}
	free(data->refchunk);

	return (0);
}

int	last_chunk(t_pile *pile, t_data *data, int i)
{
	while (pile->a[0] != ft_min(pile->a))
	{
		push_b(pile);
		ft_putstr_fd("pb\n", 1);
	}
	push_to_a_last_chunk(pile, data, i);
	while (pile->a[0] != ft_min(pile->a))
	{
		rotate(pile->a, pile->arg_nb_a);
		ft_putstr_fd("ra\n", 1);
	}
	return (0);
}

int	algo(t_pile *pile)
{
	int i;
	int j;
	t_data *data;

	i = 0;
	j = 0;
	data = ft_calloc(1, sizeof(t_data));
	data->ref = 0;
	data->ref = ft_tabcpy(data->ref, pile->a, pile->arg_nb_a);
	bubble_sort(data->ref, pile->arg_nb_a);
	data->refchunk = 0;
	data->chunk_nb = 5;
	data->chunk_size = pile->arg_nb_a / data->chunk_nb;
//	if (pile->arg_nb_a % data->chunk_size == 0)
//		data->chunk_nb++;
//	printf("\n%i", data->chunk_nb);
	while (j < 5)
	{
		fill_chunk(pile, data, i, j);
		j++;
	}
	if (pile->a[0] != ft_min(pile->a))
		last_chunk(pile, data, i);
//	test3(pile);
	return (0);
}
