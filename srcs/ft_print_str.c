/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judcarra <judcarra@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:17:48 by judcarra          #+#    #+#             */
/*   Updated: 2025/02/23 16:05:07 by judcarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_print_str(char *str)
{
    int     i;

    if (!str)
    {
        if (write(1, "(null)", 6) != 6)
            return (-1);
        return (6);
    }
    i = 0;
    while (str[i])
    {
        if (write(1, &str[i], 1) != 1)
            return (-1);
        i++;
    }
    return (i);
}