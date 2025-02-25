/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judcarra <judcarra@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:16:40 by judcarra          #+#    #+#             */
/*   Updated: 2025/02/25 08:59:25 by judcarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

static int int_min(int n)
{
    (void)n;
    if (write(1, "-2147483648", 11) != 11)
        return (-1);
    return (11);
}

int ft_print_nbr(int n)
{
    int count;

    count = 0;
    if (n == -2147483648)
        return (int_min(n));
    if (n < 0 && ++count)      //count++ para incrementar count en 1 y dejar espacio para el signo negaivo
    {
        if (write(1, "-", 1) != 1)
            return (-1);
        n = -n;
    }
    if (n > 9)
    {
        count += ft_print_nbr(n / 10);
        if (count == -1)
            return (-1);
        n = n % 10;
    }
    if (n <= 9)
    {
        if (ft_print_char(('0' + n)) == -1)
            return (-1);
        count++;
    }
    return (count);
}

