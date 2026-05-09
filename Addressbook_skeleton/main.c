#include <stdio.h>
#include "addressbook.h"

int main() 
{
    int choice;

    struct AddressBook addressBook;
    addressBook.contactCount = 0;
    
	
    int i=1;
    while(i) 
    {
		printf("\n----Address Book Menu:----\n");
		printf("1. Add/Create contact\n");
		printf("2. Search contact\n");
		printf("3. Edit contact\n");
		printf("4. Delete contact\n");
		printf("5. List all contacts\n");
		printf("6. Load contacts\n");
		printf("7. Sort contacts\n");
		printf("8. Exit\n");
		printf("---------------------------\n");
		printf("Enter your choice: ");

		scanf("%d", &choice);

		switch (choice) 
		{
	    	case 1:
				add_contact(&addressBook);
				break;
	    	case 2:
				search_contact(&addressBook);
				break;
	    	case 3:
				edit_contact(&addressBook);
				break;
	    	case 4:
				delete_contact(&addressBook);
				break;
	    	case 5:
				list_contacts(&addressBook);
				printf("Loaded contacts\n");
				break;
			case 6:
				load_contacts(&addressBook);
				break;
			case 7:
				sort_contacts(&addressBook);
				break;
	    	case 8:
				save_contacts(&addressBook);
				printf("Saving and Exiting...\n");
				break;
	    	default:
				printf("Invalid choice. Please try again.\n");
		}
		printf("Do you want to continue:(1.Yes/0.No):");
		scanf("%d",&i);
    } 

    //return 0;
}
