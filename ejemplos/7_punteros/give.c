#include <stdio.h>
#include <stdint.h>
int main(){
    uint64_t a = 4610877184;
    uint64_t b = 752229920040515872ull;
    uint64_t c = 7311146936728383086ull;
    uint64_t d = 8027420536511817038ull;
        
    printf("%s", (char*)&d);
}
