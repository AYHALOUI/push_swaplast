/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:39:20 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/01 19:18:14 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void index_list(t_list *head)
{
    t_list *temp;
    t_list *temp2;
    int i;
    int j;
    int index;

    temp = head;
    i = 0;
    index = 0;
    while (temp != NULL)
    {
        temp2 = head;
        j = 0;
        while (temp2 != NULL)
        {
            if (temp->data > temp2->data)
                j++;
            temp2 = temp2->next;
        }
        temp->index = j;
        temp = temp->next;
    }
}


int get_position(t_list *head, int index)
{
    t_list *temp = head;
    int position = 0;
    while (temp != NULL)
    {
        if (temp->index == index)
            return(position);
        position++;
        temp = temp->next;
    }
    return (position);
}


void sort_five(t_list **head_a, t_list **head_b)
{
    int mid;
    int i;

    i = 0;
    while (ft_lstsize(*head_a) > 3)
    {
        mid = ft_lstsize(*head_a) / 2;
        while (get_position(*head_a, i) > mid && get_position(*head_a, i) != 0)
            rra(head_a);   
         while (get_position(*head_a, i) <= mid && get_position(*head_a, i) != 0)
            ra(head_a);
        if (get_position(*head_a, i) == 0)
            pb(head_a, head_b);    
        i++;      
    }
    if (ft_lstsize(*head_a) == 3)
        sort_three(head_a);
    pa(head_a, head_b);
    pa(head_a, head_b);        
}