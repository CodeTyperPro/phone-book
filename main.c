#include "phonebook.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE_PHONES 10

int main(int argc, char* argv[]){

    if (argc == 2){
        char instruction[] = "manually";
        if(strcmp(instruction, argv[2]) == 0){
            launch_manually();
            return 0;
        } else{
            print("Command parameter not recognized! Please, check it or contact support. Good luck in the next run! :)\n");
        }
    }

    srand(time(NULL));

    /* === USAGE === */
    phone_book_t phonebook;

    /* === INIT === */
    init(&phonebook, DEFAULT_SIZE_PHONES);

    /* === FILL === */
    for (int i = 0; i<DEFAULT_SIZE_PHONES; ++i) {
        
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