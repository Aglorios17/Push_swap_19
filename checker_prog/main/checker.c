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
		while (--argc)
			check->arr[a++] = ft_atoi(argv[i++]);
	}
	return (1);
}

void	init_struct(t_check *check)
{
	check->arr = NULL;
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
}
