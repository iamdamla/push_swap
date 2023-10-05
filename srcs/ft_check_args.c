/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:02:07 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 12:00:24 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	ft_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack != NULL)
	{
		current = stack->top;
		while (current->next != NULL)
		{
			if (current->index > current->next->index)
				return (0);
			current = current->next;
		}
	}
	return (1);
}

static int	ft_repeat(long tmp, char **argv, int i)
{
	while (argv[++i] != NULL)
	{
		if (ft_atoi(argv[i]) == tmp)
			return (0);
	}
	return (1);
}

// int	ft_isnum(char *args)
// {
// 	int	i;

// 	i = 0;
// 	if ((args[i] == '-' || args[i] == '+' || ft_isdigit(args[i]))
// 		&& ft_strlen(args) <= 11)
// 	{
// 		if ((args[i] == '-' || args[i] == '+') && !ft_isdigit(args[i + 1]))
// 			return (0);
// 		if (args[i] == ' ' || args[i] == '\0')
// 		return (0);
// 		i++;

// 		while (args[i])
// 		{
// 			if (!ft_isdigit(args[i]))
// 				return (0);
// 			i++;
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

static int	ft_isnum(char *nptr)
{
	int	i;

	i = 0;
	if (nptr[i] == '-')
		i++;
	if (nptr[i] == ' ' || nptr[i] == '\0')
		return (0);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	if (!*args)
		exit(0);
	while (args[i])
	{
		if (!ft_isnum(args[i]) || !ft_repeat(ft_atoi(args[i]), args, i)
			|| !ft_strtolol(args[i]))
			ft_puterror("Error");
		i++;
	}
	if (argc == 2)
		free(args);
	return (0);
}
