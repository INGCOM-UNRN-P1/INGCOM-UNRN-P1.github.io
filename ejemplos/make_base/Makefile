
# Definir el objetivo por defecto
programa: main.o
	gcc -Wall -Wextra -o programa main.o

# Regla para compilar main.c en main.o
main.o: main.c
	gcc -Wall -Wextra -g -c main.c

run: programa
	./programa

# Regla de limpieza
clean:
	rm -f *.o programa

