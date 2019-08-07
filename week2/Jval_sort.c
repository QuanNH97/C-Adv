#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jval.h"
#include "jval.c"

void exch(Jval buf[],int i,int j){
  Jval temp;
  temp=buf[i];
  buf[i]=buf[j];
  buf[j]=temp;
}

void q3sort(Jval a[],
	    int l,int r,
	    int (*compare)(Jval *,Jval *)){
  if (r<=l) return;
  int i=l-1,j=r;
  int p=l-1,q=r;
  int k;
  while(1){
    while(compare(&a[++i],&a[r])<0);
    while(compare(&a[r],&a[--j])<0) if (j==l) break;
    if(i>=j)break;
    exch(a,i,j);
    if(compare(&a[i],&a[r])==0) exch(a,++p,i);
    if(compare(&a[j],&a[r])==0) exch(a,--q,i);
  }
  exch(a,i,r);
  j=i-1;
  i=i+1;
  for(k=l;k<=p;k++) exch(a,k,j--);
  for(k=r-1;k>=q;k--) exch(a,k,i++);
  q3sort(a,l,j,compare);
  q3sort(a,i,r,compare);
}

int search_gen(Jval a[],int l, int r, Jval item,int (*compare)(Jval *,Jval *)){
  int i;
  int res;
  if(r<l)return -1;
  i=(l+r)/2;
  res=compare(&item,&a[i]);
  if(res==0) return i;
  else if (res<0)
    return search_gen(a,l,i-1,item,compare);
  else return search_gen(a,i+1,r,item,compare);
}



int compare_i(Jval *a,Jval *b){
  if(jval_i(*a)==jval_i(*b)) return 0;
  if(jval_i(*a)<jval_i(*b))return -1;
  else return 1;
}

void sort_i(Jval a[],int l,int r){
  q3sort(a,l,r,compare_i);
}

int search_i(Jval a[],int l,int r,int x){
  return search_gen(a,l,r,new_jval_i(x),compare_i);
}

Jval *create_array_i(int n){
  int i;
  Jval *array=(Jval *)malloc(sizeof(Jval)*n);
  for (i=0;i<n;i++) array[i]=new_jval_i(rand()%100);
  return array;
}

int main(){
  int n,i;
  Jval *array;
  int item;
  printf("Nhap vao so phan tu cua mang so nguyen:");
  scanf("%d",&n);
  array=create_array_i(n);
  printf("Mang truoc khi sap xep:\n");
  for(i=0;i<n;i++)
    printf("\t%d",array[i]); 
  printf("\n\n");

  sort_i(array,0,n-1);
  printf("Mang sau khi sap xep:\n");
  for (i=0;i<n;i++)
    printf("\t%d",array[i]);
  printf("\n\n");

  printf("\nPhan tu muon tim:");
  scanf("%d",&item);
  if(search_i(array,0,n-1,item)>=0) printf("Tim thay!\n"); 
  else printf("Khong tim thay!\n"); 
  return 0;
}

