/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:06:43 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:20:02 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

static void	ft_nodelinker(t_stack *stack, t_node *current, t_node *new)
{
	if (current->next == NULL)
		stack = ft_stackadd_bottom(stack, new);
	else if (current->prev == NULL)
		stack = ft_stackadd_top(stack, new);
	else
	{
		current->next->prev = new;
		current->prev->next = new;
		new->prev = current->prev;
		new->next = current;
		stack->length++;
	}
}

t_stack	*ft_stackinsert(t_stack *stack, t_node *node, int pos)
{
	t_node	*temp;
	int		i;

	if (stack != NULL && node != NULL)
	{
		temp = stack->top;
		i = 1;
		while (temp != NULL && i <= pos)
		{
			if (pos == i)
				ft_nodelinker(stack, temp, node);
			else
				temp = temp->next;
			i++;
		}
	}
	return (stack);
}
