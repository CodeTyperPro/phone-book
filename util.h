#ifndef UTIL_H
#define UTIL_H

#define SIZE_NAME 10
#define SIZE_PHONE_NUMBER 12

/* === START POINT === */
void  launch_manually(phone_book_t* phonebook);

/* === INTERFACES === */
void  header();
void  dismiss();
void  add(phone_book_t* phonebook);
void  list(const phone_book_t* const phonebook);
void  save(const phone_book_t* const phonebook);

/* === AUXILIARY FUNCTIONS === */
char* get_random_text_name();
char* get_random_text_number();

#endif