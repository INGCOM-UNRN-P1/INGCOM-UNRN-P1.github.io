#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#include <stdio.h>

int x = 1;

void swap(void *a, void *b, size_t size) {
     char *temp = malloc(size);
     memcpy(temp, a, size);
     memcpy(a, b, size);
     memcpy(b, temp, size);
     free(temp);
}

int main() {
    int x = 2;
    {
        int x = 3;
        printf("%d ", x);
    }
    printf("%d ", x);
    {
        printf(“%d”, x);
    }
    return 0;
}

