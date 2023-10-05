/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:16:26 by derblang          #+#    #+#             */
/*   Updated: 2023/03/21 09:24:53 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

// int	ft_stacklen(char **argv)
// {
// 	int	n_len;
// 	int	i;
// 	int	j;

// 	i = 1;
// 	j = 0;
// 	if (!argv[i][j])
// 		return (0);
// 	n_len = 0;
// 	while (argv[i])
// 	{
// 		while (argv[i][j])
// 		{
// 			if (argv[i][j] == '-' || argv[i][j] == '+' || argv[i][j] == ' ')
// 				j++;
// 			if ((argv[i][j] == '-' || argv[i][j] == '+')
// 				&& (!ft_isdigit(argv[i][j + 1])))
// 				return (0);
// 			if (argv[i][j] == ' ' || argv[i][j] == '\0')
// 				return (0);
// 			if (ft_isdigit(argv[i][j]) && argv[i][j + 1] == ' ')
// 				n_len++;
// 			j++;
// 		}
// 		n_len++;
// 		i++;
// 		j = 0;
// 	}
// 	//ft_printf("%d\n", n_len);
// 	return (n_len);
// }

// int	char_to_int(char *str)
// {
// 	int	*tab;
// 	int	i;
// 	int length = 0;

// 	i = 0;
// 	while (str[i])
// 	i++;
// 	i = length;
// 	tab = malloc(sizeof(int) * length);
// 	while (tab[i])
// 	{
// 		tab[i] = ft_atoi(str);
// 		ft_printf("%d\n", tab[i++]);
// 	}
// 	return (tab[i]);
// }

// void	ft_stack_init(int argc, char **argv)
// {
// 	char	**buffer;
// 	int		i;

// 	i = 0;
// 	buffer = malloc(sizeof(char) * ft_stacklen(argv));
// 	if (argc == 2)
// 		buffer = ft_split(argv[1], ' ');
// 	else
// 	{
// 		i = 1;
// 		buffer = argv;
// 	}
// }

static int	*ft_create_arr(t_stack *stack, int size)
{
	t_node	*current;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!stack || !arr)
		return (NULL);
	current = stack->top;
	i = 0;
	while (i < size)
	{
		arr[i] = current->content;
		current = current->next;
		i++;
	}
	return (arr);
}

void	ft_assign_index(t_stack *stack)
{
	t_node	*current;
	int		*arr;
	int		size;
	int		i;
	int		j;

	size = stack->length;
	arr = ft_create_arr(stack, size);
	ft_sort_int_tab(arr, size);
	current = stack->top;
	i = 0;
	j = 0;
	while (current != NULL)
	{
		while (i < size)
		{
			if (current->content == arr[i])
				current->index = i;
			i++;
		}
		i = 0;
		current = current->next;
	}
	free(arr);
}

void	ft_puterror(const char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

void	ft_stack_init(int argc, char **argv, t_stack *stack)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		ft_stackadd_bottom(stack, ft_newnode(ft_atoi(args[i])));
		i++;
	}
	if (argc == 2)
		free(args);
}
