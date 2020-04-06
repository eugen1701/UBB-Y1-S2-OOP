#include <stdio.h>
#include <string.h>

int main() {
    char v[1000];
    while(1) {
        scanf("%s", v);
        if(strcmp(v, "exit") == 0){
            return 0;
        }else{
            printf("%s", v);
        }
    }
    return 0;
}
