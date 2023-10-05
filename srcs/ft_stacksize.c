/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:40:30 by derblang          #+#    #+#             */
/*   Updated: 2023/03/17 13:16:00 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Counts the number of elements in the stack

#include "../includes/swap.h"

int	ft_stacksize(t_stack *stack)
{
	t_node	*current;
	int		counter;

	if (stack != NULL)
	{
		current = stack->top;
		counter = 0;
		while (current != NULL)
		{
			counter++;
			current = current->next;
		}
		return (counter);
	}
	return (0);
}
