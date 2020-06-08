#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char* str;
    str = (char*)malloc(1000 * sizeof(char));
    scanf("%s", str);
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};

    int i=0;
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            arr[str[i] - '0'] += 1;
        }
        ++i;
    }

    for(int j=0; j<10; j++)
        printf("%d ", arr[j]);

    return 0;
}
