#include <stdio.h>

void procedimiento();
int variable_global = 10;

int main() {
    int variable_global = 20;
    {
        int variable_global = 30;
        procedimiento();
        printf("La variable vale %d\n", variable_global);
        {
            int variable_global = 50;
            procedimiento();
            printf("La variable vale %d\n", variable_global);
        }
    }
    printf("La variable vale %d\n", variable_global);
    procedimiento();
    return 0;
}

void procedimiento(){
    static int a = 0;
    {
        static int a = 10;
        printf("%d\n", a);
        a = a + 5;
    }
    printf("[procedimiento] variable vale %d - %d\n", variable_global, a);
    a = a + 1;
}
