#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

//int main(){
//    char c = 'h';
//    ft_print_char(c);
//    return (0);
//}


//int main()
//{
//    int nbr = -6;
//    ft_print_nbr(nbr);
//    return (0);
//}

//int main(){
//    char *str = "hola mundo";
//    ft_print_str(str);
//    return (0);
//}

//int main()
//{
//    unsigned int nbr = 3634746438;
//    ft_print_unsigned(nbr);
//    return (0);
//}

//int main(){
//    unsigned int n = 252;
//    ft_hexa_minus(n);
//    return (0);
//}

//int main()
//{
//    unsigned int n = 252;
//    ft_hexa_mayus(n);
//    return (0);
//}

//int main() {
//    int num = 79;
//    int *ptr = &num;
//
//    ft_print_ptr(ptr);
//    write(1, "\n", 1);
//
//    ft_print_ptr(NULL);
//    return(0);
//}

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