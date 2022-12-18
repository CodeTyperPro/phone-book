#include "phonebook.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_NAME 10
#define SIZE_PHONE_NUMBER 12
#define SIZE_PHONES 10

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

int main(int argc, char* argv[]){

    if (argc == 2){
        char instruction[] = "manually";
        if(strcmp(instruction, argv[2]) == 0){
            launch_manually();
        } else{
            print("Something went wrong! Please, check the parameters or contact support.\n");
            exit(0);
        }
    }

    srand(time(NULL));

    /* === USAGE === */
    phone_book_t phonebook;

    /* === INIT === */
    init(&phonebook, SIZE_PHONES);

    /* === FILL === */
    for (int i = 0; i<SIZE_PHONES; ++i) {
        
        char* name;
        name = get_random_text_name();
        char* phone_number;
        phone_number = get_random_text_number();

        if(!insert(&phonebook, name, phone_number)){
            printf("Error inserting %s : %s\n", name, phone_number);
        }
    }

    /* === PRINT === */
    print(&phonebook);

    /* === GET === */
    char str[MAX_LEN];
    strcpy(str, phonebook.items_ptr[0].name);

    const char* result;
    result = get(&phonebook, str);
    if (result == NULL) {
        printf("Phone name not found.\n");
    } else {
        printf("Phone number of %s: %s\n", str, result);
    }

    /* === DUMP === */
    char filename[] = "output.dat";
    dump(&phonebook, filename);

    /* === SIZE === */
    printf("Size = %lu.\n", size(&phonebook));

    /* === DESTROY === */
    destroy(&phonebook);

    return 0;
}

// Prevent main function to access private fields in the struct.