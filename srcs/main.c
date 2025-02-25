#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int main(){
    char c = 's';
    int res = ft_print_char(c);

    printf("resultado: %c", res);
    return (0);
}