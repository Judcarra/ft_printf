/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judcarra <judcarra@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:23:37 by judcarra          #+#    #+#             */
/*   Updated: 2025/02/26 07:11:28 by judcarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int  ft_puthexa(char *hstr, unsigned int n, int c)
{
    unsigned int s;

    s = ft_strlen(hstr);
    if (n >= s)
    {
        c = ft_puthexa(hstr, n / s, c);
        if (c == -1)
            return (-1);
    }
    if (write(1, &hstr[n % s], 1)== -1)
        return (-1);
    return (c + 1);
}

int ft_hexa_minus(unsigned int n)
{
    return (ft_puthexa("0123456789abcdef", n, 0));
}