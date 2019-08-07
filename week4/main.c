#include<stdio.h>
#include<string.h>
#include "jval.c"
#include"jval.h"
#include"jrb.h"
#include"jrb.c"


int main()
{
  int ch;
  char name[20];
  int sdt;
  JRB book;
  JRB node;
  book=make_jrb();
do
  {
    printf("\n1. Add phone\n");
    printf("2. Find \n");
    printf("3. Display \n");
    printf("4. Xoa\n");
    printf("5. Exit\n");
    printf("Your choice :  \n");
    scanf("%d",&ch);
    switch(ch)
      {
      case 1:
	{
	  printf("Nhap ten: ");
	  scanf("%s",name);
	  printf("Nhap sdt: ");
	  scanf("%d",&sdt);
	  node=jrb_find_str(book,name);
	  if(node!=NULL)
	    {
	      node->key=new_jval_s(name);
	      node->val=new_jval_i(sdt);
	    }
	  else
	    {
	      jrb_insert_str(book, name, new_jval_i(sdt));
	    }
	  break;
	}
      case 2:
	{
	  char ten[20];
	  printf("\nNhap ten: ");
	  scanf("%s",ten);
	  node=jrb_find_str(book,ten);
	  if(node!=NULL) printf(" \nTen: %s So Dien thoai: %d \n",ten,jval_i(node->val));
	  else printf("Khong co\n");
	  break;
	}
      case 3:
	{
	  jrb_traverse(node, book) printf("Ten: %s\tSo: %d \n",jval_s(node->key),jval_i(node->val));
	  break;
	}
	case 4:
	{
        char ten[20];
        printf("\nNhap ten muon xoa: ");
        scanf("%s",ten);
        node=jrb_find_str(book,ten);
        if(node==NULL) printf("Khong tim thay\n");
        else
        {
            jrb_delete_node(node);
            jrb_traverse(node, book) printf("Ten: %s\tSo: %d \n",jval_s(node->key),jval_i(node->val));
						printf("Da xoa\n");
        }
        break;
	}
      case 5:
	{
	  jrb_traverse(node, book) jrb_delete_node(node);
	  jrb_free_tree(book);
	  break;
	}
      }
  }while(ch!=5);
	return 1;
}
