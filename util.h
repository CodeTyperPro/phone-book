#ifndef UTIL_H
#define UTIL_H

#define SIZE_NAME 10
#define SIZE_PHONE_NUMBER 12

#include "phonebook.h"
#include <stdbool.h>


/* === START POINT === */
void  launch_manually(phone_book_t* phonebook);

/* === INTERFACES === */
void  header();
void  dismiss();
void  add(phone_book_t* phonebook);
void  list(phone_book_t* phonebook);
void  save(phone_book_t* phonebook);

/* === AUXILIARY FUNCTIONS === */
char* get_random_text_name();
char* get_random_text_number();
bool is_phone_number();

#endif