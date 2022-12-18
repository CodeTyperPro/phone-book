#include "util.h"

#include <time.h>

/* === START UP OF THE APPLICATION === */
void
launch_manually(){
    header();

    printf(":: WELCOME TO PHONE BOOK (MINI) APPLICATION ::\n");
    printf("OPTIONS: \n");
    printf("\t:: [A] : Add  - Insert new phone ::");
    printf("\t:: [L] : List - Total number of security guards ::");
    printf("\t:: [S] : Save - Workplaces with higher number of violent incidents ::");
    printf("`t:: [E] : Exit - Exist the application ::");

    char option;
    option = getchar();

    switch (option){
        case 'A': 
            add();
            break;
        case 'L':
            list();
            break;
        case 'S':
            save();
            break;
        case 'E':
            dismiss();
            break;    
        default:
            printf("Invalid option!\n");
            launch_manually();
            break;
    }
}

/* === PRINT NICE HEADER :) === */
void 
header(){
    // if define on linux and mac
	system("cls");
	printf("\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb PHONE BOOK \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("=================================================\n");
    printf("Student: MARTINS Alfredo | HEIOPO\n");
    printf("==================================================\n");
}

/* === GOODBYE MESSAGE AND RECOGNITION === */
void 
dismiss(){
    time_t t;
	time(&t);
	printf("\n\t\tData e tempo: %s\n", ctime(&t));
    printf("\t\tTHANK YOU FOR USING MY PROGRAM :) %s\n", ctime(&time));
    printf("\t\tCopyright© ComSys ELTE 2022, Alfredo Martins (Student) & Dr. Brunner Tibor (Teacher)\n");
    exit(0);
}

/* === INSERT PHONE === */
void  
add(){

}

/* === LIST ALL THE PHONES ===*/
void  
list(){

}

/* === SAVE THE LIST IN A DEFAULT FILE CALLED "output.dat" ===*/
void  
save(){

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
    str[0] = '+';
    str[1] = '3';
    str[2] = '6';

    for (size_t i = 3; i < SIZE_PHONE_NUMBER; i++) {
        int number = rand()%10;
        str[i] = '0' + number;
    }

    str[SIZE_PHONE_NUMBER - 1] = '\0';

    return str;
}