/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 15:44:29 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/26 20:13:33 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap:
//	sa - swap a -		Swap the two top elements of stack a.
//	sb - swap b -		Swap the two top elements of stack b.
//	ss - swap both -	Swap both at once.

// When swapping node 1 and 2, both will still point to node 2 and 3.
// To avoid this, we update (*stack)->next to skip swap (second node) 
// and instead point to the node that follows after swap.
// To avoid an infinite loop, we use add_front after updating the nodes.
static void	swap(t_stack **stack)
{
	t_stack	*swap;

	if (count_stacks(*stack) <= 1)
		return ;
	swap = (*stack)->next;
	(*stack)->next = swap->next; 
	add_front(stack, swap);
}

void	sa(t_stack **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
