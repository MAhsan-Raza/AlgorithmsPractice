#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float getAreaSq(triangle tr)
{
    float p = (float)(tr.a+tr.b+tr.c)/2;
    return p*(p-tr.a)*(p-tr.b)*(p-tr.c);
}

void sort_by_area(triangle* tr, int n) 
{
	for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(getAreaSq(tr[i]) > getAreaSq(tr[j]))
            {
                triangle tmp = tr[i];
                tr[i] = tr[j];
                tr[j] = tmp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
