#include <stdio.h>
#include <stdlib.h>
#include "btree.h"


int main()
{
    char name[30];
    int sdt,size,ch;
    BTA *book;
    btinit();
    book=btopn("mybook",0,0);
    if(!book)
    {
        printf("Create my book\n");
        book=btcrt("mybook",0,0);
        do
        {
            printf("\n1. Add phone\n2. Search phone\n3. Print List\n4. Delete Phone\n5. Exit\nYour choice : ");
            scanf("%d%*c",&ch);
            switch(ch)
            {
                case 1:
                {
                    printf("Name: ");
                    gets(name);
                    printf("\nPhone: ");
                    scanf("%d%*c",&sdt);
                    if(btins(book,name,(char*)&sdt,sizeof(long))) printf("Can not insert\n");
                    break;
                }
                case 2:
                {
                    printf("Name: ");
                    gets(name);
                    if(!btsel(book,name,(char *)&sdt,sizeof(long),&size))
                    printf("number is %d \n",sdt);
                    else printf("Not found\n");
                    break;
                }
                case 3:
                {
                    btsel(book,"",(char*)&sdt,sizeof(long),&size);
                    while(btseln(book,name,(char*)&sdt,sizeof(long),&size)==0)
                    printf("%s\t%d\n",name,sdt);
                    break;
                }
                case 4:
                {
                    printf("Name :");
                    gets(name);
                    if(!btsel(book,name,(char*)&sdt,sizeof(long),&size))
                    btdel(book,name);
                    else printf("Not found\n");
                    break;
                }
                case 5:
                {
                    btcls(book);
                    break;
                }
            }
        }while(ch!=5);
    remove("mybook");
    return 0;
    }
}
