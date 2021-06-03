/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:15:10 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/31 15:47:53 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	arg_is_str2(t_pile *pile, int b, char **str)
{
	int	j;
	int	i;

	pile->a = malloc(sizeof (int *) * b);
	if (!pile->a)
		exit_error("Error\n");
	j = 0;
	i = 0;
	pile->arg_nb_a = b;
	while (b--)
	{
		pile->a[j] = ft_atoi(str[i++]);
		if (pile->a[j] < 0 || pile->a[j++] > 2147483647)
			exit_error("Error\n");
	}
	pile->a[j] = 0;
	ft_freetab(str);
}

void	arg_is_str(char *av, t_pile *pile)
{
	int		i;
	int		j;
	int		b;
	char	**str;

	i = 0;
	j = 0;
	b = 0;
	str = ft_split(av, ' ');
	while (str[b] != NULL)
		b++;
	while (i < (b - 1) && str[i])
	{
		j = 0;
		while (str[i++][j])
			if (!ft_isdigit(str[i][j++]))
				exit_error("Error\n");
	}
	arg_is_str2(pile, b, str);
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
	algo_main(pile);
	//test(pile);
	return (0);
}
