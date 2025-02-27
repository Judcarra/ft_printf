#include "../includes/ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

static int type_var(char c, va_list element);

static int w_str_percent(const char c, va_list element)
{
    int count = 0;

    if (c == '%') {
        if (write(1, "%", 1) != 1)
            return (-1);
        return (1);
    }

    count = type_var(c, element);
    if (count == -1)
        return (-1);
    return (count);
}

static int w_str(const char *str, va_list element, int count)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == '%' && str[i + 1] == '%') {
            if (write(1, "%", 1) != 1)
                return (-1);
            count++;
            i += 2;
        } else if (str[i] == '%') {
            count = w_str_percent(str[i + 1], element);
            if (count == -1)
                return (-1);
            i++;
        } else {
            if (write(1, &str[i], 1) != 1)
                return (-1);
            count++;
        }
        i++;
    }
    return (count);
}

int ft_printf(const char *str, ...)
{
    va_list element;
    int count = 0;

    va_start(element, str);
    count = w_str(str, element, count);
    va_end(element);
    return (count);
}

static int type_var(char c, va_list element)
{
    if (c == 'c')
        return (ft_print_char(va_arg(element, int)));
    if (c == 's')
        return (ft_print_str(va_arg(element, char *)));
    if (c == 'p')
        return (ft_print_ptr(va_arg(element, void *)));
    if (c == 'd' || c == 'i')
        return (ft_print_nbr(va_arg(element, int)));
    if (c == 'u')
        return (ft_print_unsigned(va_arg(element, unsigned int)));
    if (c == 'x')
        return (ft_hexa_minus(va_arg(element, unsigned int)));
    if (c == 'X')
        return (ft_hexa_mayus(va_arg(element, unsigned int)));
    return (0);
}


int main(void)
{
    // Pruebas básicas
    ft_printf("Hola mundo!\n");
    ft_printf("Número entero: %d\n", 42);
    ft_printf("Carácter: %c\n", 'A');
    ft_printf("Cadena: %s\n", "Esto es una prueba");

    // Pruebas de formatos especiales
    ft_printf("Porcentaje: %%\n");
    ft_printf("Hexadecimal (minúsculas): %x\n", 255);
    ft_printf("Hexadecimal (mayúsculas): %X\n", 255);
    ft_printf("Puntero: %p\n", (void *)main);

    // Pruebas combinadas
    ft_printf("Mi nombre es %s y tengo %d años.\n", "Juan", 25);
    ft_printf("Valor sin signo: %u\n", 4294967295);

    return 0;
}