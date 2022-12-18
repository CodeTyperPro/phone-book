#include "util.h"

#include <time.h>

void 
header(){
	system("cls");
	printf("\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb PHONE BOOK \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("=================================================\n");
    printf("Student: MARTINS Alfredo | HEIOPO\n");
    printf("==================================================\n");
    printf(":: WELCOME TO PHONE BOOK (MINI) APPLICATION ::\n");
    printf("OPTIONS: \n");
    printf("\t:: Add - Insert new phone ::");
    printf("\t:: List - Total number of security guards ::");
    printf("\t:: Save - Workplaces with higher number of violent incidents ::");
    printf("`t:: E - Exit::");
}

void 
dismiss(){
    time_t t;
	time(&t);
	printf("\n\t\tData e tempo: %s\n", ctime(&t));
    printf("\t\tTHANK YOU FOR USING MY PROGRAM :) %s\n", ctime(&time));
    printf("\t\tCopyright© ComSys ELTE 2022, Alfredo Martins (Student) & Dr. Brunner Tibor (Teacher)\n");
    exit(0);
}