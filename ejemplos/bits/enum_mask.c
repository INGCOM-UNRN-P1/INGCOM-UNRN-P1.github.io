#include <stdio.h>

// Definición de la Bitmask usando un enum
// Los valores se asignan manualmente como potencias de 2 (2^0, 2^1, 2^2, ...)
// Esto garantiza que solo un bit esté activo por cada constante.
typedef enum {
    // Binario: 0001
    PERMISO_LECTURA   = 1 << 0,  // O simplemente 1
    
    // Binario: 0010
    PERMISO_ESCRITURA = 1 << 1,  // O simplemente 2
    
    // Binario: 0100
    PERMISO_EJECUCION = 1 << 2,  // O simplemente 4
    
    // Binario: 1000. Una constante adicional para un permiso compuesto si se necesita.
    PERMISO_AUDITORIA = 1 << 3   // O simplemente 8
} permiso_t;

// Función de ejemplo para verificar un permiso
void verificar_permiso(int permisos_actuales, permiso_t permiso_requerido) {
    // Se utiliza el operador AND a nivel de bit (&)
    // para verificar si el bit de permiso_requerido está ACTIVO
    // dentro del conjunto de permisos_actuales.
    if (permisos_actuales & permiso_requerido) {
        printf("-> OK: El permiso (Valor: %d) esta concedido.\n", permiso_requerido);
    } else {
        printf("-> FALLO: El permiso (Valor: %d) no esta concedido.\n", permiso_requerido);
    }
}

int main() {
    // 1. Declaración de la variable
    // Utilizamos un entero (generalmente 'int' o 'unsigned int') para almacenar la máscara.
    
    // 2. Asignación de permisos
    // Se utiliza el operador OR a nivel de bit (|) para COMBINAR múltiples permisos.
    // Combinacion binaria: 0001 | 0010 = 0011 (Valor decimal: 3)
    int permisos_usuario = PERMISO_LECTURA | PERMISO_ESCRITURA;
    
    printf("Permisos actuales (Valor Decimal): %d\n", permisos_usuario);
    printf("Permisos actuales (Binario): 0b%d%d%d%d\n", 
           (permisos_usuario & PERMISO_AUDITORIA) >> 3,
           (permisos_usuario & PERMISO_EJECUCION) >> 2,
           (permisos_usuario & PERMISO_ESCRITURA) >> 1,
           (permisos_usuario & PERMISO_LECTURA) >> 0);
    
    printf("------------------------------------------\n");

    // 3. Verificación de permisos
    verificar_permiso(permisos_usuario, PERMISO_LECTURA);    // Debería ser OK
    verificar_permiso(permisos_usuario, PERMISO_EJECUCION);  // Debería ser FALLO
    
    // 4. Modificación de permisos (Añadir un permiso)
    // Se utiliza el operador OR a nivel de bit (|) para activar un nuevo bit.
    permisos_usuario |= PERMISO_EJECUCION;
    printf("\nSe ha anadido PERMISO_EJECUCION (Nuevo valor: %d)\n", permisos_usuario);
    
    // 5. Verificación después de la modificación
    verificar_permiso(permisos_usuario, PERMISO_EJECUCION);  // Ahora debería ser OK
    
    // 6. Revocar un permiso (Desactivar un bit)
    // Se utiliza AND a nivel de bit (&) con la negación a nivel de bit (~) del permiso.
    permisos_usuario &= ~PERMISO_LECTURA;
    printf("\nSe ha revocado PERMISO_LECTURA (Nuevo valor: %d)\n", permisos_usuario);
    
    verificar_permiso(permisos_usuario, PERMISO_LECTURA);    // Ahora debería ser FALLO

    return 0;
}