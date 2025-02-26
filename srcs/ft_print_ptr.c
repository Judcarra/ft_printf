/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judcarra <judcarra@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:02:00 by judcarra          #+#    #+#             */
/*   Updated: 2025/02/26 14:55:25 by judcarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int  ft_puthexa_ptr(unsigned long long ptr)
{
    char *hstr;
    int count;

    hstr = "0123456789abcdef";
    count = 0;
    if (ptr >= 16)
    {
        count = ft_puthexa_ptr(ptr / 16);
        if (count == -1)
            return (-1);
    }
    if (write(1, &hstr[ptr % 16], 1) == -1)
        return (-1);
    return (count + 1);
}

int ft_print_ptr(void *ptr)
{
    int count;
    unsigned long long p;

    count = 0;
    if (!ptr)
    {
        return (write(1, "(nil)", 5));
    }
    p = (unsigned long long)ptr;
    if (write(1, "0x", 2) != 2)
        return (-1);
    count = ft_puthexa_ptr(p);
    if (count == -1)
        return (-1);
    return (count + 2);
}