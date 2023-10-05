/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:29:56 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:19:07 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	ft_putendl("sa");
}

void	sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	ft_putendl("sb");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl("ss");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putendl("pa");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putendl("pb");
}
