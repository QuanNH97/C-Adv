// quicksort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void* a, void* b, size_t size) {
    void *temp = (void*)malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int compare_int(void* x, void* y) {
    int a = *( (int*)x );
    int b = *( (int*)y );
    if (a==b) return 0;
    return (a>b)?1:-1;
}

int compare_long(void* x, void* y) {
    long a = *( (long*)x );
    long b = *( (long*)y );
    if (a==b) return 0;
    return (a>b)?1:-1;
}

int compare_float(void* x, void* y) {
    float a = *( (float*)x );
    float b = *( (float*)y );
    if (a==b) return 0;
    return (a>b)?1:-1;
}

int compare_char(void* x, void* y) {
    char a = *( (char*)x );
    char b = *( (char*)y );
    if (a==b) return 0;
    return (a>b)?1:-1;
}

void in(int a[]) {
    int i;
    for (i=0; i<10; i++) printf("%d ", a[i]);
    printf("\n");
}

int partition(void* a, int l, int r, int size, int (*compare)(void*, void*))
{
    void* p = a+size*l; int i = l, j=r+1;
    while (i<=j)
    {
        i++;
        while(i<=r && compare(a+size*i, p)<0 /*a[i]<p*/) i++;
        j--;
        while(j>=l && compare(a+size*j, p)>0 /*a[j]>p*/) j--;
        if (i<j) swap(a+size*i, a+size*j, size); //{ int tmp = a[i]; a[i]=a[j]; a[j]=tmp; }
    }
    //int temp = a[l]; a[l]=a[j]; a[j]=temp;
    swap(a+size*l, a+size*j, size);
    return j;
}

void quickSort(int a[], int l, int r)
{
    if (l>=r) return;
    int pivot = partition(a, l, r, sizeof(int), &compare_int);
    if (pivot>l) quickSort(a, l, pivot-1);
    if (pivot<r) quickSort(a, pivot+1, r);
}

void main()
{
    int arr[10] = {6,4,2,8,9,5,0,7,1,3};
    quickSort(arr, 0, 9);
    int i;
    for (i=0; i<10; i++) printf("%d ", arr[i]);
    printf("\n");
    int a= 3, b=4;
}
