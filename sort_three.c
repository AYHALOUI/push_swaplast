/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:33:57 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/01 16:35:35 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_list *head)
{
    t_list *temp = head;
    int result  = temp->data;

    while (temp != NULL)
    {
        if (result < temp->data)
            result = temp->data;
        temp = temp->next;
    }
    return (result);
}

int get_index_max(t_list *head, int max)
{
    t_list *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (temp->data == max)
            return (i);
        temp = temp->next;
        i++;
    }
    return (0);
}

void help_sort_three(t_list **head_a, int index_node)
{
	if (index_node == 0)
        {
            if ((*head_a)->data > (*head_a)->next->data && (*head_a)->next->data > (*head_a)->next->next->data)
            {
                sa(head_a);
                rra(head_a);
            }
            else if ((*head_a)->data > (*head_a)->next->data && (*head_a)->next->next->data > (*head_a)->next->data)
                ra(head_a);
        }    
        else if (index_node == 1)
        {
            if ((*head_a)->data < (*head_a)->next->data && (*head_a)->next->next->data < (*head_a)->next->data && (*head_a)->next->next->data > (*head_a)->data)
            {
                rra(head_a);
                sa(head_a);
            }
            else if ((*head_a)->data < (*head_a)->next->data && (*head_a)->next->next->data < (*head_a)->next->data && (*head_a)->data > (*head_a)->next->next->data)
                rra(head_a);
        }
        else if (index_node == 2)
            sa(head_a);
}

void sort_three(t_list **head_a)
{
    int max;
    int index_node;

	max = find_max(*head_a);
	index_node= get_index_max(*head_a, max);
    if (!is_sorted(head_a))
		help_sort_three(head_a, index_node);
}