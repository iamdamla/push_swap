/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:38:34 by derblang          #+#    #+#             */
/*   Updated: 2023/03/21 09:46:32 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

t_stack	*ft_stacknew(void)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (new != NULL)
	{
		new->length = 0;
		new->top = NULL;
		new->bottom = NULL;
	}
	return (new);
}

void	ft_stack_free(t_stack *s)
{
	t_node	*n;
	t_node	*to_free;

	n = s->top;
	while (n != NULL)
	{
		to_free = n;
		free(to_free);
		n = n->next;
	}
	free(s);
}
