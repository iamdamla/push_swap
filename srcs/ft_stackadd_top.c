/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:20:39 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:21:29 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

t_stack	*ft_stackadd_top(t_stack *stack, t_node *new)
{
	if (stack != NULL && new != NULL)
	{
		if (stack->bottom == NULL)
		{
			new->next = NULL;
			stack->top = new;
			stack->bottom = new;
		}
		else
		{
			stack->top->prev = new;
			new->next = stack->top;
			stack->top = new;
		}
		stack->length++;
	}
	return (stack);
}
