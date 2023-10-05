/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdisplay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:25:28 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:20:16 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	ft_stackdisplay(t_stack *stack)
{
	t_node	*current;

	if (stack != NULL)
	{
		current = stack->top;
		while (current != NULL)
		{
			ft_putnbr(current->content);
			ft_putchar('\n');
			current = current->next;
		}
	}
	ft_putendl("NULL");
}

void	ft_displayindex(t_stack *stack)
{
	t_node	*current;

	if (stack != NULL)
	{
		current = stack->top;
		while (current != NULL)
		{
			ft_putnbr(current->index);
			ft_putchar('\n');
			current = current->next;
		}
	}
	ft_putendl("NULL");
}
