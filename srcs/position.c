/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:30:16 by derblang          #+#    #+#             */
/*   Updated: 2023/03/17 13:14:39 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	current = stack->top;
	max = current->index;
	while (current->next != NULL)
	{
		if (current->next->index > max)
			max = current->next->index;
		current = current->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	min = current->index;
	while (current->next != NULL)
	{
		if (current->next->index < min)
			min = current->next->index;
		current = current->next;
	}
	return (min);
}

int	find_next_min(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		next_min;

	current = stack->top;
	max = find_max(stack);
	next_min = current->index;
	while (current->next != NULL)
	{
		if (current->next->index > next_min && current->next->index < max)
			next_min = current->next->index;
		current = current->next;
	}
	return (next_min);
}
