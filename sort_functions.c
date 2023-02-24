/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:15 by ahaloui           #+#    #+#             */
/*   Updated: 2023/02/24 22:50:33 by ahaloui          ###   ########.fr       */
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

int find_min(t_list *head)
{
    t_list *temp = head;
    int result  = temp->data;

    while (temp != NULL)
    {
        if (result > temp->data)
            result = temp->data;
        temp = temp->next;
    }
    return (result);
}


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

int get_index(t_list *head, int nbr)
{
    t_list *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (temp->data == nbr)
            return (temp->index);
        temp = temp->next;
        i++;
    }
    return (0);
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
    return (0);
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


void sort_two(t_list *head)
{
    sa(&head);
}

// function to sort three elements
void sort_three(t_list **head_a)
{
    t_list *temp = *head_a;
    int max =  find_max(*head_a);
    int index_node = get_index_max(*head_a, max);
    if (!is_sorted(head_a))
    {
        if (index_node == 0)
        {
            if (temp->data > temp->next->data && temp->next->data > temp->next->next->data)
            {
                sa(head_a);
                rra(head_a);
            }
            else if (temp->data > temp->next->data && temp->next->next->data > temp->next->data)
                ra(head_a);
        }    
        else if (index_node == 1)
        {
            if (temp->data < temp->next->data && temp->next->next->data < temp->next->data && temp->next->next->data > temp->data)
            {
                rra(head_a);
                sa(head_a);
            }
            else if (temp->data < temp->next->data && temp->next->next->data < temp->next->data && temp->data > temp->next->next->data)
                rra(head_a);
        }
        else if (index_node == 2)
            sa(head_a);
    }
}


// function to sort four elements
void sort_four(t_list **head_a, t_list **head_b)
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


// void sort_four(t_list **head_a, t_list **head_b)
// {
//     // t_list *temp = *head_a;
//     // int nbr = find_min(*head_a);
//     // int min = get_index_max(*head_a, nbr);
//     // int mid = ft_lstsize(*head_a) / 2;
//     // if (min < mid)
//     // {
//     //     if (temp->data < temp->next->data)
//     //     {
//     //         //sa(head_a);    
//     //         pb(head_a, head_b);
//     //         sort_three(head_a);
//     //         pa(head_a, head_b);
//     //     }
//     //     else if (temp->next->data < temp->data)
//     //     {
//     //         sa(head_a);
//     //         pb(head_a, head_b);
//     //         sort_three(head_a);
//     //         pa(head_a, head_b);
//     //     }
        
//     // }
//     // else if (min > mid)
//     // {
//     //     if (temp->next->next->data < temp->next->next->next->data)
//     //     {
//     //         rra(head_a);
//     //         rra(head_a);
//     //         pb(head_a, head_b);
//     //         sort_three(head_a);
//     //         pa(head_a, head_b);
//     //     }
//     //     else if (temp->next->next->next->data > temp->next->next->data)
//     //     {
//     //         rra(head_a);
//     //         pb(head_a, head_b);
//     //         sort_three(head_a);
//     //         pa(head_a, head_b);
//     //     }
//     // }

//     int 
// }

void sort(t_list **head_a, t_list **head_b)
{
    t_list *temp;
    int size;

    temp = *head_a;
    size = ft_lstsize(temp);
    if (size == 2)
    {
        sa(head_a);
        return ;
    }
    else if (size == 3)
        sort_three(head_a);
    else if (size <= 5)
        sort_four(head_a, head_b);
    else if (size > 5 && size <= 100)
    {
        printf("ff");
    }
    else if (size > 100)
    {
        printf("ff");
    }
        
}