#include <stdio.h>
#include <string.h>
#include "addressbook.h"
void delete_contact(struct AddressBook *addressBook)
{
    char deletename[50];
    printf("Enter the contactname you want to delete : ");
    //getchar();
    scanf(" %[^\n]",deletename);

    int found = 0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].name, deletename)==0)
        {
            //found now shift ie overight
            found = 1;
            printf("Contact found\n");
            for(int j=i;j<addressBook->contactCount-1;j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j+1];
            }
            addressBook->contactCount--;
            break;
        }
    }
    if(found == 0)
    {
        printf("Contact not found!\n");
    }
}