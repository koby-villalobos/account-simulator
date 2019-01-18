/*****************************************************************
//
//  NAME:        Koby Villalobos
//
//  HOMEWORK:    project 1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 27, 2018
//
//  FILE:        main.c
//
//  DESCRIPTION:
//   This file contains the ui and main function for a bank database.
//
//
****************************************************************/


#include <stdio.h>
#include <string.h>
#include "record.h"

int addRecord(struct record **, int, char [], char[]);
int deleteRecord(struct record **, int);
void printAllRecords(struct record *);
void printRecord(struct record *, int);
void getAddress(char [], int);
int writefile(struct record *, char []);
int readfile(struct record *, char []);
 
int debugmode;


/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   main function
//                 This function contains the ui for a bank database.
//
//  Parameters:    argc (int) : contains the number of arguments
//                               which will be processed
//            
//                 argv (char **) : contains the arguments
//                                    from the command line.
//
//  Return values:  1 : Will always be 1
//                 
//
****************************************************************/
int main(int argc, char *argv[]) 
{

    struct record * start; 
    int input, i, accno;
    char name[100];
    char address[100];

    start = NULL;


    debugmode = 1;

 
    if (argc == 1)
    {
     
        debugmode = 1;

    } 
    else if (argc == 2)
    {
        if(strcmp(argv[1], "debug") == 0)
        {

            debugmode = 0;

        } 
        else 
        {

        input = 5;
        for(i=1;i<argc;i++)
        {
            printf("%s",argv[i]);
        }
        printf(" : missing file operand \nTry (ui debug to run debug mode)\n");

        }
    }


    if(argc > 2) 
    {

    input = 5;

     for(i=1;i<argc;i++)
        {
            printf("%s",argv[i]);
        }

    printf(" : missing file operand \nTry typing (ui) to run, or (ui debug) to run debug\n");

    }

    if (input != 5)
    {
        if(debugmode == 0)
        {
            printf("You have now entered debug mode\n");
        }

        printf("Welcome to the bank database\n To add a record please enter (1)\n To print a record please enter (2)\n To print all records please enter (3)\n To delete a record please enter (4)\n To exit the program please enter (5) \n ");
        scanf("%d", &input);
    }


    while(input != 5)
    {

        if(input == 1)
        {   
            printf("Please enter the account #\n");
            scanf("%d", &accno);
            printf("Please enter the name\n");
            scanf("%s", &name);
            printf("Please enter the address, to finish typing address please type '*'\n");
            getAddress(address, 100);
            addRecord(&start, accno, name, address);
            

        }
        if(input == 2)
        {
            printf("Please enter the account no\n");
            scanf("%d", &accno);
            printRecord(start, accno);
            printf("\nTo add a record please enter (1)\n To print a record please enter (2)\n To print all records please enter (3)\n To delete a record please enter (4)\n To exit the program please enter (5) \n ");

        }
        if(input == 3)
        { 
            printf("print all records\n");
            printAllRecords(start);
            printf("\nTo add a record please enter (1)\n To print a record please enter (2)\n To print all records please enter (3)\n To delete a record please enter (4)\n To exit the program please enter (5) \n ");
        }
        if(input == 4) 
        {
            printf("Please enter the account no\n");
	    scanf("%d", &accno);
            deleteRecord(&start, accno);
            printf("\nTo add a record please enter (1)\n To print a record please enter (2)\n To print all records please enter (3)\n To delete a record please enter (4)\n To exit the program please enter (5) \n");
        }            
        else if (input != 1 && input != 2 && input !=3)
        {
            printf("please enter a valit input\n");

        }
 
        scanf("%d", &input);        
    }
    writefile(start, "database.txt");

    

return 1;
}

