# Makefile para compilación modular

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic

# Archivos
OBJS = main.o matematica.o utilidades.o
TARGET = programa

# Regla principal
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Reglas para archivos objeto
main.o: main.c matematica.h utilidades.h
	$(CC) $(CFLAGS) -c main.c

matematica.o: matematica.c matematica.h
	$(CC) $(CFLAGS) -c matematica.c

utilidades.o: utilidades.c utilidades.h
	$(CC) $(CFLAGS) -c utilidades.c

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Recompilar todo desde cero
rebuild: clean $(TARGET)

.PHONY: clean rebuild
