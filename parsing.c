/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:15:26 by ahaloui           #+#    #+#             */
/*   Updated: 2023/02/23 18:22:44 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quit()
{
    ft_printf("Error");
    exit(EXIT_FAILURE);
}

int check_is_empty(char *str)
{
    return (!(*str));
}

int is_contain_allspace(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}


int check_is_digit(char *str)
{
    int i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (ft_isdigit(str[i]))
        i++;
    if (!ft_isdigit(str[i]) && str[i] != '\0' && str[i] != ' ')
        return (1);
    else
        return (0);
}

void check_string(int ac, char *str)
{
     if (ac < 2)
        quit();
    if (check_is_empty(str))
        quit();
    else if (is_contain_allspace(str))
        quit();
    else if (check_is_digit(str))
        quit();    
}