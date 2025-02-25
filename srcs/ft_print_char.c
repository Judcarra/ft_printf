/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judcarra <judcarra@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:34:37 by judcarra          #+#    #+#             */
/*   Updated: 2025/02/25 06:09:10 by judcarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int    ft_print_char(int c)
{
    if(write(1, &c, 1) != 1)
        return(-1);
    return (1);
}

int main(){
    char c = 'h';
    ft_print_char(c);
    return (0);
}