#include <stdio.h>
#include "addressbook.h"
void list_contacts(struct AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf("no contact found!\n");
        return;
    }
    printf("+----+-----------------------+----------------+------------------------------+\n");
    printf("| %-3s| %-22s| %-15s| %-28s |\n", "No", "Name", "Phone", "Email");
    printf("+----+-----------------------+----------------+------------------------------+\n");

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("| %-3d| %-22s| %-15s| %-28s |\n",
            i+1,
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }

    printf("+----+-----------------------+----------------+------------------------------+\n");
    printf("Total Contacts: %d\n",addressBook->contactCount);
    /*for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("Contact %d:\n",i+1);
        printf("Name  : %s\n",addressBook->contacts[i].name);
        printf("Phone : %s\n",addressBook->contacts[i].phone);
        printf("Email : %s\n",addressBook->contacts[i].email);
        printf("\n");

    }
    */

}