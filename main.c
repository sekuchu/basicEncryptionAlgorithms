#include <stdio.h>
#include <string.h>

#define length 8

int main(){

    char str[length];

    do{
        printf("Insert your word: ");
        scanf("%s", str);
    }
    while(strlen(str) > length || strlen(str) < 1);

    for(int i = 0; i < strlen(str); i++){
        str[i]++;
    }
    
    printf("%s", str);

    return 0;
}