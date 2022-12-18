#ifndef UTIL_H
#define UTIL_H

#define SIZE_NAME 10
#define SIZE_PHONE_NUMBER 12

/* === START POINT === */
void  launch_manually();

/* === INTERFACES === */
void  header();
void  dismiss();
void  add();
void  list();
void  save();

/* === AUXILIARY FUNCTIONS === */
char* get_random_text_name();
char* get_random_text_number();

#endif