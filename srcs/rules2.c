/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:29:43 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 11:19:12 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	ft_putendl("ra");
}

void	rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	ft_putendl("rb");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl("rr");
}
