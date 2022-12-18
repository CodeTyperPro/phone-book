#include "phonebook.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void
init(phone_book_t* phonebook, int size){
    if (size < 0) {
        printf("Invalid size. Good luck on the next try :)!\n");
        exit(0);
    }

    phonebook->size = size;
    phonebook->num_elems = 0;
    phonebook->items_ptr = (phone_t*) malloc(sizeof(phone_t)*size);
}

bool
is_full(const phone_book_t* const phonebook){
    return phonebook->num_elems == phonebook->size;
}

bool
insert(phone_book_t* phonebook, char name[], char phone_number[]){
    if (!is_full(phonebook)) {
        phone_t p;
        strcpy(p.name, name);
        strcpy(p.phone_number, phone_number);

        phonebook->items_ptr[phonebook->num_elems++] = p;
        return true;
    }

    return false;
}

size_t
size(const phone_book_t* const phonebook){
    return phonebook->num_elems;
}

const char*
get(const phone_book_t* const phonebook, const char name[]){
    for (size_t i = 0; i < size(phonebook); i++) {
        if (strcmp(phonebook->items_ptr[i].name, name) == 0){
            return phonebook->items_ptr[i].phone_number;
        }
    } return NULL;
}

void
print(const phone_book_t* const phonebook){
    for (size_t i = 0; i < size(phonebook); ++i) {
        printf("\t[%zu] - %s : %s\n", (i + 1), phonebook->items_ptr[i].name, phonebook->items_ptr[i].phone_number);  
    }
}

void
dump(const phone_book_t* const phonebook, const char file_name[]){
    FILE* output;
    output = fopen(file_name, "w+");
    if (output == NULL) {
        printf("An error occurred while opening the file/file does not exist. Please, check it!\n");
        exit(0);
    } else {            
        for (size_t i = 0; i < size(phonebook); ++i) {
            fprintf(output, "%s : %s\n", phonebook->items_ptr[i].name, phonebook->items_ptr[i].phone_number);
            fseek(output, 0, SEEK_CUR);
        }

        printf("\nData saved sucessfully. Please, check the file called \"%s\" in the current directory! :) \n", file_name);
        fclose(output);
    }
}

void
destroy(phone_book_t* phonebook){
    if (phonebook != NULL) {
        free(phonebook->items_ptr);
    }
}