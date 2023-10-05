/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:01:43 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:26:39 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

static int	sort_five_difference(t_stack *stack1)
{
	int	min;
	int	counter;
	int	i;
	int	j;

	min = find_min(stack1);
	i = 0;
	j = 0;
	while (stack1->top->index != min && ++i)
		ft_rotate(stack1);
	counter = i;
	while (counter--)
		ft_rev_rotate(stack1);
	while (stack1->top->index != min && ++j)
		ft_rev_rotate(stack1);
	counter = j;
	while (counter--)
		ft_rotate(stack1);
	return (i - j);
}

static void	sort_five_loop(t_stack *stack1)
{
	int	min;
	int	i;

	min = find_min(stack1);
	i = sort_five_difference(stack1);
	while (stack1->top->index != min)
	{
		if (i < 0)
			ra(stack1);
		else
			rra(stack1);
	}
}

void	sort_five(t_stack *stack1, t_stack *stack2)
{
	int	max;
	int	min;

	sort_five_loop(stack1);
	pb(stack1, stack2);
	sort_five_loop(stack1);
	pb(stack1, stack2);
	min = find_min(stack1);
	max = find_max(stack1);
	if (!ft_sorted(stack1))
		sort_three(stack1, max, min);
	pa(stack2, stack1);
	pa(stack2, stack1);
}

void	radix_sort(t_stack *stack1, t_stack *stack2, int size)
{
	int	i;
	int	j;
	int	max;
	int	max_bits;

	i = 0;
	max = size;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack1->top->index >> i) & 1) == 1)
				ra(stack1);
			else
				pb(stack1, stack2);
			++j;
		}
		while (ft_stacksize(stack2) != 0)
			pa(stack1, stack2);
		++i;
	}
}

void	sorting_algo(t_stack *stack1, t_stack *stack2)
{
	int	min;
	int	max;
	int	size;

	min = find_min(stack1);
	max = find_max(stack1);
	size = stack1->length;
	if (!ft_sorted(stack1))
	{
		if (stack1->length == 2)
			sort_two(stack1);
		else if (stack1->length == 3)
			sort_three(stack1, max, min);
		else if (stack1->length == 4)
			sort_four(stack1, stack2);
		else if (stack1->length == 5)
			sort_five(stack1, stack2);
		else
			radix_sort(stack1, stack2, size);
	}
}
