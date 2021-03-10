#include "../include/checker.h"

int	check_values(int argc, char **argv, t_check *check)
{
	int		i;
	int		a;
	int		b;
	char	**tabs;

	i = 0;
	a = 0;
	b = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		tabs = ft_split(argv[1], ' ');
		while (tabs[b] != NULL)
			b++;
		while (i < (b - 1) && tabs[i])
		{
			a = 0;
			while (tabs[i][a])
			{
				if (!ft_isdigit(tabs[i][a++]))
				{
					write(1, "Error : only numbers pls\n", 25);
					ft_freetab(tabs);
					return (-1);
				}
			}
			i++;
		}
		if (!(check->arr = malloc(sizeof (int) * b)))
		{
			ft_freetab(tabs);
			return (0);
		}
		a  = 0;
		i  = 0;
		while (--b)
			check->arr[a++] = ft_atoi(tabs[i++]);
		ft_freetab(tabs);
		return (1);
	}
	else
	{
		while (i < (argc - 1) && argv[i++])
		{
			a = 0;
			while (argv[i][a])
				if (!ft_isdigit(argv[i][a++]))
				{
					write(1, "Error : only numbers pls\n", 25);
					return (-1);
				}
		}
	}
	return (1);
}

int	get_values(int argc, char **argv, t_check *check)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	if (argc == 2)
		return (1);		
	else
	{
		if (!(check->arr = malloc(sizeof (int) * argc)))
			return (0);
		while (i < argc)
			check->arr[a++] = ft_atoi(argv[i++]);
		check->arr[a] = 0;
	}
	return (1);
}

int		put_to_stack(t_check *check)
{
	int	i;

	i = 0;
	while (check->arr[i])
		ft_lstadd_back(&check->stacka, ft_lstnew(ft_itoa(check->arr[i++])));
	check->firsta = check->stacka;
	free(check->arr);
	return (1);
}

int		ft_swap_s(int stack, int arg, t_check *check)
{
	char *tmp;

	tmp = NULL;
	check->stacka = check->firsta;
	if (stack == 1 || arg == 1)
	{
			tmp = ft_strdup(check->stacka->next->content);
			free(check->stacka->next->content);
			check->stacka->next->content = ft_strdup(check->stacka->content);
			free(check->stacka->content);
			check->stacka->content = tmp;
			check->firsta = check->stacka;
			free(tmp);
	}
	if (stack == 2 || arg == 1)
	{
			tmp = ft_strdup(check->stackb->next->content);
			free(check->stackb->next->content);
			check->stackb->next->content = ft_strdup(check->stackb->content);
			free(check->stackb->content);
			check->stackb->content = tmp;
			check->firstb = check->stackb;
			free(tmp);
	}
	return (1);
}

int		process(t_check *check)
{
	if (!ft_strncmp(check->input, "sa", 3))
		ft_swap_s(1, 0, check);
	if (!ft_strncmp(check->input, "sb", 3))
		ft_swap_s(2, 0, check);
	if (!ft_strncmp(check->input, "ss", 3))
		ft_swap_s(0, 1, check);
	write(1, "\n", 1);
	return (1);
}

int		check_final(t_check *check)
{
	printf("stack a =");
	while (check->stacka)
	{
		printf(" %s ", check->stacka->content);
		check->stacka = check->stacka->next;
	}
	printf("\n");
	return (1);
}

void	init_struct(t_check *check)
{
	check->arr = NULL;
	check->stacka = NULL;
	check->stackb = NULL;
	check->input = NULL;
}

t_check	*global_struct(void)
{
	static t_check	check;
	return (&check);
}

int main(int argc, char **argv)
{
	t_check	*check;

	check = global_struct();
	init_struct(check);
	if (check_values(argc, argv, check) == 0)
		return (0);
	if (get_values(argc, argv, check) == 0)
		return (0);
	if (put_to_stack(check) == 0)
		return (0);
	if (get_next_line3d(0, &check->input) != 1)
		return (0);
	if (process(check) == 0)
		return (0);
	if (check_final(check) == 0)
		return (0);
	return (1);
}
