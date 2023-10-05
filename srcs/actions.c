/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:13:09 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:18:56 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	ft_swap(t_stack *stack)
{
	if (stack->length > 1)
	{
		if (stack->length > 2)
		{
			stack->top = stack->top->next;
			stack->top->prev->next = stack->top->next;
			stack->top->next = stack->top->prev;
			stack->top->prev = NULL;
			stack->top->next->prev = stack->top;
			stack->top->next->next->prev = stack->top->next;
		}
		else
		{
			stack->bottom = stack->top;
			stack->top = stack->top->next;
			stack->bottom->prev = stack->top;
			stack->top->next = stack->bottom;
			stack->bottom->next = NULL;
			stack->top->prev = NULL;
		}
	}
}

static void	ft_push2(t_stack *stack1, t_stack *stack2)
{
	if (stack1->length == 1 && stack2->length >= 1)
	{
		stack2->top->prev = stack1->top;
		stack2->top->prev->next = stack2->top;
		stack2->top = stack1->top;
		stack1->top = NULL;
		stack1->bottom = NULL;
	}
	else if (stack1->length == 1 && stack2->length == 0)
	{
		stack2->top = stack1->top;
		stack2->bottom = stack1->top;
		stack1->top = NULL;
		stack1->bottom = NULL;
	}
}

void	ft_push(t_stack *stack1, t_stack *stack2)
{
	if (stack1->length >= 1 && stack2->length >= 0)
	{
		if (stack1->length >= 2 && stack2->length >= 1)
		{
			stack1->top = stack1->top->next;
			stack2->top->prev = stack1->top->prev;
			stack2->top->prev->next = stack2->top;
			stack2->top = stack2->top->prev;
			stack1->top->prev = NULL;
			stack2->top->prev = NULL;
		}
		else if (stack1->length >= 2 && stack2->length == 0)
		{
			stack2->top = stack1->top;
			stack1->top = stack1->top->next;
			stack1->top->prev = NULL;
			stack2->top->next = NULL;
			stack2->top->prev = NULL;
			stack2->bottom = stack2->top;
		}
		else if (stack1->length == 1)
			ft_push2(stack1, stack2);
		stack1->length--;
		stack2->length++;
	}
}

void	ft_rotate(t_stack *stack)
{
	if (stack->length > 1)
	{
		if (stack->length > 2)
		{
			stack->top->prev = stack->bottom;
			stack->bottom->next = stack->top;
			stack->bottom = stack->top;
			stack->top = stack->top->next;
			stack->bottom->next = NULL;
		}
		else
			ft_swap(stack);
	}
}

void	ft_rev_rotate(t_stack *stack)
{
	if (stack->length > 1)
	{
		if (stack->length > 2)
		{
			stack->top->prev = stack->bottom;
			stack->bottom->next = stack->top;
			stack->top = stack->bottom;
			stack->bottom = stack->bottom->prev;
			stack->bottom->next = NULL;
		}
		else
			ft_swap(stack);
	}
}
