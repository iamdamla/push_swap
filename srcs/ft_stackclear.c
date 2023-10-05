/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:43:23 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:20:43 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	ft_steakclear(t_stack **stack)
{
	t_node	*current;
	t_node	*temp;

	if (*stack != NULL)
	{
		current = (*stack)->top;
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		free(*stack);
		*stack = NULL;
	}
}
