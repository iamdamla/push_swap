/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:29:27 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:19:15 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	rra(t_stack *stack_a)
{
	ft_rev_rotate(stack_a);
	ft_putendl("rra");
}

void	rrb(t_stack *stack_b)
{
	ft_rev_rotate(stack_b);
	ft_putendl("rrb");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_putendl("rrr");
}
