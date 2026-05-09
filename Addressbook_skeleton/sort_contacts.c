#include <stdio.h>
#include <string.h>
#include "addressbook.h"

void sort_contacts(struct AddressBook* addressBook)
{
    for(int i = 0; i < addressBook->contactCount-1; i++)
    {
        for(int j = 0; j < addressBook->contactCount-i-1; j++)
        {
            if(strcmp(addressBook->contacts[j].name, addressBook->contacts[j+1].name) > 0)
            {
                // swaping structures
                struct Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
    printf("Contacts sorted successfully\n");
    printf("----------------------------------\n");
    list_contacts(addressBook);
}