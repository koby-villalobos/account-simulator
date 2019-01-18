#include <stdio.h>
#include "record.h"

void getAddressFile(char [], int, FILE *);

extern int debugmode;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   A function that adds a struct record to a 
//                 linked list.
//
//  Parameters:    start (struct record **) : Pointer to a 
//                    to a pointer of the start of the linked list.
//                          
//                 accountnoInput (int) : the account number for 
//                    struct record that will be inputed.
//
//     	       	   nameInput (char []) : the name for 
//     	       	      struct record that will be inputed.
//
//     	       	   addressInput (char []) : the address for 
//     	       	      struct record that will be inputed.
//
//  Return values:  0 : success
//                  1 : struct record was not added.
//
****************************************************************/

int addRecord(struct record **  start, int accountnoInput, char nameInput[], char addressInput[])
{
    struct record * newNode; 
    struct record * temp;
    struct record * tempPrev;
    int run;
        
          
    newNode = (struct record *) malloc(sizeof(struct record));
    run = 1;
    temp = NULL;
    tempPrev = NULL;
    
    
    
    newNode ->  accountno = accountnoInput;
    strcpy(newNode -> name, nameInput);
    strcpy(newNode -> address, addressInput); 
    newNode -> next = NULL;
    temp = *start;
    tempPrev = NULL;
    
    if(debugmode == 0)
    {
     	printf("The function being called is addRecord, the parameters being passed through:\n accountno: %d\n name: %s\n address: %s\n",accountnoInput, nameInput, addressInput);
    }
    
    if(temp == NULL)
    {

        *start = newNode;
        run = 0;
    }


    if(run == 1)
    { 
        if( newNode -> accountno <= temp -> accountno)
        {
            newNode -> next = *start;
            *start = newNode;
            run = 0;
        }
    }
    if(run == 1)
    {
        if(temp -> next == NULL)
        {
            temp -> next = newNode;
            run = 0;
        }
    } 

    if(run == 1)
    {
    tempPrev = temp;
    temp = temp -> next;
    }
    
    while(run == 1)
    {
        if((newNode -> accountno >= tempPrev -> accountno) &&  (newNode -> accountno <= temp -> accountno))
        {
            tempPrev -> next = newNode;
            newNode -> next = temp;
            run = 0;

        } else if(temp -> next == NULL)
        {
            temp -> next = newNode;
            run = 0;

        } else
	{

        tempPrev = temp;
        temp = temp -> next;

        }



    }

    printf("This persons account has been added: %s\n", newNode -> name);
    return run;

}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   A function that deletes a struct record from
//                 a linked list.
//
//  Parameters:    start (struct record **) : contains a pointer to a
//                             pointer of the start of the linked list.
//
//                 uaccountno (int) : contains the account number
//                               of struct record to be deleted.     
//
//  Return values:  0 : success
//                 -1 : the struct record was not deleted.
//
****************************************************************/

int deleteRecord(struct record ** start, int uaccountno)
{
    struct record * temp;
    struct record * tempPrev;
    int run;
    int works;
    

    works = -1;
    run = 0;
    temp = *start;
    tempPrev = NULL;

    if(debugmode == 0)
    {
     	printf("The function being called is deleteRecord, the parameters being passed through:\n accountno: %d\n",uaccountno);
    }

    
    if(temp == NULL)
    {
        run = 1;
        printf("There were no records in the list.\n");
    }

    if(run == 0)
    {
        if(temp -> accountno == uaccountno)
        {
            printf("%s's record was deleted.\n", temp -> name);
            temp = temp -> next;
            *start = temp;
            works = 0;
            run = 1;
        }
    }

    if(run == 0)
    {  
        if(temp -> next == NULL)
        {
            printf("No record was deleted\n");
       	    run = 1;
        } else {
            tempPrev = temp;
            temp = temp -> next;
        }
    }



    while(run == 0)
    {
        
        if (temp -> accountno == uaccountno)
        {
            printf("%s's record has been removed\n", temp -> name);        
            tempPrev -> next = temp -> next;
            free(temp);
            works = 0;
            run = 1;


        } else if (temp -> next == NULL || temp == NULL)
        {
            run = 1;
        } else if (run == 0)
        {
            tempPrev = temp;
            temp = temp -> next;
        }
    }        

        
       


    return works;
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   A function that prints all struct records from
//                 a linked list.
//
//  Parameters:    start (struct record *) : contains a pointer         
//                             to the start of the linked list.
//
//     	       	   
//  Return values:  N/A 
//
****************************************************************/

void printAllRecords(struct record * start)
{
    struct record * temp;

    temp = NULL;
    temp = start;
 
    if(debugmode == 0)
    {
     	printf("The function being called is printAllRecord, there only parameter being passed is a pointer\n");
    }

   while( temp != NULL)
    {
        printf("Account #: %d\nName: %s\nAddress: %s\n \n", temp -> accountno, temp -> name, temp -> address);
        temp = temp -> next;
    }

}

/*****************************************************************
//
//  Function name: printRecord
//
//  DESCRIPTION:   A function that prints a struct record from
//                 a linked list.
//
//  Parameters:    start (struct record *) : contains a pointer to         
//                             the start of the linked list.
//
//     	       	   uaccountno (int) : contains the account number
//  	       	       	       	    of struct record to	be printed.
//
//  Return values:  0 : success
//                 -1 : the struct record was not printed.
//
****************************************************************/

int printRecord(struct record * start, int uaccountno)
{
    struct record * temp;
    int run;
    int works;


    works = -1;
    run = 0;
    temp = start;

    if(debugmode == 0)
    {
     	printf("The function being called is printRecord, the parameters being passed through:\n accountno: %d\n",uaccountno);
    }



    while(run == 0)
    {

     	if(start == NULL)
        {
            printf("There are no records in the list\n");
            run = 1;

        } else if (uaccountno == temp -> accountno)
        {
            printf("Account #: %d\nName: %s\nAddress: %s\n \n", temp -> accountno, temp -> name, temp -> address);  
            works = 0;
            run = 1;
        } else if (temp -> next == NULL)
        {

            run = 1;
        } else if (run == 0)
        {
            temp = temp -> next;

        }
    }

    return works;
}

/*****************************************************************
//
//  Function name: getAddress
//
//  DESCRIPTION:   A function that recieves an address for standard
//                 input.
//
//  Parameters:    address (char []) : contains char array used to add        
//                             address to.
//
//     	       	   max (int) : contains the size of the array.
//
//  Return values:  N/A
//
****************************************************************/

void getAddress(char address[], int max)
{
    char in;
    int count;

    count = 0;
    memset(address, 0, 100);

    while(in != '*' && count < max)
    {
        in = fgetc(stdin); 
        address[count] =  in;
        count++;
    }

}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   A function that writes the linkedlist to a file.
// 
//
//  Parameters:    start (struct record **) : contains a pointer to         
//                             the start of the linked list.
//
//     	       	   filename (char []) : contains the file name.
//
//  Return values:  0 : success
//                 -1 : file was not written to.
//
****************************************************************/

int writefile( struct record *start, char filename[ ] )
{

    FILE * fp;
    int works;
    struct record * temp;

    temp = start;
    works = -1;
    fp = fopen(filename, "w+");
    if(fp != NULL)
    {
        while(temp != NULL)
        {

            fprintf(fp, "%d\n", temp -> accountno );
            fprintf(fp, "%s\n", temp -> name);
            fprintf(fp, "%s\n", temp -> address);
       
            temp = temp -> next;
        }

        fclose(fp);   
        works = 0;
    }

    return works;
}



void getAddressFile(char address[], int max, FILE * fp)
{
    char in;
    int count;

    count = 0;
    memset(address, 0, 100);

    while(in != '*' && count < max)
    {
        in = fgetc(fp);
        address[count] =  in;
        count++;
    }

}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   A function that reads a file, then creates a 
//                 a linked list.
//
//  Parameters:    start (struct record *) : contains a pointer to     
//                              the start of the linked list.
//
//     	       	   filename (char []) : contains the filename.
//
//  Return values:  0 : success
//                 -1 : the struct record was not deleted.
//
****************************************************************/

int readfile( struct record * start, char filename[] )
{
    FILE * fp;
    int ret, count;
    struct record * temp;
    char get[100];
    char in;

    temp = start;
    ret = -1;
    count = 0;
    
    fp = fopen(filename, "r");
    if( fp != NULL )
    {
    
     	while(feof(fp) == 0)
        {

            printf("Hello\n");    
            fscanf(fp, "%d", temp -> accountno); 
            printf("Hello\n");
           
            fgets(temp -> name, 100, fp);

            while(in != '*')
            {

       	        in = fgetc(fp);
                get[count] =  in;
                count++;
            temp = temp -> next;
            }
            strcpy(temp -> address, get);
    

        }
	ret = 0;
        fclose(fp);
    }

    return ret;
}

