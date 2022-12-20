#include "util.h"

#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* === START UP OF THE APPLICATION === */
void
launch_manually(phone_book_t* phonebook){
    header();

    printf(":: WELCOME TO PHONE BOOK (MINI) APPLICATION ::\n");
    printf("OPTIONS: \n");
    printf("\t:: [A] => Add  - Insert new phone ::\n");
    printf("\t:: [L] => List - List all the phones ::\n");
    printf("\t:: [F] => Find - Search the phone number of a given name ::\n");
    printf("\t:: [S] => Save - Save the phones in a text file ::\n");
    printf("\t:: [E] => Exit - Exit the application ::\n");

    printf("\n\tEnter the operation: ");
    char option;
    scanf("%c", &option);
    option = toupper(option);
    fgetc(stdin); /* Remove enter in the buffer. */

    switch (option) {
        case 'A': 
            add(phonebook);
            break;
        case 'L':
            list(phonebook);
            break;
        case 'F':
            search(phonebook);
            break;
        case 'S':
            save(phonebook);
            break;
        case 'E':
            dismiss();
            break;    
        default:
            printf("\nInvalid option!\n");
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
    printf("=================================================\n");
}

/* === GOODBYE MESSAGE AND RECOGNITION === */
void
dismiss(){
    time_t curtime;
    time(&curtime);
    printf("\n\tTHANK YOU FOR USING MY PROGRAM :) %s\n", ctime(&curtime));
    printf("\tCopyright© Imperative Programming ELTE 2022, Alfredo Martins (Student) & Dr. Brunner Tibor (Professor)\n");
}

/* === INSERT PHONE === */
void  
add(phone_book_t* phonebook){
    printf("\n:: INSERT PHONE ::");
    printf("\nEnter a valid name (maximum of 30 digits or characters): ");
    char name[MAX_LEN + 1];
    char c;
    size_t index = 0;
    while ((c = getchar()) != '\n') {
        name[index++] = c;
    }

    name[index] = '\0';

    while(strlen(name) > 30) {
        printf("\nEnter a valid name (maximum of 30 digits or characters): ");
        index = 0;
        while ((c = getchar()) != '\n') {
            name[index++] = c;
        }
        name[index] = '\0';
    }

    printf("Enter a valid phone number (maximum of 30 digits or characters): ");
    char phone_number[MAX_LEN + 1];
    index = 0;
    while ((c = getchar()) != '\n') {
        phone_number[index++] = c;
    }
    phone_number[index] = '\0';
    
    while(!is_phone_number(phone_number)) {
        printf("Enter a valid phone number (maximum of 30 digits or characters): ");    
        index = 0;
        while ((c = getchar()) != '\n') {
            phone_number[index++] = c;
        }
        phone_number[index] = '\0';
    }

    if(!insert(phonebook, name, phone_number)) {
        printf("Error inserting %s : %s. Please, check If maximu capacity was reached.\n", name, phone_number);
    } else{
        printf("\nPhone inserted sucessfully!\n");
    }
    
    launch_manually(phonebook);
}

/* === LIST ALL THE PHONE ===*/
void
list(phone_book_t* phonebook){
    printf("\n:: LIST PHONE BOOK ::\n\n");
    print(phonebook);

    launch_manually(phonebook); /* Go back to the menu */
}

/* === SEARCH FOR THE PHONE NUMBER OF A GIVEN NAME ===*/
void
search(phone_book_t* phonebook){
    printf("\n:: SEARCH OF A PHONE NUMBER'S NAME ::\n\n");
    
    print(phonebook);

    printf("\nEnter a name (maximum of 30 digits or characters): ");
    char name[256];
    char c;
    size_t index = 0;
    while ((c = getchar()) != '\n') {
        name[index++] = c;
    }

    name[index] = '\0';
    const char* result;
    result = get(phonebook, name);
    if (result == NULL) {
        printf("\nPhone name not found.\n");
    } else {
        printf("\nPhone number of \"%s\": %s.\n", name, result);
    }

    launch_manually(phonebook); /* Go back to the menu */
}

/* === SAVE THE LIST IN A DEFAULT FILE CALLED "output.dat" ===*/
void
save(phone_book_t* phonebook){
    char file_name[] = "output.dat";
    dump(phonebook, file_name);

    launch_manually(phonebook); /* Go back to the menu */
}

/* === GENERATE A NAME RANDOMLY BASED ON LETTERS IN ENGLISH ALPHABET === */
void
get_random_text_name(char* str){
    char vowels[] = "aeiou";

    for (size_t i = 0; i < SIZE_NAME; i++) {
        int number = rand()%26;
        str[i] = (i % 2 ? 'a' + number : vowels[number%(strlen(vowels))]);
    }

    str[SIZE_NAME - 1] = '\0';
}

/* === GENERATE A PHONE NUMBER RANDOMDLYWITH PREFIX +366 === */
void
get_random_text_number(char* str){
    str[0] = '+'; str[1] = '3'; str[2] = '6';

    for (size_t i = 3; i < SIZE_PHONE_NUMBER; i++) {
        int number = rand()%10;
        str[i] = '0' + number;
    }

    str[SIZE_PHONE_NUMBER - 1] = '\0';
}

/* === CHECK WHETHER OR NOT A GIVEN INPUT IS A PHONE NUMBER === */
bool
is_phone_number(char str[]) {
    if(strlen(str) > 30 || strlen(str) < 5)
        return false;
    
    bool is_okay = str[0] == '+';
    for (size_t index = 1; str[index] != '\0'; index++) {
        is_okay = is_okay && (str[index] >= '0' && str[index] <= '9');
    }

    return is_okay;
}