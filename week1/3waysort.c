#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int int_compare(void const* x, void const *y)
{
    int m ,n;
    m = *((int*)x);
    n = *((int*)y);
    if (m==n) return 0;
    if (m<n) return -1;
    if (m>n) return 1;
}

void exch(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// 3 way quicksort
void threewaysort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r;
    int p = l - 1, q = r;
    int k;
    while (1)
    {           // 3 4 10 5 8 7
        while (a[++i] < a[r])  // i = 2
            ;
        while (a[--j] > a[r])  // j = 3
            if (j == l)
                break;
        if (i >= j)
            break;
        exch(a, i, j);
        if (a[i] == a[r])
            exch(a, ++p, i);
        if (a[j] == a[r])
            exch(a, j, --q);
    }
    exch(a, i, r);  // 3 4 7 5 8 10
    j = i - 1;  // j = 1
    i = i + 1;  // i = 3
    for (k = l; k <= p; k++)
        exch(a, k, j--);
    for (k = r - 1; k >= q; k--)
        exch(a, i++, k);
    threewaysort(a, l, j);
    threewaysort(a, i, r);
}

// quick sort
void twowaysort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r;
    while (1)
    {
        while (a[++i] < a[r])
            ;
        while (a[--j] > a[r])
            if (j == l)
                break;
        if (i >= j)
            break;
        exch(a, i, j);
    }
    exch(a, i, r);
    twowaysort(a, l, i - 1);
    twowaysort(a, i + 1, r);
}

int main() {
    int *a, *b ,*c;
    int i;
    int temp;
    int max = 100000000;
    time_t start, end;
    double cpu_time_used; //Bien dem thoi gian
    a = (int *) malloc(max * sizeof (int));
    b = (int *) malloc(max * sizeof (int));
    c = (int *) malloc(max * sizeof (int));
    srand(time(NULL));
    
    //Khoi tao phan tu ngau nhien cho cac bien mang
    for (i = 0; i < max; i++) {
        temp = rand() % 10 + 1;
        a[i] = temp;
        b[i] = temp;
    }
    /**/
    start = clock();
    threewaysort(a, 0, max - 1);
    end = clock();
    cpu_time_used = (double)(end - start); 
    printf("Thoi gian chay 3 way sort: %f giay\n", cpu_time_used/1000000);
    /**/
    start = clock();
    twowaysort(b, 0, max - 1);
    end = clock();
    cpu_time_used = ((end - start)); 
    printf("Thoi gian chay quick sort: %f giay\n", cpu_time_used/1000000);
    /**/
    start = clock();
    qsort(c,max,sizeof(int),int_compare);
    end = clock();
    cpu_time_used = ((end - start)); 
    printf("Thoi gian chay qsort: %f giay\n", cpu_time_used/1000000);
    /**/
    free(a);
    free(b);
    free(c);
    return 0;
}