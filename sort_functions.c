/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:15 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/01 00:22:53 by ahaloui          ###   ########.fr       */
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

// void sort_more_then_five(t_list **head_a, t_list **head_b)
// {
//     int chunk = 5;
//     int nbr_chunk = ft_lstsize(*head_a) / chunk;
//     int nbr_chunk_fix = nbr_chunk;
//     int mid = nbr_chunk / 2;
//     int mid_fix = mid;
//     t_list *temp;
    
//     temp = *head_a;
//     // printf("chunk => %d\n\n", nbr_chunk);
//     // printf("midle => %d\n\n", mid);
//     while(chunk--)
//     {
//         // printf("nbr-CHUNKD : %d\n\n", nbr_chunk);

//         // push to b
//         while (ft_lstsize(*head_b) < nbr_chunk)
//         {
//         if ((*head_a)->index < nbr_chunk)
//         {
//             if ((*head_a)->index < mid)
//             {   
//                 pb(head_a, head_b);
//                 rb(head_b);
//             }
//             else
//                 pb(head_a, head_b);
//         }
//         else
//             ra(head_a);
//         }
//         nbr_chunk += nbr_chunk_fix;
//         mid = nbr_chunk - mid_fix;
//         // printf("mid => %d\n\n", mid);
//     }
//     // int position = 0;
//     int middle;
//     int size_b = ft_lstsize(*head_b);
//     // printf("size of b => %d\n", size_b);
//     // push to A
//     while (size_b)
//     {
//         middle = ft_lstsize(*head_b) / 2;

//         while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
//                 rrb(head_b);
//             while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
//                 rb(head_b);
//             if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
//                 pa(head_a, head_b);
//         while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
//                 rrb(head_b);
//             while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
//                 rb(head_b);
//             if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
//                 pa(head_a, head_b);
//         size_b--;    
//     }
//     // printf("\n");
// }

// funnction to get the nearest element to the top of the stack
// int get_near(t_list *head, int nbr)
// {
//     int position = 0;
//     t_list *temp;

//     temp = head;
//     while (temp->index != nbr)
//     {
//         temp = temp->next;
//         position++;
//     }
//     return (position);
// }


// void sort_500(t_list **head_a, t_list **head_b)
// {
//     int chunk = 10;
//     int nbr_chunk = ft_lstsize(*head_a) / chunk;
//     int nbr_chunk_fix = nbr_chunk;
//     int mid = nbr_chunk / 2;
//     int mid_fix = mid;
//     t_list *temp;
    
//     temp = *head_a;
//     while(chunk--)
//     {
//         while (ft_lstsize(*head_b) < nbr_chunk)
//         {
//         if ((*head_a)->index < nbr_chunk)
//         {
//             if ((*head_a)->index < mid)
//             {   
//                 pb(head_a, head_b);
//                 rb(head_b);
//             }
//             else
//                 pb(head_a, head_b);
//         }
//         else
//             ra(head_a);
//         }
//         nbr_chunk += nbr_chunk_fix;
//         mid = nbr_chunk - mid_fix;
//     }
//     int middle;
//     int size_b = ft_lstsize(*head_b);
//     while (size_b)
//     {
//         middle = ft_lstsize(*head_b) / 2;
//         while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
//                 rrb(head_b);
//             while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
//                 rb(head_b);
//             if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
//                 pa(head_a, head_b);
//         while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) >= middle)
//                 rrb(head_b);
//             while (get_position(*head_b, ft_lstsize(*head_b) - 1) != 0 && get_position(*head_b, ft_lstsize(*head_b) - 1) < middle)
//                 rb(head_b);
//             if (get_position(*head_b, ft_lstsize(*head_b) - 1) == 0)
//                 pa(head_a, head_b);
//         size_b--;    
//     }
// }


void push_to_B(t_list **head_a, t_list **head_b, int chunk)
{
    int nbr_chunk;
    int mid;
    // int i = -1;
    int nbr_chunk_fix;
    int mid_fix;

    nbr_chunk = ft_lstsize(*head_a) / chunk;
    mid = nbr_chunk / 2;
    mid_fix = mid;
    nbr_chunk_fix = nbr_chunk;

	while(chunk--)
    {
        while (ft_lstsize(*head_b) < nbr_chunk && *head_a)
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
        }
        nbr_chunk += nbr_chunk_fix;
        mid = nbr_chunk - mid_fix;
    }
	while (ft_lstsize(*head_a))
        pb(head_a, head_b);
}

int	instriction(int size_list, int position)
{
	int	instriction;
		if (position > size_list / 2)
			instriction = (size_list - position);
		else
			instriction = position;
	return (instriction);
}

void sort_numbers(t_list **head_a, t_list **head_b, int chunk_divide)
{
     int chunk;
	//  int	instriction_max;
	//  int	instriction_bef_max;
    // int middle;
    // int size_b;

    
    chunk = chunk_divide;
    push_to_B(head_a, head_b, chunk);
    // size_b = ft_lstsize(*head_b);
    // while (size_b)
    // {
	// 	instriction_max = instriction(ft_lstsize(*head_b), get_position(*head_a, ft_lstsize(*head_a) - 1));
	// 	instriction_bef_max = instriction(ft_lstsize(*head_b), get_position(*head_a, ft_lstsize(*head_a) - 2));
    //     middle = ft_lstsize(*head_b) / 2;
	// 	size_b = ft_lstsize(*head_b);
	// 	if (instriction_max > instriction_bef_max)
	// 	{
    //     	while (get_position(*head_b, size_b - 2) != 0 && get_position(*head_b, size_b - 2) >= size_b / 2)
    //     	        rrb(head_b);
    //     	    while (get_position(*head_b, size_b - 2) != 0 && get_position(*head_b, size_b - 2) < size_b / 2)
    //     	        rb(head_b);
    //     	    if (get_position(*head_b, size_b - 2) == 0)
    //     	        pa(head_a, head_b);
					
    //     	while (get_position(*head_b, size_b - 1) != 0 && get_position(*head_b, size_b - 1) >= size_b / 2)
    //     	        rrb(head_b);
    //     	    while (get_position(*head_b, size_b - 1) != 0 && get_position(*head_b, size_b - 1) < size_b / 2)
    //     	        rb(head_b);
    //     	    if (get_position(*head_b, size_b - 1) == 0)
    //     	        pa(head_a, head_b);
	// 			if ((*head_a)->index > (*head_a)->next->index )
	// 				sa(head_a);
	// 	}
	// 	else
	// 	{
    //     	while (get_position(*head_b, size_b - 1) != 0 && get_position(*head_b, size_b - 1) >= size_b / 2)
    //     	        rrb(head_b);
    //     	    while (get_position(*head_b, size_b - 1) != 0 && get_position(*head_b, size_b - 1) < size_b / 2)
    //     	        rb(head_b);
    //     	    if (get_position(*head_b, size_b - 1) == 0)
    //     	        pa(head_a, head_b);
	// 	}
    //     size_b--;    
    // }
}


void sort(t_list **head_a, t_list **head_b)
{
    t_list *temp;
    int size;

    temp = *head_a;
    size = ft_lstsize(temp);
    
    if (size == 2)
        sa(head_a);
    else if (size == 3)
        sort_three(head_a);
    else if (size <= 5)
        sort_five(head_a, head_b);
    else if (size > 5 && size <= 100)
        sort_numbers(head_a, head_b, 5);
    else if (size > 100)
        	sort_numbers(head_a, head_b, 8);
}

