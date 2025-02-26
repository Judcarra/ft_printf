/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judcarra <judcarra@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:00:09 by judcarra          #+#    #+#             */
/*   Updated: 2025/02/26 07:14:20 by judcarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int     ft_print_char(int c);
int     ft_print_str(char *str);
int     ft_print_nbr(int n);
unsigned int        ft_print_unsigned(unsigned int nbr);
int     ft_hexa_minus(unsigned int n);
int     ft_hexa_mayus(unsigned int n);




#endif
 
