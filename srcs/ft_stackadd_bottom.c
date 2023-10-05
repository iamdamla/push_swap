/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_bottom.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:30:52 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:21:53 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

t_stack	*ft_stackadd_bottom(t_stack *stack, t_node *new)
{
	if (stack != NULL && new != NULL)
	{
		if (stack->bottom == NULL)
		{
			new->prev = NULL;
			stack->top = new;
			stack->bottom = new;
		}
		else
		{
			stack->bottom->next = new;
			new->prev = stack->bottom;
			stack->bottom = new;
		}
		stack->length++;
	}
	return (stack);
}
