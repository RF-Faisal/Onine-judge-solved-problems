//problem link: https://atcoder.jp/contests/abc066/tasks/abc066_b
//learned stl library strncmp func

#include<stdio.h>
#include<string.h>

int main(){
    char str[220];
    scanf("%s", str);

    int size = strlen(str);

    for(int i=size-2; i; i -= 2){
        if(strncmp(str, str+i/2, i/2) == 0){
            printf("%d", i);
            return 0;
        }
    }
}
