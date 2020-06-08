#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    int a =0;
    int b =num - 1;
    while(a < b)
    {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        ++a;
        --b;
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

