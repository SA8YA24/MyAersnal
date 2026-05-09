#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>


struct Contact{
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook {
    struct Contact contacts[100];
    int contactCount;
};

void add_contact(struct AddressBook* addressBook);
void search_contact(struct AddressBook* addressBook);
void edit_contact(struct AddressBook* addressBook);
void delete_contact(struct AddressBook* addressBook);
void list_contacts(struct AddressBook* addressBook);

int validate_name(char name[]);
int validate_phone(char phone[]);
int validate_email(char email[]);

void load_contacts(struct AddressBook* addressBook);
void save_contacts(struct AddressBook* addressBook);
void sort_contacts(struct AddressBook* addressBook);
#endif









