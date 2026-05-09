#include <stdio.h>
#include <string.h>
#include "addressbook.h"

void edit_contact(struct AddressBook *addressBook)
{
    char searchname[50];
    printf("Enter the name of the contact you want to edit : ");
    getchar();
    scanf("%[^\n]",searchname);

    int found = 0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].name,searchname)==0)
        {
            found = 1;
            printf("contact found\n");
            printf("Name : %s\n",addressBook->contacts[i].name);
            printf("Phone: %s\n",addressBook->contacts[i].phone);
            printf("Email: %s\n",addressBook->contacts[i].email);
            printf("\n");

            printf("MENU\n");
            printf("1. Edit name\n");
            printf("2. Edit phone\n");
            printf("3. Edit email\n");
            
            int opt;
            printf("Enter the option to edit based on menu : ");
            scanf("%d",&opt);

            switch (opt)
            {
                case 1:
                {
                    char name[50];
                    while(1)
                    {    
                        printf("Enter name: ");
                        scanf(" %[^\n]",name);
        
                        if(validate_name(name))
                        break;
                        printf("Invalid name , try again\n");
                    }
                    strcpy(addressBook->contacts[i].name, name);//saving it
                    break;
                }

                case 2:
                {
                    char phone[15];
                    while(1)
                    {
                        printf("Enter phone: ");
                        scanf("%s", phone);

                        if(validate_phone(phone))
                            break;
        
                        printf("Invalid phone, try again\n");
                    }
                    strcpy(addressBook->contacts[i].phone, phone); // savint it
                    break;
                }   

                case 3:
                {
                    char email[50];
                    while(1)
                    {
                        printf("Enter email: ");
                        scanf("%s", email);
    
                        if(validate_email(email))
                            break;

                        printf("Invalid email , try again\n");
                    }
                    strcpy(addressBook->contacts[i].email, email);
                    break;

                }
            
                default:
                    break;
            }
            FILE* fptr = fopen("database.csv","w");
            if(fptr == NULL)
            {
                printf("Error opening file!\n");
                return;
            }
            for(int k=0;k<addressBook->contactCount;k++)
            {
                fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[k].name,addressBook->contacts[k].phone,addressBook->contacts[k].email);
            }
            fclose(fptr);
        }
    }
    if(found == 0)
        printf("contact not found!\n");
}