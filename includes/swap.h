/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:52:37 by derblang          #+#    #+#             */
/*   Updated: 2023/03/20 13:12:57 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# include <unistd.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	size_t			length;
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

int					ft_check_args(int argc, char **argv);
int					char_to_int(char *str);
int					ft_stacklen(char **argv);
int					ft_isspace(char **argv);
void				ft_puterror(const char *str);
void				ft_stack_init(int argc, char **argv, t_stack *stack);
t_node				*ft_newnode(int content);
t_stack				*ft_stackadd_bottom(t_stack *stack, t_node *new);
t_stack				*ft_stacknew(void);
void				ft_assign_index(t_stack *stack);
t_stack				*ft_stackadd_top(t_stack *stack, t_node *new);
t_stack				*ft_stackinsert(t_stack *stack, t_node *node, int pos);
void				ft_stackdisplay(t_stack *stack);
void				ft_displayindex(t_stack *stack);
int					ft_stacksize(t_stack *stack);
void				ft_steakclear(t_stack **stack);
void				ft_swap(t_stack *stack);
void				ft_push(t_stack *stack1, t_stack *stack2);
void				ft_rotate(t_stack *stack);
void				ft_rev_rotate(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				sort_two(t_stack *stack);
void				sort_three(t_stack *stack, int max, int min);
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
int					find_next_min(t_stack *stack);
int					ft_sorted(t_stack *stack);
void				sort_four(t_stack *stack1, t_stack *stack2);
void				sort_five(t_stack *stack1, t_stack *stack2);
void				radix_sort(t_stack *stack1, t_stack *stack2, int size);
void				sorting_algo(t_stack *stack1, t_stack *stack2);
void				ft_stack_free(t_stack *s);

#endif