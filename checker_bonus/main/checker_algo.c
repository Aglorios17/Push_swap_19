/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:31:50 by aglorios          #+#    #+#             */
/*   Updated: 2021/06/03 11:59:22 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int ft_cmd(t_pile *pile, char *cmd)
{
	if (!(ft_strncmp(cmd, "sa", 3)))
		swap(pile->a, pile->arg_nb_a);
	else if (!(ft_strncmp(cmd, "sb", 3)))
		swap(pile->b, pile->arg_nb_b);
	else if (!(ft_strncmp(cmd, "ss", 3)))
		swap_ss(pile->a, pile->b, pile->arg_nb_a, pile->arg_nb_b);
	else if (!(ft_strncmp(cmd, "pa", 3)))
		push_a(pile);
	else if (!(ft_strncmp(cmd, "pb", 3)))
		push_b(pile);
	else if (!(ft_strncmp(cmd, "ra", 3)))
		rotate(pile->a, pile->arg_nb_a);
	else if (!(ft_strncmp(cmd, "rb", 3)))
		rotate(pile->b, pile->arg_nb_b);
	else if (!(ft_strncmp(cmd, "rr", 3)))
	{
		rotate(pile->a, pile->arg_nb_a);
		rotate(pile->b, pile->arg_nb_b);
	}
	else if (!(ft_strncmp(cmd, "rra", 4)))
		rot_rot(pile->a, pile->arg_nb_a);
	else if (!(ft_strncmp(cmd, "rrb", 4)))
		rot_rot(pile->b, pile->arg_nb_b);
	else if (!(ft_strncmp(cmd, "rrr", 4)))
	{
		rot_rot(pile->a, pile->arg_nb_a);
		rot_rot(pile->b, pile->arg_nb_b);
	}
	else
		return (0);
	return (1);
}

void	test(t_pile *pile)
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

int	checker_algo(t_pile *pile)
{
	char *cmd;

	cmd = NULL;
	while (1)
	{
//		test(pile);
		if (get_next_linec(0, &cmd) != 0)
		{
			if (!ft_cmd(pile, cmd))
				break;
			free(cmd);
		}
	}
//	test(pile);
	if (is_sort(pile->a, pile->arg_nb_a) == -1 || pile->arg_nb_b)
	{
		ft_putstr_fd("KO\n", 1);
		return (0);
	}
	ft_putstr_fd("OK\n", 1);
	return (1);
}
