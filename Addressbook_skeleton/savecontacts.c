#include <stdio.h>
#include <string.h>
#include "addressbook.h"

void save_contacts(struct AddressBook* addressBook)
{
    FILE* fptr = fopen("database.csv","w");
    if(fptr == NULL)
    {
        return;
    }
    //fprintf(fptr,"Name\tPhone No\tEmail\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
         fprintf(fptr, "%s,%s,%s\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
       
    }
    fclose(fptr);
    
}