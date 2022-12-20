#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_LEN 30

typedef struct phone{
    char name[MAX_LEN + 1];       /* Extra place for '\0' */
    char phone_number[MAX_LEN + 1];
} phone_t;

typedef struct phone_book{
    size_t num_elems, size; // ?
    phone_t* items_ptr;
} phone_book_t;

void        init(phone_book_t* phonebook, const int size);
bool        insert(phone_book_t* phonebook, char name[], char phone_number[]);
const char* get(const phone_book_t* const phonebook, const char name[]);
size_t      size(const phone_book_t* const phonebook);
bool        is_full(const phone_book_t* const phonebook);
bool        is_empty(const phone_book_t* const phonebook);
int         at(const phone_book_t* const phonebook, const char name[]);
void        print(const phone_book_t* const phonebook);
void        dump(const phone_book_t* const phonebook, const char file_name[]);
void        destroy(phone_book_t* phonebook);

#endif