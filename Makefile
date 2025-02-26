#Nombre de la libreria
NAME = libftprintf.a 

#Directorios de los archivos con las funciones.
SRCS_DIR = srcs

#Directorio de las librerias personales (Si es que tenemos)
INCLUDES_DIR = includes 

#Archivos con las funciones
SRCS = $(SRCS_DIR)/ft_print_char.c $(SRCS_DIR)/ft_print_str.c $(SRCS_DIR)/ft_print_nbr.c $(SRCS_DIR)/ft_print_unsigned.c $(SRCS_DIR)/ft_hexa_minus.c $(SRCS_DIR)/ft_hexa_mayus.c $(SRCS_DIR)/ft_print_ptr.c

#Variable que guarda los objetos generados a partir de los archivos .c
OBJS = $(SRCS:.c=.o)

#Compilador que se va a usar
CC = gcc

#Las flags que se van a utilizar a la hora de compilar los recursos
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)

# Configuración de la librería libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

#Comando que compila los archivos .c a archivos .o (Objetos)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT)

#Comando final que se ejecuta
%.o: %.c $(INCLUDES_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#Parametros adicionales para el comando make:
#Elimina los objetos (.o)
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean


#Elimina los objetos y la librería generada
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


#Elimina los objetos, la libreria generada y lo compila todo de nuevo
re: fclean all

# Regla para compilar y probar con main.c
test: all
	$(CC) main.c -L. -lftprintf -L$(LIBFT_DIR) -lft -o programa
	./programa


#Ejemplos:
#make clean
#make fclean
#make re
