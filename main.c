#include "phonebook.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE_PHONES 10

int main(int argc, char* argv[]){
    /* === USAGE === */
    phone_book_t phonebook;

    if (argc == 2){
        char* instruction[] = {"manually", "-m"};
        if(strcmp(instruction[0], argv[1]) == 0 || strcmp(instruction[1], argv[1]) == 0){
            printf("Enter the number of phones: ");
            int num_phones;

            scanf("%d", &num_phones);
            init(&phonebook, num_phones);

            launch_manually(&phonebook);
            destroy(&phonebook);
            return 0;
        } else{
            printf("Command parameter not recognized! Please, check it or contact support. Good luck in the next run! :)\n");
        }
    }

    srand(time(NULL));

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
    printf("List of phones: \n");
    print(&phonebook);

    /* === GET === */
    char str[MAX_LEN];
    int pos; 
    pos = rand()%size(&phonebook);
    strcpy(str, phonebook.items_ptr[pos].name);

    const char* result;
    result = get(&phonebook, str);
    if (result == NULL) {
        printf("\nPhone name not found.\n");
    } else {
        printf("\nPhone number of \"%s\" at position [%d]: %s.\n", str,  (pos + 1), result);
    }

    /* === DUMP === */
    char filename[] = "output.dat";
    dump(&phonebook, filename);

    /* === SIZE === */
    printf("\nTotal number of phones = %lu.\n", size(&phonebook));

    /* === DESTROY === */
    destroy(&phonebook);

    return 0;
}

// Prevent main function to access private fields in the struct.