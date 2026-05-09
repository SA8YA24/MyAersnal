#include <stdio.h>
#include <string.h>
#include "addressbook.h"

void load_contacts(struct AddressBook* addressBook)
{
    FILE* fptr = fopen("database.csv","r");
    if(fptr == NULL)
    {
        return;
    }
    printf("file opened succesfully\n");
  
    int i = 0;
    while(fscanf(fptr, "%[^,],%[^,],%[^\n]\n",
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email) == 3)
        {
            i++;
            addressBook->contactCount++;
        }   
    fclose(fptr);

}