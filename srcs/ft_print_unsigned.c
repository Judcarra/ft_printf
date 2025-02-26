/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judcarra <judcarra@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:05:18 by judcarra          #+#    #+#             */
/*   Updated: 2025/02/25 12:17:31 by judcarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int    ft_print_unsigned(unsigned int nbr)
{
    int count;

    count = 0;
    if (nbr > 9)
    {
        count = ft_print_unsigned(nbr / 10);
        if (count == -1)
            return (-1);
        nbr = nbr % 10;
    }
    if (nbr <= 9)
    {
        if (ft_print_char('0' + nbr) == -1)
            return (-1);
        count++;
    }
    return (count);
}