#include "util.h"

#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* === START UP OF THE APPLICATION === */
void
launch_manually(phone_book_t* phonebook){
    header();

    printf(":: WELCOME TO PHONE BOOK (MINI) APPLICATION ::\n");
    printf("OPTIONS: \n");
    printf("\t:: [A] : Add  - Insert new phone ::\n");
    printf("\t:: [L] : List - Total number of security guards ::\n");
    printf("\t:: [S] : Save - Workplaces with higher number of violent incidents ::\n");
    printf("\t:: [E] : Exit - Exist the application ::\n");

    printf("\tEnter the operation: ");
    char option;
    option = getchar();

    switch (option){
        case 'A': 
            add(phonebook);
            break;
        case 'L':
            list(phonebook);
            break;
        case 'S':
            save(phonebook);
            break;
        case 'E':
            dismiss();
            break;    
        default:
            printf("Invalid option!\n");
            launch_manually(phonebook);
            break;
    }
}

/* === PRINT NICE HEADER :) === */
void 
header(){
    // if define on linux and mac
    printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb PHONE BOOK \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("=================================================\n");
    printf("Student: MARTINS Alfredo | HEIOPO\n");
    printf("==================================================\n");
}

/* === GOODBYE MESSAGE AND RECOGNITION === */
void 
dismiss(){
    time_t curtime;
    time(&curtime);
    printf("\t\tTHANK YOU FOR USING MY PROGRAM :) %s\n", ctime(&curtime));
    printf("\t\tCopyright© ComSys ELTE 2022, Alfredo Martins (Student) & Dr. Brunner Tibor (Teacher)\n");
}

/* === INSERT PHONE === */
void  
add(phone_book_t* phonebook){
    printf(":: INSERT PHONE ::");
    printf("\n\t\tEnter a name (maximum of 30 letters): ");
    char* name;
    scanf("%s", name);

    while(strlen(name) > 30){
        printf("\n\t\tEnter a name (maximum of 30 letters): ");
        scanf("%s", name);
    }

    printf("\n\t\tEnter a phone number (maximum of 30 digits or characters): ");
    char* phone_number;
    scanf("%s", phone_number); 
    
    while(strlen(phone_number) > 30){
        printf("\n\t\tEnter a name (maximum of 30 letters): ");
        scanf("%s", phone_number);
    }

    if(!insert(phonebook, name, phone_number)){
        printf("Error inserting %s : %s\n", name, phone_number);
    } else{
        printf("\nPhone inserted sucessfully!\n");
        launch_manually(phonebook);
    }
}

/* === LIST ALL THE PHONE ===*/
void  
list(phone_book_t* phonebook){
    printf(":: LIST PHONE BOOK ::");
    print(phonebook);

    launch_manually(phonebook); /* Go back to the menu */
}

/* === SAVE THE LIST IN A DEFAULT FILE CALLED "output.dat" ===*/
void  
save(phone_book_t* phonebook){
    char file_name[] = "output.dat";
    dump(phonebook, file_name);

    launch_manually(phonebook); /* Go back to the menu */
}

/* === GENERATE A NAME RANDOMDLY BASE OF LETTERS IN ENGLISH ALPHABET === */
char*
get_random_text_name(){
    char* str = malloc(sizeof(char)*(SIZE_NAME + 1));
    char vowels[] = "aeiou";

    for (size_t i = 0; i < SIZE_NAME; i++) {
        int number = rand()%26;
        str[i] = (i % 2 ? 'a' + number : vowels[number%(strlen(vowels))]);
    }

    str[SIZE_NAME - 1] = '\0';

    return str;
}

/* === GENERATE A PHONE NUMBER RANDOMDLYWITH PREFIX +366 === */
char*
get_random_text_number(){
    char* str = malloc(sizeof(char)*(SIZE_PHONE_NUMBER + 1));
    str[0] = '+'; str[1] = '3'; str[2] = '6';

    for (size_t i = 3; i < SIZE_PHONE_NUMBER; i++) {
        int number = rand()%10;
        str[i] = '0' + number;
    }

    str[SIZE_PHONE_NUMBER - 1] = '\0';

    return str;
}