/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:15 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/01 20:23:10 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_B(t_list **head_a, t_list **head_b, int chunk)
{
    int nbr_chunk;
    int mid;
    int nbr_chunk_fix;
    int mid_fix;
    int size_b;

    nbr_chunk = (ft_lstsize(*head_a) / chunk);
    mid = nbr_chunk / 2;
    mid_fix = mid;
    nbr_chunk_fix = nbr_chunk;
    size_b = ft_lstsize(*head_b);
	while(*head_a)
    {
        while (*head_a && ft_lstsize(*head_b) < nbr_chunk)
        {
            if ((*head_a)->index < nbr_chunk && *head_a)
            {
                if ((*head_a)->index < nbr_chunk - mid_fix && *head_a)
                {   
                    pb(head_a, head_b);
                }
                else
                {
                    pb(head_a, head_b);
                    if (!((*head_a)->index < nbr_chunk) && *head_a)
                        rr(head_a, head_b);
                    else
                        rb(head_b);
                }
            }
            else
                ra(head_a);
        }
        nbr_chunk += nbr_chunk_fix;
    }
}

void f1(t_list **head_a, t_list **head_b, int size_b)
{
    while (get_position(*head_b, size_b - 2) != 0 && get_position(*head_b, size_b - 2) >= size_b / 2)
        rrb(head_b);
    while (get_position(*head_b, size_b - 2) != 0 && get_position(*head_b, size_b - 2) < size_b / 2)
        rb(head_b);
    if (get_position(*head_b, size_b - 2) == 0)
        pa(head_a, head_b);
	
    while (get_position(*head_b, size_b - 1) != 0 && get_position(*head_b, size_b - 1) >= size_b / 2)
        rrb(head_b);
    while (get_position(*head_b, size_b - 1) != 0 && get_position(*head_b, size_b - 1) < size_b / 2)
        rb(head_b);
    if (get_position(*head_b, size_b - 1) == 0)
        pa(head_a, head_b);
	if ((*head_a)->index > (*head_a)->next->index )
		sa(head_a);
}

void f2(t_list **head_a, t_list **head_b, int size_b)
{
    while (get_position(*head_b, size_b - 1) != 0 && get_position(*head_b, size_b - 1) >= size_b / 2)
        rrb(head_b);
    while (get_position(*head_b, size_b - 1) != 0 && get_position(*head_b, size_b - 1) < size_b / 2)
        rb(head_b);
    if (get_position(*head_b, size_b - 1) == 0)
        pa(head_a, head_b);
}

void sort_numbers(t_list **head_a, t_list **head_b, int chunk_divide)
{
    int chunk;
	// int	instriction_max;
	// int	instriction_bef_max;
    // int middle;
    // int size_b;

    
    chunk = chunk_divide;
    // print_list(*head_a);
    push_to_B(head_a, head_b, chunk);
    // print_list(*head_b);
    // size_b = ft_lstsize(*head_b);
    // while (size_b)
    // {
	// 	size_b = ft_lstsize(*head_b);
    // //     // // printf("pos = [%d]\n", get_position(*head_a, ft_lstsize(*head_a)) - 1);
	// 	instriction_max = instriction(size_b, get_position(*head_a, ft_lstsize(*head_a)) - 1);
	// 	instriction_bef_max = instriction(size_b, get_position(*head_a, ft_lstsize(*head_a) - 2));
    //     middle = (size_b / 2);
    //     // printf("instriction_max = %d > ", instriction_max);
    //     // printf("instriction_bef_max = %d\n", instriction_bef_max);
    //     if (instriction_max > instriction_bef_max)
    //         f1(head_a, head_b, size_b);
	// 	else
    //     	f2(head_a, head_b, size_b);
    //     size_b--;
    // }
}


// Function to calculate numbre of instriction
int instriction(int size_b, int pos)
{
    int middle;
    int instriction;

    middle = (size_b / 2);
    if (pos >= middle)
        instriction = (size_b - pos) + 1;
    else
        instriction = pos + 1;
    return (instriction);
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

