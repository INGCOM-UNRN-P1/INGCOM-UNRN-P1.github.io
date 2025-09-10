#include <stdio.h>
#include <stdint.h>
int main(){
    struct {
        uint64_t a, b, c, d;
    } s = {
        .a = 8027420536511817038ull, 
        .b = 7311146936728383086ull,
        .c = 752229920040515872ull,
        .d = 4610877184
    }; 
    printf("%s", (char*)&s);
}
