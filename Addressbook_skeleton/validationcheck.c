#include <stdio.h>
#include <string.h>
#include "addressbook.h"

int validate_name(char name[]) //can also be written in pointer notation 
{                             // ie int validate_name(char* name)
                            // easy readability 
    if(strlen(name)==0)
    {
        return 0;
    }
    for(int i = 0; name[i] != '\0'; i++)
    {
        if((name[i]< 'a' || name[i]> 'z')&&(name[i]< 'A' || name[i]> 'Z')&&(name[i]!=' '))
            return 0;
    }
    return 1;
}

int validate_phone(char phone[])
{
    
    if(strlen(phone)== 13)
    {
       
        if(phone[0]!='+' || phone[1]!='9' || phone[2]!='1')
            return 0;
        
        for(int i=3;i<13;i++)
        {
            if(phone[i] < '0' || phone[i]> '9') //checking out bounds ie range
            {
                return 0;
            }
        }
        return 1;
           
    }
    else if(strlen(phone)== 10)
    {
       
        for(int i=0;i<10;i++)
        {
            if(phone[i] < '0' || phone[i]> '9')
                return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int validate_email(char email[])
{
    int i;
    for(i=0; email[i]!='@' && email[i]!='\0'; i++)
    {
        if((email[i]<'a' || email[i]>'z')&&(email[i]<'0' || email[i]>'9')&&(email[i]!='.')&&(email[i]!='_'))
            return 0;

    }
    if(email[i]=='\0')
        return 0;
        
            
    if(strcmp(email+i+1,"gmail.com")==0)//returns 0 if true, so 0==0 true
        return 1;
        
    return 0;
      
}