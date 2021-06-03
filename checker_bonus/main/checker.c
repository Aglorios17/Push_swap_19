/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:24:14 by aglorios          #+#    #+#             */
/*   Updated: 2021/06/03 12:24:19 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	test_pile(t_pile *pile)
{
	int	loop;
	int	i;

	i = 0;
	printf("\npile a : ");
	for (loop = 0; loop < pile->arg_nb_a; loop++)
		printf("%d ", pile->a[loop]);
	printf("\npile b : ");
	for (loop = 0; loop < pile->arg_nb_b; loop++)
		printf("%d ", pile->b[loop]);
	printf("\n");
}

int	main(int ac, char **av)
{
	t_pile	*pile;
	int		i;

	i = 1;
	pile = ft_calloc(1, sizeof(t_pile));
	if (ac < 2)
		exit_error("Error\n");
	if (ac == 2)
	{
		arg_is_str(av[1], pile);
		i = pile->arg_nb_a - 1;
	}
	else
	{
		pile->a = malloc(sizeof(int *) * ac);
		if (!pile->a)
			return (0);
		while (i < ac)
			pile_arg(av[i++], pile);
		i -= 1;
		pile->a[i] = 0;
	}
	while (i != 0)
		pile_doublons(pile->a[--i], pile);
	checker_algo(pile);
	test_pile(pile);
	return (0);
}
