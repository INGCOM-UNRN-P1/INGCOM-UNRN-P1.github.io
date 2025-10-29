---
title: Programación de Sockets en C
short_title: Sockets POSIX
subtitle: Comunicación de red en sistemas Unix/Linux
---

## Introducción a la Programación de Red

Los **sockets** son el mecanismo fundamental para la comunicación entre procesos a través de una red (o en la misma máquina). Proporcionan una abstracción que permite que programas intercambien datos usando protocolos como TCP e UDP, ocultando los detalles de bajo nivel de la comunicación de red.

### ¿Qué es un Socket?

Un socket es un **punto final de comunicación** bidireccional. Podés pensarlo como un "archivo especial" que permite leer y escribir datos que viajan por la red.

**Analogía:** Si los procesos son casas, los sockets son las puertas y ventanas por donde entra y sale información.

### Tipos de Sockets

#### 1. Stream Sockets (TCP)

- **Protocolo:** TCP (Transmission Control Protocol)
- **Características:**
  - Orientado a conexión (handshake)
  - Confiable: garantiza entrega y orden
  - Bidireccional
  - Control de flujo y congestión
- **Usos:** HTTP, HTTPS, SSH, FTP, correo electrónico

```c
socket(AF_INET, SOCK_STREAM, 0);  // TCP
```

#### 2. Datagram Sockets (UDP)

- **Protocolo:** UDP (User Datagram Protocol)
- **Características:**
  - Sin conexión
  - No confiable: puede perder paquetes
  - Sin orden garantizado
  - Más rápido y ligero
- **Usos:** DNS, streaming de video, juegos en línea, VoIP

```c
socket(AF_INET, SOCK_DGRAM, 0);  // UDP
```

### Comparación TCP vs. UDP

| Característica | TCP | UDP |
|----------------|-----|-----|
| Conexión | Orientado a conexión | Sin conexión |
| Confiabilidad | Garantiza entrega | Puede perder paquetes |
| Orden | Preserva orden | Sin garantía de orden |
| Velocidad | Más lento (overhead) | Más rápido |
| Overhead | Mayor | Menor |
| Control de flujo | Sí | No |
| Casos de uso | Transferencia de archivos, web | Streaming, juegos |

:::{important}
TCP es como una llamada telefónica: establecés conexión, conversás, y colgás.  
UDP es como enviar postales: mandás el mensaje sin garantía de que llegue o en qué orden.
:::

## Conceptos Fundamentales

### Direcciones y Puertos

#### Dirección IP

Identifica un dispositivo en la red:
- **IPv4:** `192.168.1.100` (32 bits, 4 bytes)
- **IPv6:** `2001:0db8:85a3:0000:0000:8a2e:0370:7334` (128 bits)

#### Puerto

Identifica una aplicación específica en un dispositivo:
- Número de 16 bits: 0-65535
- **Puertos bien conocidos (0-1023):** HTTP (80), HTTPS (443), SSH (22), FTP (21)
- **Puertos registrados (1024-49151):** Asignados por IANA
- **Puertos dinámicos (49152-65535):** Uso temporal

```
Conexión = (IP origen, puerto origen, IP destino, puerto destino)
```

### Familias de Direcciones

- **AF_INET:** IPv4
- **AF_INET6:** IPv6
- **AF_UNIX:** Comunicación local (Unix domain sockets)

### Orden de Bytes (Endianness)

Las computadoras pueden almacenar números de diferentes formas:
- **Big-endian (orden de red):** Byte más significativo primero
- **Little-endian (orden de host):** Byte menos significativo primero

**Funciones de conversión:**

```c
#include <arpa/inet.h>

// Host to Network
uint32_t htonl(uint32_t hostlong);   // long (32 bits)
uint16_t htons(uint16_t hostshort);  // short (16 bits)

// Network to Host
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);
```

**Ejemplo:**
```c
uint16_t puerto_host = 8080;
uint16_t puerto_red = htons(puerto_host);  // Convertir a orden de red
```

:::{warning}
**Siempre** convertir puertos y direcciones IP a orden de red antes de usarlos en estructuras de sockets.
:::

## Estructuras de Datos Principales

### `struct sockaddr`

Estructura genérica para direcciones:

```c
struct sockaddr {
    sa_family_t sa_family;  // Familia de direcciones (AF_INET, AF_INET6, etc.)
    char sa_data[14];       // Datos específicos de la familia
};
```

### `struct sockaddr_in` (IPv4)

```c
#include <netinet/in.h>

struct sockaddr_in {
    sa_family_t    sin_family;  // AF_INET
    in_port_t      sin_port;    // Puerto en orden de red
    struct in_addr sin_addr;    // Dirección IPv4
    char           sin_zero[8]; // Padding (debe ser cero)
};

struct in_addr {
    uint32_t s_addr;  // Dirección en orden de red
};
```

### `struct sockaddr_in6` (IPv6)

```c
struct sockaddr_in6 {
    sa_family_t     sin6_family;   // AF_INET6
    in_port_t       sin6_port;     // Puerto
    uint32_t        sin6_flowinfo; // Información de flujo IPv6
    struct in6_addr sin6_addr;     // Dirección IPv6
    uint32_t        sin6_scope_id; // Scope ID
};
```

### `struct addrinfo`

Usada para resolver nombres de host:

```c
struct addrinfo {
    int              ai_flags;
    int              ai_family;    // AF_INET, AF_INET6, AF_UNSPEC
    int              ai_socktype;  // SOCK_STREAM, SOCK_DGRAM
    int              ai_protocol;
    socklen_t        ai_addrlen;
    struct sockaddr *ai_addr;
    char            *ai_canonname;
    struct addrinfo *ai_next;      // Lista enlazada
};
```

## API de Sockets: Funciones Fundamentales

### 1. Crear un Socket: `socket()`

```c
#include <sys/socket.h>

int socket(int domain, int type, int protocol);
```

**Parámetros:**
- `domain`: Familia de direcciones (AF_INET, AF_INET6, AF_UNIX)
- `type`: Tipo de socket (SOCK_STREAM, SOCK_DGRAM)
- `protocol`: Protocolo específico (0 para automático)

**Retorna:** Descriptor de archivo del socket, o -1 en error.

**Ejemplo:**
```c
int sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd == -1) {
    perror("socket");
    exit(1);
}
```

### 2. Vincular a una Dirección: `bind()`

Asocia el socket con una dirección IP y puerto específicos (servidor).

```c
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

**Ejemplo:**
```c
struct sockaddr_in servidor;
memset(&servidor, 0, sizeof(servidor));
servidor.sin_family = AF_INET;
servidor.sin_port = htons(8080);
servidor.sin_addr.s_addr = INADDR_ANY;  // Todas las interfaces

if (bind(sockfd, (struct sockaddr*)&servidor, sizeof(servidor)) == -1) {
    perror("bind");
    exit(1);
}
```

:::{note}
`INADDR_ANY` (valor 0) indica que el servidor escucha en todas las interfaces de red disponibles.
:::

### 3. Escuchar Conexiones: `listen()`

Marca el socket como pasivo, listo para aceptar conexiones (solo TCP).

```c
int listen(int sockfd, int backlog);
```

**Parámetros:**
- `sockfd`: Socket vinculado
- `backlog`: Número máximo de conexiones pendientes en cola

**Ejemplo:**
```c
if (listen(sockfd, 10) == -1) {
    perror("listen");
    exit(1);
}
```

### 4. Aceptar Conexión: `accept()`

Bloquea hasta que un cliente se conecte (solo TCP).

```c
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

**Retorna:** Nuevo descriptor de socket para comunicación con el cliente.

**Ejemplo:**
```c
struct sockaddr_in cliente;
socklen_t len = sizeof(cliente);

int cliente_fd = accept(sockfd, (struct sockaddr*)&cliente, &len);
if (cliente_fd == -1) {
    perror("accept");
    exit(1);
}

// Obtener información del cliente
char ip_cliente[INET_ADDRSTRLEN];
inet_ntop(AF_INET, &cliente.sin_addr, ip_cliente, sizeof(ip_cliente));
printf("Cliente conectado desde %s:%d\n", ip_cliente, ntohs(cliente.sin_port));
```

### 5. Conectar a un Servidor: `connect()`

Inicia conexión a un servidor remoto (cliente TCP, o asociar socket UDP).

```c
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

**Ejemplo:**
```c
struct sockaddr_in servidor;
memset(&servidor, 0, sizeof(servidor));
servidor.sin_family = AF_INET;
servidor.sin_port = htons(8080);
inet_pton(AF_INET, "127.0.0.1", &servidor.sin_addr);

if (connect(sockfd, (struct sockaddr*)&servidor, sizeof(servidor)) == -1) {
    perror("connect");
    exit(1);
}

printf("Conectado al servidor\n");
```

### 6. Enviar Datos: `send()` / `write()`

```c
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
ssize_t write(int sockfd, const void *buf, size_t count);
```

**Ejemplo:**
```c
const char *mensaje = "Hola, servidor!";
ssize_t enviados = send(sockfd, mensaje, strlen(mensaje), 0);
if (enviados == -1) {
    perror("send");
}
```

### 7. Recibir Datos: `recv()` / `read()`

```c
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
ssize_t read(int sockfd, void *buf, size_t count);
```

**Ejemplo:**
```c
char buffer[1024];
ssize_t recibidos = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
if (recibidos == -1) {
    perror("recv");
} else if (recibidos == 0) {
    printf("Conexión cerrada por el otro extremo\n");
} else {
    buffer[recibidos] = '\0';  // Null-terminar
    printf("Recibido: %s\n", buffer);
}
```

:::{important}
`recv()` retorna 0 cuando la conexión se cierra ordenadamente. Un valor -1 indica error.
:::

### 8. Cerrar Socket: `close()`

```c
#include <unistd.h>

int close(int sockfd);
```

**Ejemplo:**
```c
close(sockfd);
```

Para cerrar solo escritura o lectura:

```c
int shutdown(int sockfd, int how);
// how: SHUT_RD (lectura), SHUT_WR (escritura), SHUT_RDWR (ambos)
```

## Ejemplo Completo: Servidor TCP Echo

Un servidor que repite lo que recibe del cliente.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PUERTO 8080
#define BACKLOG 5
#define BUFFER_SIZE 1024

int main(void) {
    int servidor_fd, cliente_fd;
    struct sockaddr_in servidor, cliente;
    socklen_t cliente_len;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_recibidos;
    
    // 1. Crear socket
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // Permitir reutilizar la dirección inmediatamente
    int opt = 1;
    if (setsockopt(servidor_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    // 2. Configurar dirección del servidor
    memset(&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_port = htons(PUERTO);
    
    // 3. Vincular socket a la dirección
    if (bind(servidor_fd, (struct sockaddr*)&servidor, sizeof(servidor)) == -1) {
        perror("bind");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }
    
    // 4. Escuchar conexiones
    if (listen(servidor_fd, BACKLOG) == -1) {
        perror("listen");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Servidor escuchando en puerto %d...\n", PUERTO);
    
    // 5. Aceptar y manejar conexiones
    while (1) {
        cliente_len = sizeof(cliente);
        cliente_fd = accept(servidor_fd, (struct sockaddr*)&cliente, &cliente_len);
        
        if (cliente_fd == -1) {
            perror("accept");
            continue;
        }
        
        // Obtener información del cliente
        char ip_cliente[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &cliente.sin_addr, ip_cliente, sizeof(ip_cliente));
        printf("Cliente conectado: %s:%d\n", ip_cliente, ntohs(cliente.sin_port));
        
        // Recibir y reenviar datos (echo)
        while ((bytes_recibidos = recv(cliente_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
            buffer[bytes_recibidos] = '\0';
            printf("Recibido: %s", buffer);
            
            // Enviar de vuelta al cliente
            if (send(cliente_fd, buffer, bytes_recibidos, 0) == -1) {
                perror("send");
                break;
            }
        }
        
        if (bytes_recibidos == 0) {
            printf("Cliente desconectado\n");
        } else if (bytes_recibidos == -1) {
            perror("recv");
        }
        
        close(cliente_fd);
    }
    
    close(servidor_fd);
    return 0;
}
```

**Compilar y ejecutar:**
```bash
gcc -Wall -Wextra servidor_echo.c -o servidor_echo
./servidor_echo
```

## Ejemplo Completo: Cliente TCP

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PUERTO 8080
#define BUFFER_SIZE 1024

int main(void) {
    int sockfd;
    struct sockaddr_in servidor;
    char buffer[BUFFER_SIZE];
    char mensaje[BUFFER_SIZE];
    ssize_t bytes_recibidos;
    
    // 1. Crear socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // 2. Configurar dirección del servidor
    memset(&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PUERTO);
    
    // Convertir dirección IP de texto a binario
    if (inet_pton(AF_INET, "127.0.0.1", &servidor.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    // 3. Conectar al servidor
    if (connect(sockfd, (struct sockaddr*)&servidor, sizeof(servidor)) == -1) {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("Conectado al servidor. Escribe mensajes (Ctrl+D para salir):\n");
    
    // 4. Enviar y recibir mensajes
    while (fgets(mensaje, sizeof(mensaje), stdin) != NULL) {
        // Enviar mensaje al servidor
        if (send(sockfd, mensaje, strlen(mensaje), 0) == -1) {
            perror("send");
            break;
        }
        
        // Recibir respuesta del servidor
        bytes_recibidos = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_recibidos == -1) {
            perror("recv");
            break;
        } else if (bytes_recibidos == 0) {
            printf("Servidor cerró la conexión\n");
            break;
        }
        
        buffer[bytes_recibidos] = '\0';
        printf("Respuesta del servidor: %s", buffer);
    }
    
    close(sockfd);
    return 0;
}
```

**Probar:**
```bash
# Terminal 1
./servidor_echo

# Terminal 2
./cliente
Hola servidor
Respuesta del servidor: Hola servidor
```

## Sockets UDP (Datagram)

### Servidor UDP

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PUERTO 8080
#define BUFFER_SIZE 1024

int main(void) {
    int sockfd;
    struct sockaddr_in servidor, cliente;
    socklen_t cliente_len;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_recibidos;
    
    // Crear socket UDP
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // Configurar dirección
    memset(&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_port = htons(PUERTO);
    
    // Vincular
    if (bind(sockfd, (struct sockaddr*)&servidor, sizeof(servidor)) == -1) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("Servidor UDP escuchando en puerto %d...\n", PUERTO);
    
    // Recibir y responder datagramas
    while (1) {
        cliente_len = sizeof(cliente);
        bytes_recibidos = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                                   (struct sockaddr*)&cliente, &cliente_len);
        
        if (bytes_recibidos == -1) {
            perror("recvfrom");
            continue;
        }
        
        buffer[bytes_recibidos] = '\0';
        
        char ip_cliente[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &cliente.sin_addr, ip_cliente, sizeof(ip_cliente));
        printf("Recibido de %s:%d: %s", ip_cliente, ntohs(cliente.sin_port), buffer);
        
        // Enviar respuesta
        if (sendto(sockfd, buffer, bytes_recibidos, 0,
                   (struct sockaddr*)&cliente, cliente_len) == -1) {
            perror("sendto");
        }
    }
    
    close(sockfd);
    return 0;
}
```

### Cliente UDP

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PUERTO 8080
#define BUFFER_SIZE 1024

int main(void) {
    int sockfd;
    struct sockaddr_in servidor;
    socklen_t servidor_len;
    char buffer[BUFFER_SIZE];
    char mensaje[BUFFER_SIZE];
    ssize_t bytes_recibidos;
    
    // Crear socket UDP
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // Configurar dirección del servidor
    memset(&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PUERTO);
    inet_pton(AF_INET, "127.0.0.1", &servidor.sin_addr);
    
    printf("Cliente UDP. Escribe mensajes (Ctrl+D para salir):\n");
    
    while (fgets(mensaje, sizeof(mensaje), stdin) != NULL) {
        // Enviar datagrama
        servidor_len = sizeof(servidor);
        if (sendto(sockfd, mensaje, strlen(mensaje), 0,
                   (struct sockaddr*)&servidor, servidor_len) == -1) {
            perror("sendto");
            break;
        }
        
        // Recibir respuesta
        bytes_recibidos = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                                   (struct sockaddr*)&servidor, &servidor_len);
        if (bytes_recibidos == -1) {
            perror("recvfrom");
            break;
        }
        
        buffer[bytes_recibidos] = '\0';
        printf("Respuesta: %s", buffer);
    }
    
    close(sockfd);
    return 0;
}
```

## Resolución de Nombres: `getaddrinfo()`

En lugar de codificar IPs, usá `getaddrinfo()` para resolver nombres de host.

```c
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int getaddrinfo(const char *node, const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res);
```

### Ejemplo: Cliente Moderno con `getaddrinfo()`

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <host> <puerto>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *host = argv[1];
    const char *puerto = argv[2];
    
    struct addrinfo hints, *res, *p;
    int sockfd, status;
    
    // Configurar hints
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;     // IPv4 o IPv6
    hints.ai_socktype = SOCK_STREAM;  // TCP
    
    // Resolver nombre
    status = getaddrinfo(host, puerto, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }
    
    // Intentar conectar con cada dirección obtenida
    for (p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) != -1) {
            break;  // Conectado exitosamente
        }
        
        close(sockfd);
    }
    
    if (p == NULL) {
        fprintf(stderr, "No se pudo conectar\n");
        freeaddrinfo(res);
        exit(EXIT_FAILURE);
    }
    
    printf("Conectado a %s:%s\n", host, puerto);
    
    // Usar el socket...
    const char *mensaje = "GET / HTTP/1.0\r\n\r\n";
    send(sockfd, mensaje, strlen(mensaje), 0);
    
    char buffer[4096];
    ssize_t n;
    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    
    close(sockfd);
    freeaddrinfo(res);
    
    return 0;
}
```

**Probar:**
```bash
./cliente_http www.example.com 80
```

## Servidor Concurrente con Múltiples Clientes

### Opción 1: Fork (Multiproceso)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>

#define PUERTO 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

void manejar_cliente(int cliente_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes;
    
    while ((bytes = recv(cliente_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("[PID %d] Recibido: %s", getpid(), buffer);
        send(cliente_fd, buffer, bytes, 0);
    }
    
    close(cliente_fd);
    exit(0);
}

void manejador_sigchld(int sig) {
    (void)sig;
    // Recolectar procesos hijo zombies
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main(void) {
    int servidor_fd, cliente_fd;
    struct sockaddr_in servidor, cliente;
    socklen_t cliente_len;
    
    // Configurar manejador de SIGCHLD
    signal(SIGCHLD, manejador_sigchld);
    
    // Crear y configurar servidor
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    int opt = 1;
    setsockopt(servidor_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    memset(&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_port = htons(PUERTO);
    
    if (bind(servidor_fd, (struct sockaddr*)&servidor, sizeof(servidor)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    if (listen(servidor_fd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Servidor multiproceso escuchando en puerto %d...\n", PUERTO);
    
    while (1) {
        cliente_len = sizeof(cliente);
        cliente_fd = accept(servidor_fd, (struct sockaddr*)&cliente, &cliente_len);
        
        if (cliente_fd == -1) {
            perror("accept");
            continue;
        }
        
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &cliente.sin_addr, ip, sizeof(ip));
        printf("Cliente conectado: %s:%d\n", ip, ntohs(cliente.sin_port));
        
        pid_t pid = fork();
        
        if (pid == -1) {
            perror("fork");
            close(cliente_fd);
        } else if (pid == 0) {
            // Proceso hijo
            close(servidor_fd);  // No necesita el socket servidor
            manejar_cliente(cliente_fd);
        } else {
            // Proceso padre
            close(cliente_fd);  // No necesita el socket cliente
        }
    }
    
    close(servidor_fd);
    return 0;
}
```

### Opción 2: Threads (Multihilo)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PUERTO 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

void* manejar_cliente(void* arg) {
    int cliente_fd = *(int*)arg;
    free(arg);
    
    pthread_detach(pthread_self());  // Auto-limpieza
    
    char buffer[BUFFER_SIZE];
    ssize_t bytes;
    
    while ((bytes = recv(cliente_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("[Thread %lu] Recibido: %s", pthread_self(), buffer);
        send(cliente_fd, buffer, bytes, 0);
    }
    
    close(cliente_fd);
    return NULL;
}

int main(void) {
    int servidor_fd, cliente_fd;
    struct sockaddr_in servidor, cliente;
    socklen_t cliente_len;
    
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    int opt = 1;
    setsockopt(servidor_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    memset(&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_port = htons(PUERTO);
    
    if (bind(servidor_fd, (struct sockaddr*)&servidor, sizeof(servidor)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    if (listen(servidor_fd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Servidor multihilo escuchando en puerto %d...\n", PUERTO);
    
    while (1) {
        cliente_len = sizeof(cliente);
        cliente_fd = accept(servidor_fd, (struct sockaddr*)&cliente, &cliente_len);
        
        if (cliente_fd == -1) {
            perror("accept");
            continue;
        }
        
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &cliente.sin_addr, ip, sizeof(ip));
        printf("Cliente conectado: %s:%d\n", ip, ntohs(cliente.sin_port));
        
        // Crear thread para manejar cliente
        pthread_t thread_id;
        int* cliente_fd_ptr = malloc(sizeof(int));
        *cliente_fd_ptr = cliente_fd;
        
        if (pthread_create(&thread_id, NULL, manejar_cliente, cliente_fd_ptr) != 0) {
            perror("pthread_create");
            close(cliente_fd);
            free(cliente_fd_ptr);
        }
    }
    
    close(servidor_fd);
    return 0;
}
```

**Compilar con threads:**
```bash
gcc -Wall -pthread servidor_threads.c -o servidor_threads
```

## Multiplexación de E/S: `select()` y `poll()`

Para manejar múltiples conexiones sin threads ni procesos.

### Servidor con `select()`

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#define PUERTO 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024
#define MAX_CLIENTES 30

int main(void) {
    int servidor_fd, cliente_fd, max_fd, actividad, i;
    int clientes[MAX_CLIENTES];
    struct sockaddr_in servidor, cliente;
    socklen_t cliente_len;
    char buffer[BUFFER_SIZE];
    fd_set read_fds;
    
    // Inicializar array de clientes
    for (i = 0; i < MAX_CLIENTES; i++) {
        clientes[i] = 0;
    }
    
    // Crear servidor
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    int opt = 1;
    setsockopt(servidor_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    memset(&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_port = htons(PUERTO);
    
    if (bind(servidor_fd, (struct sockaddr*)&servidor, sizeof(servidor)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    if (listen(servidor_fd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Servidor con select() escuchando en puerto %d...\n", PUERTO);
    
    while (1) {
        // Limpiar el conjunto de descriptores
        FD_ZERO(&read_fds);
        
        // Agregar socket servidor
        FD_SET(servidor_fd, &read_fds);
        max_fd = servidor_fd;
        
        // Agregar sockets clientes
        for (i = 0; i < MAX_CLIENTES; i++) {
            int sd = clientes[i];
            
            if (sd > 0) {
                FD_SET(sd, &read_fds);
            }
            
            if (sd > max_fd) {
                max_fd = sd;
            }
        }
        
        // Esperar actividad en algún socket
        actividad = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        
        if (actividad < 0) {
            perror("select");
            continue;
        }
        
        // Nueva conexión entrante
        if (FD_ISSET(servidor_fd, &read_fds)) {
            cliente_len = sizeof(cliente);
            cliente_fd = accept(servidor_fd, (struct sockaddr*)&cliente, &cliente_len);
            
            if (cliente_fd < 0) {
                perror("accept");
                continue;
            }
            
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &cliente.sin_addr, ip, sizeof(ip));
            printf("Nueva conexión: %s:%d (socket %d)\n", 
                   ip, ntohs(cliente.sin_port), cliente_fd);
            
            // Agregar a array de clientes
            for (i = 0; i < MAX_CLIENTES; i++) {
                if (clientes[i] == 0) {
                    clientes[i] = cliente_fd;
                    printf("Agregado a lista en posición %d\n", i);
                    break;
                }
            }
            
            if (i == MAX_CLIENTES) {
                printf("Máximo de clientes alcanzado. Conexión rechazada.\n");
                close(cliente_fd);
            }
        }
        
        // Operación de E/S en algún cliente
        for (i = 0; i < MAX_CLIENTES; i++) {
            int sd = clientes[i];
            
            if (FD_ISSET(sd, &read_fds)) {
                ssize_t bytes = recv(sd, buffer, BUFFER_SIZE - 1, 0);
                
                if (bytes == 0) {
                    // Cliente desconectado
                    getpeername(sd, (struct sockaddr*)&cliente, &cliente_len);
                    char ip[INET_ADDRSTRLEN];
                    inet_ntop(AF_INET, &cliente.sin_addr, ip, sizeof(ip));
                    printf("Cliente desconectado: %s:%d\n", ip, ntohs(cliente.sin_port));
                    
                    close(sd);
                    clientes[i] = 0;
                } else {
                    // Datos recibidos
                    buffer[bytes] = '\0';
                    printf("Recibido: %s", buffer);
                    send(sd, buffer, bytes, 0);  // Echo
                }
            }
        }
    }
    
    close(servidor_fd);
    return 0;
}
```

:::{note}
`select()` tiene limitaciones (máximo 1024 descriptores en muchos sistemas). Para escalar mejor, usá `poll()` o `epoll()` (específico de Linux).
:::

## Opciones de Socket: `setsockopt()`

Configurar comportamiento del socket.

```c
int setsockopt(int sockfd, int level, int optname, 
               const void *optval, socklen_t optlen);
```

### Opciones Comunes

#### SO_REUSEADDR

Permite reutilizar dirección inmediatamente (evita "Address already in use"):

```c
int opt = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
```

#### SO_REUSEPORT

Permite múltiples sockets vinculados al mismo puerto:

```c
int opt = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));
```

#### SO_RCVBUF / SO_SNDBUF

Tamaño de buffers de recepción/envío:

```c
int buffer_size = 65536;
setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &buffer_size, sizeof(buffer_size));
```

#### SO_KEEPALIVE

Mantener conexión activa (TCP):

```c
int opt = 1;
setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &opt, sizeof(opt));
```

#### TCP_NODELAY

Deshabilitar algoritmo de Nagle (envío inmediato):

```c
int opt = 1;
setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &opt, sizeof(opt));
```

## Sockets No Bloqueantes

Por defecto, operaciones como `accept()` y `recv()` son bloqueantes.

### Hacer Socket No Bloqueante

```c
#include <fcntl.h>

int flags = fcntl(sockfd, F_GETFL, 0);
fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
```

Ahora, `recv()` retorna inmediatamente con -1 y `errno` = `EWOULDBLOCK` si no hay datos.

### Ejemplo con No Bloqueante

```c
#include <errno.h>

char buffer[1024];
ssize_t n = recv(sockfd, buffer, sizeof(buffer), 0);

if (n == -1) {
    if (errno == EWOULDBLOCK || errno == EAGAIN) {
        printf("No hay datos disponibles ahora\n");
    } else {
        perror("recv");
    }
}
```

## Manejo de Errores Comunes

### "Address already in use"

**Causa:** El puerto sigue vinculado a un proceso anterior.

**Solución:**
```c
int opt = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
```

### "Connection refused"

**Causa:** No hay servidor escuchando en ese puerto.

**Solución:** Verificar que el servidor esté ejecutándose y en el puerto correcto.

### "Broken pipe" (SIGPIPE)

**Causa:** Intentar escribir en un socket cerrado.

**Solución:** Ignorar la señal o manejarla:
```c
signal(SIGPIPE, SIG_IGN);  // Ignorar
```

O usar flag `MSG_NOSIGNAL`:
```c
send(sockfd, buffer, len, MSG_NOSIGNAL);
```

### Recv retorna 0

**Causa:** Conexión cerrada por el otro extremo.

**Solución:** Cerrar el socket localmente:
```c
if (recv(sockfd, buffer, sizeof(buffer), 0) == 0) {
    printf("Conexión cerrada\n");
    close(sockfd);
}
```

## Protocolo de Aplicación Simple

Un ejemplo de protocolo personalizado para un chat.

### Formato de Mensaje

```
[longitud:4 bytes][tipo:1 byte][datos:N bytes]
```

### Servidor de Chat

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PUERTO 8080
#define MAX_CLIENTES 10
#define BUFFER_SIZE 1024

typedef enum {
    MSG_TEXTO = 1,
    MSG_NOMBRE = 2,
    MSG_SALIR = 3
} tipo_mensaje_t;

typedef struct {
    int sockfd;
    char nombre[50];
} cliente_t;

cliente_t clientes[MAX_CLIENTES];
int num_clientes = 0;

void broadcast(const char* mensaje, int remitente_fd) {
    for (int i = 0; i < num_clientes; i++) {
        if (clientes[i].sockfd != remitente_fd) {
            send(clientes[i].sockfd, mensaje, strlen(mensaje), 0);
        }
    }
}

void manejar_mensaje(int cliente_fd, char* buffer, ssize_t len) {
    // Formato simple: tipo:contenido
    char tipo = buffer[0];
    char* contenido = buffer + 2;  // Saltar "tipo:"
    
    if (tipo == MSG_TEXTO) {
        char mensaje[BUFFER_SIZE];
        snprintf(mensaje, sizeof(mensaje), "%s: %s", 
                 clientes[cliente_fd].nombre, contenido);
        printf("%s", mensaje);
        broadcast(mensaje, cliente_fd);
    }
}

int main(void) {
    // Implementación completa del servidor de chat...
    printf("Servidor de chat en puerto %d\n", PUERTO);
    // ... código del servidor ...
    return 0;
}
```

## Depuración y Herramientas

### netstat / ss

Ver sockets activos:

```bash
netstat -tuln    # Todos los sockets escuchando
ss -tuln         # Alternativa moderna
```

### tcpdump / Wireshark

Capturar y analizar tráfico de red:

```bash
sudo tcpdump -i lo port 8080 -XX
```

### telnet / nc (netcat)

Probar servidores manualmente:

```bash
telnet localhost 8080
nc localhost 8080
```

### strace

Ver llamadas al sistema:

```bash
strace ./servidor
strace -e trace=network ./cliente
```

### lsof

Ver archivos abiertos (incluye sockets):

```bash
lsof -i :8080         # Qué proceso usa el puerto 8080
lsof -i -n -P        # Todos los sockets
```

## Mejores Prácticas

### 1. Siempre Verificar Retornos

```c
if (send(sockfd, buffer, len, 0) == -1) {
    perror("send");
    // Manejar error
}
```

### 2. Usar `SO_REUSEADDR` en Servidores

```c
int opt = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
```

### 3. Cerrar Sockets Apropiadamente

```c
shutdown(sockfd, SHUT_RDWR);
close(sockfd);
```

### 4. Manejar Señales

```c
signal(SIGPIPE, SIG_IGN);  // Ignorar broken pipe
```

### 5. Timeout en Operaciones

```c
struct timeval timeout;
timeout.tv_sec = 5;
timeout.tv_usec = 0;
setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
```

### 6. Validar Entrada del Usuario

Nunca confiar en datos recibidos por la red:

```c
if (bytes_recibidos >= BUFFER_SIZE) {
    fprintf(stderr, "Mensaje demasiado largo\n");
    return;
}
buffer[bytes_recibidos] = '\0';  // Null-terminar
```

### 7. Manejo de Envío Parcial

`send()` puede no enviar todos los bytes:

```c
ssize_t enviar_completo(int sockfd, const void *buf, size_t len) {
    size_t total = 0;
    size_t restante = len;
    ssize_t n;
    
    while (total < len) {
        n = send(sockfd, buf + total, restante, 0);
        if (n == -1) {
            if (errno == EINTR) continue;  // Interrumpido, reintentar
            return -1;
        }
        total += n;
        restante -= n;
    }
    
    return total;
}
```

## Ejemplo Avanzado: Servidor HTTP Minimalista

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PUERTO 8080
#define BUFFER_SIZE 4096

void enviar_respuesta(int cliente_fd, const char* contenido) {
    char encabezado[256];
    snprintf(encabezado, sizeof(encabezado),
             "HTTP/1.1 200 OK\r\n"
             "Content-Type: text/html; charset=UTF-8\r\n"
             "Content-Length: %zu\r\n"
             "Connection: close\r\n"
             "\r\n",
             strlen(contenido));
    
    send(cliente_fd, encabezado, strlen(encabezado), 0);
    send(cliente_fd, contenido, strlen(contenido), 0);
}

void manejar_solicitud(int cliente_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes = recv(cliente_fd, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes <= 0) {
        close(cliente_fd);
        return;
    }
    
    buffer[bytes] = '\0';
    printf("Solicitud:\n%s\n", buffer);
    
    // Parsear primera línea (método y ruta)
    char metodo[16], ruta[256];
    sscanf(buffer, "%s %s", metodo, ruta);
    
    const char* respuesta = 
        "<!DOCTYPE html>"
        "<html>"
        "<head><title>Servidor HTTP en C</title></head>"
        "<body>"
        "<h1>¡Hola desde C!</h1>"
        "<p>Ruta solicitada: %s</p>"
        "</body>"
        "</html>";
    
    char contenido[BUFFER_SIZE];
    snprintf(contenido, sizeof(contenido), respuesta, ruta);
    
    enviar_respuesta(cliente_fd, contenido);
    close(cliente_fd);
}

int main(void) {
    int servidor_fd, cliente_fd;
    struct sockaddr_in servidor, cliente;
    socklen_t cliente_len;
    
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    int opt = 1;
    setsockopt(servidor_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    memset(&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_port = htons(PUERTO);
    
    if (bind(servidor_fd, (struct sockaddr*)&servidor, sizeof(servidor)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    if (listen(servidor_fd, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Servidor HTTP escuchando en http://localhost:%d/\n", PUERTO);
    
    while (1) {
        cliente_len = sizeof(cliente);
        cliente_fd = accept(servidor_fd, (struct sockaddr*)&cliente, &cliente_len);
        
        if (cliente_fd == -1) {
            perror("accept");
            continue;
        }
        
        manejar_solicitud(cliente_fd);
    }
    
    close(servidor_fd);
    return 0;
}
```

**Probar:**
```bash
gcc servidor_http.c -o servidor_http
./servidor_http
# Abrir navegador: http://localhost:8080/
```

## Seguridad en Sockets

### 1. Validación de Entrada

```c
if (bytes_recibidos < 0 || bytes_recibidos >= BUFFER_SIZE) {
    fprintf(stderr, "Datos inválidos\n");
    close(sockfd);
    return;
}
```

### 2. Límites de Conexiones

```c
#define MAX_CONEXIONES 100

if (num_conexiones >= MAX_CONEXIONES) {
    fprintf(stderr, "Máximo de conexiones alcanzado\n");
    close(cliente_fd);
    continue;
}
```

### 3. Timeouts

```c
struct timeval tv;
tv.tv_sec = 30;  // 30 segundos
tv.tv_usec = 0;
setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
```

### 4. TLS/SSL

Para comunicación segura, usar OpenSSL:

```c
#include <openssl/ssl.h>
#include <openssl/err.h>

SSL_CTX *ctx = SSL_CTX_new(TLS_server_method());
SSL *ssl = SSL_new(ctx);
SSL_set_fd(ssl, cliente_fd);

if (SSL_accept(ssl) <= 0) {
    ERR_print_errors_fp(stderr);
} else {
    SSL_read(ssl, buffer, sizeof(buffer));
    SSL_write(ssl, respuesta, strlen(respuesta));
}

SSL_shutdown(ssl);
SSL_free(ssl);
```

## Referencias y Recursos

### Libros

- **"Unix Network Programming"** - W. Richard Stevens  
  La biblia de programación de red en Unix.

- **"TCP/IP Illustrated"** - W. Richard Stevens  
  Explicación detallada de protocolos.

- **"Beej's Guide to Network Programming"**  
  Tutorial gratuito y excelente para principiantes.

### Páginas Man

```bash
man 2 socket
man 2 bind
man 2 listen
man 2 accept
man 2 connect
man 7 ip
man 7 tcp
man 7 udp
```

### RFC Relevantes

- **RFC 793:** TCP
- **RFC 768:** UDP
- **RFC 791:** IP
- **RFC 2616:** HTTP/1.1

### Herramientas Online

- [Beej's Guide](https://beej.us/guide/bgnet/)
- [The Linux Programming Interface](http://man7.org/tlpi/)

## Resumen

La programación de sockets permite crear aplicaciones de red en C:

:::{important} Conceptos Clave

1. **Socket = punto final de comunicación** bidireccional.
2. **TCP (SOCK_STREAM):** Confiable, orientado a conexión.
3. **UDP (SOCK_DGRAM):** Rápido, sin conexión, no confiable.
4. **Servidor:** `socket()` → `bind()` → `listen()` → `accept()` → `recv()`/`send()`
5. **Cliente:** `socket()` → `connect()` → `send()`/`recv()`
6. **Orden de bytes:** Siempre usar `htons()`/`htonl()` para puertos e IPs.
7. **Multiplexación:** `select()`, `poll()`, `epoll()` para múltiples clientes.
8. **Concurrencia:** Procesos (`fork()`), threads (`pthread`), o multiplexación.
9. **Seguridad:** Validar entrada, usar timeouts, considerar TLS/SSL.
10. **Depuración:** `netstat`, `tcpdump`, `strace`, `lsof`.
:::

:::{tip} Cuándo Usar TCP vs UDP

**TCP cuando:**
- La confiabilidad es crucial (transferencia de archivos, web, correo)
- Se necesita orden garantizado
- La latencia no es crítica

**UDP cuando:**
- La velocidad es más importante que la confiabilidad (streaming)
- Pérdida ocasional de datos es aceptable
- Baja latencia es crítica (juegos, VoIP)
- Broadcast/multicast
:::

La programación de sockets es la base de todas las aplicaciones de red modernas. Este apunte cubre los fundamentos, pero dominar redes requiere entender también protocolos, concurrencia y rendimiento a nivel de sistema.
