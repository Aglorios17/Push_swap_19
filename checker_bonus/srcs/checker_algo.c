/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:31:50 by aglorios          #+#    #+#             */
/*   Updated: 2021/06/10 20:05:55 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_cmd_2(t_pile *pile, char *cmd)
{
	if (!(ft_strncmp(cmd, "ra", 3)))
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

int	ft_cmd(t_pile *pile, char *cmd)
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
	else if (!ft_cmd_2(pile, cmd))
		return (0);
	return (1);
}

int	checker_algo(t_pile *pile)
{
	char	*cmd;

	cmd = NULL;
	while (1)
	{
		if (get_next_linec(0, &cmd) != 0)
		{
			if (!ft_cmd(pile, cmd))
				break ;
			free(cmd);
		}
	}
	free(cmd);
	if (is_sort(pile->a, pile->arg_nb_a) == -1 || pile->arg_nb_b)
	{
		ft_putstr_fd("KO\n", 1);
		return (0);
	}
	ft_putstr_fd("OK\n", 1);
	return (1);
}
