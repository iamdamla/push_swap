/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:28:28 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 09:42:30 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->top->index > stack->top->next->index)
		sa(stack);
}

void	sort_three(t_stack *stack, int max, int min)
{
	if (stack->top->index == max && stack->top->next->index != min)
	{
		sa(stack);
		rra(stack);
	}
	else if (stack->top->index == max && stack->top->next->index == min)
		ra(stack);
	else if (stack->top->index != max && stack->top->next->index == min)
		sa(stack);
	else if (stack->top->index == min && stack->top->next->index == max)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->top->index != min && stack->top->next->index == max)
		rra(stack);
}

static void	sort_four2(t_stack *stack1, t_stack *stack2, int max, int min)
{
	int	medium;

	medium = find_next_min(stack1);
	if (stack2->top->index > max)
	{
		pa(stack2, stack1);
		ra(stack1);
	}
	else if (stack2->top->index > medium && stack2->top->index < max)
	{
		ra(stack1);
		pa(stack2, stack1);
		sa(stack1);
		rra(stack1);
	}
	else if (stack2->top->index < medium && stack2->top->index > min)
	{
		ra(stack1);
		pa(stack2, stack1);
		rra(stack1);
	}
	else if (stack2->top->index < min)
		pa(stack2, stack1);
}

void	sort_four(t_stack *stack1, t_stack *stack2)
{
	int	min;
	int	max;

	pb(stack1, stack2);
	min = find_min(stack1);
	max = find_max(stack1);
	if (!ft_sorted(stack1))
		sort_three(stack1, max, min);
	sort_four2(stack1, stack2, max, min);
}
