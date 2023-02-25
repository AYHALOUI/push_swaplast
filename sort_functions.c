/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:15 by ahaloui           #+#    #+#             */
/*   Updated: 2023/02/25 21:07:50 by ahaloui          ###   ########.fr       */
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

void sort_more_then_five(t_list **head_a, t_list **head_b)
{
    int chunk = 5;
    int nbr_chunk = ft_lstsize(*head_a) / chunk;
    int nbr_chunk_fix = nbr_chunk;
    int mid = nbr_chunk / 2;
    int mid_fix = mid;
    t_list *temp;
    
    temp = *head_a;
    // printf("chunk => %d\n\n", nbr_chunk);
    // printf("midle => %d\n\n", mid);
    while(chunk--)
    {
        // printf("nbr-CHUNKD : %d\n\n", nbr_chunk);
        while (ft_lstsize(*head_b) < nbr_chunk)
        {
        if ((*head_a)->index < nbr_chunk)
        {
            if ((*head_a)->index < mid)
            {   
                pb(head_a, head_b);
                rb(head_b);
            }
            else
                pb(head_a, head_b);
        }
        else
            ra(head_a);
        // while (temp->index > mid && temp->index != 0)
        // {
        //     rra(head_a);
        //     printf("rra\n");
        // }
        // while (temp->index <= mid && temp->index != 0)
        // {
        //     ra(head_a);
        //     printf("ra\n");
        // }
        // if (temp->index == 0)
        // {
        //     pb(head_a, head_b);
        //     printf("pb\n");
        // }  
        }
        nbr_chunk += nbr_chunk_fix;
        mid = nbr_chunk - mid_fix;
        // printf("mid => %d\n\n", mid);
    }
    // int position = 0;
    int middle;
    int size_b = ft_lstsize(*head_b);
    // printf("size of b => %d\n", size_b);
    while (size_b)
    {
        middle = ft_lstsize(*head_b) / 2;
        // if (get_position(*head_b, ft_lstsize(*head_b) - 1) > get_position(*head_b, ft_lstsize(*head_b) - 2))
        // {
        //     while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
        //         rrb(head_b);
        //     while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
        //         rb(head_b);
        //     if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
        //         pa(head_a, head_b);
        // }
        // else if (get_position(*head_b, ft_lstsize(*head_b) - 1) < get_position(*head_b, ft_lstsize(*head_b) - 2))
        // {
        //     while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
        //         rrb(head_b);
        //     while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
        //         rb(head_b);
        //     if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
        //         pa(head_a, head_b);
        // }

        while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
                rrb(head_b);
            while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
                rb(head_b);
            if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
                pa(head_a, head_b);
        while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
                rrb(head_b);
            while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
                rb(head_b);
            if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
                pa(head_a, head_b);
        size_b--;    
    }
    // printf("\n");
}


void sort_500(t_list **head_a, t_list **head_b)
{
    int chunk = 8;
    int nbr_chunk = ft_lstsize(*head_a) / chunk;
    int nbr_chunk_fix = nbr_chunk;
    int mid = nbr_chunk / 2;
    int mid_fix = mid;
    t_list *temp;
    
    temp = *head_a;
    // printf("chunk => %d\n\n", nbr_chunk);
    // printf("midle => %d\n\n", mid);
    while(chunk--)
    {
        // printf("nbr-CHUNKD : %d\n\n", nbr_chunk);
        while (ft_lstsize(*head_b) < nbr_chunk)
        {
        if ((*head_a)->index < nbr_chunk)
        {
            if ((*head_a)->index < mid)
            {   
                pb(head_a, head_b);
                rb(head_b);
            }
            else
                pb(head_a, head_b);
        }
        else
            ra(head_a);
        // while (temp->index > mid && temp->index != 0)
        // {
        //     rra(head_a);
        //     printf("rra\n");
        // }
        // while (temp->index <= mid && temp->index != 0)
        // {
        //     ra(head_a);
        //     printf("ra\n");
        // }
        // if (temp->index == 0)
        // {
        //     pb(head_a, head_b);
        //     printf("pb\n");
        // }  
        }
        nbr_chunk += nbr_chunk_fix;
        mid = nbr_chunk - mid_fix;
        // printf("mid => %d\n\n", mid);
    }
    // int position = 0;
    int middle;
    int size_b = ft_lstsize(*head_b);
    // printf("size of b => %d\n", size_b);
    while (size_b)
    {
        middle = ft_lstsize(*head_b) / 2;
        // if (get_position(*head_b, ft_lstsize(*head_b) - 1) > get_position(*head_b, ft_lstsize(*head_b) - 2))
        // {
        //     while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
        //         rrb(head_b);
        //     while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
        //         rb(head_b);
        //     if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
        //         pa(head_a, head_b);
        // }
        // else if (get_position(*head_b, ft_lstsize(*head_b) - 1) < get_position(*head_b, ft_lstsize(*head_b) - 2))
        // {
        //     while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
        //         rrb(head_b);
        //     while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
        //         rb(head_b);
        //     if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
        //         pa(head_a, head_b);
        // }

        while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
                rrb(head_b);
            while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
                rb(head_b);
            if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
                pa(head_a, head_b);
        while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
                rrb(head_b);
            while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
                rb(head_b);
            if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
                pa(head_a, head_b);
        size_b--;    
    }
    // printf("\n");
}



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
        sort_five(head_a, head_b);
    else if (size > 5 && size <= 100)
    {
        sort_more_then_five(head_a, head_b);
    }
    else if (size > 100)
    {
        sort_500(head_a, head_b);
    }
}

