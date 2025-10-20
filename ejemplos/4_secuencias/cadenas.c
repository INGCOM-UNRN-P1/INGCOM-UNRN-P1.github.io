#include <stdio.h>

void imprime(int arr[], size_t len)
{
  for(size_t i = 0; i < len; i++){
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main()
{

char str[] = "computadora";
int count = 0;
for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'o') {
        count++;
    }
}
printf("%d\n", count);

int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    if (arr[i] % 2 == 0) {
        arr[i] *= 2;
    }
}
arr[3] = arr[2] + arr[4];
printf("\n%d\n-----", arr[3]);

int x = 5;
if (x = 0) {
    printf("Cero");
} else {
    printf("No Cero");
}


}

