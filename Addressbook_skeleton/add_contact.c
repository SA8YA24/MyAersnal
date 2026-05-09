#include <stdio.h>
#include <string.h>
#include "addressbook.h"

void add_contact(struct AddressBook* AddressBook)
{
    if(AddressBook->contactCount == 100)
    {
        printf("Address Book is full!\n");
        return;
    }

    char name[50];
    char phone[15];
    char email[50];

    while(1)
    {
        printf("Enter name: ");
        scanf(" %[^\n]",name);
        
        if(validate_name(name))
            break;

        printf("Invalid name , try again\n");

    }
    
    while(1)
    {
        printf("Enter phone: ");
        scanf("%s", phone);

        if(validate_phone(phone))
            break;

        printf("Invalid phone number , try again\n");

    }
       
    while(1)
    {
        printf("Enter email: ");
        scanf("%s", email);
    
        if(validate_email(email))
            break;

        printf("Invalid email , try again\n");

    }

    int i = AddressBook->contactCount;

    
    strcpy(AddressBook->contacts[i].name, name);
    strcpy(AddressBook->contacts[i].phone, phone);
    strcpy(AddressBook->contacts[i].email, email);

    AddressBook->contactCount++;

/*
    FILE* fptr = fopen("database.csv","a");

    if(fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    // writes formatted text → perfect for CSV! 
    fprintf(fptr,"%s,%s,%s\n",name,phone,email);
    fclose(fptr);
*/
    
}
