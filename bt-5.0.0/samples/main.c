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
        printf("Insert data\n");
        printf("Name: ");
        gets(name);
        printf("\nsdt: ");
        scanf("%d%*c",&sdt);
        btins(book,name,(char*)&sdt,sizeof(int));
        btsel(book,"",(char*)&sdt,sizeof(int),&size);
        while(btsel(book,name,(char*)&sdt,sizeof(int),&size))
        {
            printf("%s\t%d\n",name,sdt);
        }
        do
        {
            printf("1.Add phone\n2. Search phone\n3. Print List\n4. Delete Phone\n5.Exit\n");
            scanf("%d%*c",&ch);
            switch(ch)
            {
                case 1:
                {
                    printf("Name: ");
                    gets(name);
                    printf("\n sdt: ");
                    scanf("%d%*c",&sdt);
                    if(btins(book,name,(char*)&sdt,sizeof(long))) printf("Can not insert\n");
                    break;
                }
                case 2:
                {
                    printf("Name: ");
                    gets(name);
                    if(!btsel(book,name,(char *)&sdt,sizeof(int),&size))
                    printf("number is %d \n",sdt);
                    else printf("No co\n");
                    break;
                }
                case 3:
                {
                    btsel(book,"",(char*)&sdt,sizeof(int),&size);
                    while(btseln(book,name,(char*)&sdt,sizeof(int),&size)==0)
                    printf("%s\t%d\n",name,sdt);
                    break;
                }
                case 4:
                {
                    printf("Name :");
                    gets(name);
                    if(!btsel(book,name,(char*)&sdt,sizeof(int),&size))
                    btdel(book,name);
                    else printf(" k co\n");
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
