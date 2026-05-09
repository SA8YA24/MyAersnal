#include <stdio.h>
#include <string.h>
#include "addressbook.h"
void search_contact(struct AddressBook *addressBook)
{
    char searchname[50];
    printf("Enter the name you want to search : ");
    getchar();
    scanf("%[^\n]",searchname);

    int found = 0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].name,searchname)==0)
        {
            found = 1;
            printf("Name : %s\n",addressBook->contacts[i].name);
            printf("Phone: %s\n",addressBook->contacts[i].phone);
            printf("Email: %s\n",addressBook->contacts[i].email);
            printf("\n");
            break;
        }
    }
    if(found == 0)
    {
        printf("Contact not found!\n");
    }

}