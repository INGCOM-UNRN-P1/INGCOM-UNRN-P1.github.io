# Definición de variables
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = programa

# Definir el objetivo por defecto (la primera regla)
$(TARGET): main.o funciones.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o funciones.o

# Regla para compilar main.c en main.o
main.o: main.c funciones.h
	$(CC) $(CFLAGS) -c main.c

# Regla para compilar funciones.c en funciones.o (vean que depende de dos archivos)
funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c

# Limpiar los archivos generados
clean:
	rm -f *.o $(TARGET)

