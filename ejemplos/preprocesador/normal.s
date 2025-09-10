# --- Directivas de Ensamblador (Metadatos) ---
    .file   "loop.c"                # Indica el nombre del archivo fuente original.
    .text                           # Declara que la siguiente sección contiene código ejecutable.
    .section    .rodata             # Declara una sección de datos de solo lectura.
.LC0:
    .string "Suma: %d\n"            # Define la cadena de formato para printf y le asigna la etiqueta .LC0.
    .text                           # Vuelve a la sección de código.
    .globl  main                    # Hace que el símbolo 'main' sea visible para el enlazador.
    .type   main, @function         # Declara que 'main' es una función.

# --- Inicio de la función main y configuración del Stack Frame ---
main:
.LFB0:
    .cfi_startproc                  # Información para el depurador sobre el inicio de la función.
    pushq   %rbp                    # Guarda el puntero base anterior (%rbp) en la pila.
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq    %rsp, %rbp              # Establece el nuevo puntero base (%rbp) en la posición actual de la pila (%rsp).
    .cfi_def_cfa_register 6
    subq    $416, %rsp              # Reserva 416 bytes en la pila: 400 para el array y 16 para variables locales.

# --- Bucle 1: Inicialización del array (for i = 0; i < 100; i++) ---
# Este es un bucle for clásico, sin ninguna optimización.

    movl    $0, -4(%rbp)            # Inicializa la variable del contador 'i' a 0. La guarda en la pila en [-4(%rbp)].
    jmp .L2                         # Salta a la condición del bucle por primera vez.
.L3:                                # Etiqueta del cuerpo del bucle de inicialización.
    movl    -4(%rbp), %eax          # Carga el valor de 'i' en el registro %eax.
    cltq                            # Extiende el valor de 32 bits de %eax a 64 bits en %rax (para cálculo de dirección).
    movl    -4(%rbp), %edx          # Carga el valor de 'i' de nuevo en %edx.
    movl    %edx, -416(%rbp,%rax,4) # Guarda 'i' en la posición del array: array[i] = i.
    addl    $1, -4(%rbp)            # Incrementa 'i' en 1 (i++).
.L2:                                # Etiqueta de la condición del bucle.
    cmpl    $99, -4(%rbp)           # Compara 'i' con 99.
    jle .L3                         # Si 'i' es menor o igual a 99 (i <= 99), salta de nuevo al cuerpo del bucle (.L3).

# --- Bucle 2: Suma de los elementos del array ---
# Este es el segundo bucle for, también sin optimizar.

    movl    $0, -8(%rbp)            # Inicializa la variable 'suma' a 0. La guarda en la pila en [-8(%rbp)].
    movl    $0, -12(%rbp)           # Inicializa el segundo contador 'i' a 0. La guarda en [-12(%rbp)].
    jmp .L4                         # Salta a la condición del segundo bucle.
.L5:                                # Etiqueta del cuerpo del bucle de suma.
    movl    -12(%rbp), %eax         # Carga el contador 'i' en %eax.
    cltq                            # Extiende a 64 bits en %rax.
    movl    -416(%rbp,%rax,4), %eax # Carga el valor de array[i] en %eax.
    addl    %eax, -8(%rbp)          # Suma el valor de array[i] a la variable 'suma' (suma += array[i]).
    addl    $1, -12(%rbp)           # Incrementa el contador 'i' en 1 (i++).
.L4:                                # Etiqueta de la condición del segundo bucle.
    cmpl    $99, -12(%rbp)          # Compara 'i' con 99.
    jle .L5                         # Si 'i' es menor o igual a 99, salta de nuevo al cuerpo del bucle (.L5).

# --- Llamada a printf ---
    movl    -8(%rbp), %eax          # Carga el resultado final de 'suma' en %eax.
    movl    %eax, %esi              # Mueve el resultado a %esi (segundo argumento para printf).
    movl    $.LC0, %edi             # Carga la dirección de la cadena "Suma: %d\n" en %edi (primer argumento).
    movl    $0, %eax                # Pone a cero %eax (requerido por la convención de llamada para printf).
    call    printf                  # Llama a la función printf.

# --- Limpieza y retorno ---
    movl    $0, %eax                # Establece el valor de retorno de main a 0.
    leave                           # Restaura el puntero de la pila (%rsp) y el puntero base (%rbp) a su estado anterior.
    .cfi_def_cfa 7, 8
    ret                             # Retorna de la función main.
    .cfi_endproc                    # Fin de la información de la función.
.LFE0:
    .size   main, .-main            # Define el tamaño de la función main.

# --- Metadatos Finales ---
    .ident  "GCC: (GNU) 15.2.1 20250808 (Red Hat 15.2.1-1)" # Identificador del compilador.
    .section    .note.GNU-stack,"",@progbits # Información sobre la pila.
