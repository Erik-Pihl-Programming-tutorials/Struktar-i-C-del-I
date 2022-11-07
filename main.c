/********************************************************************************
* main.c: Demonstration av strukt i C för lagring samt utskrift av persondata.
********************************************************************************/
#include "person.h"
#include <locale.h> 

/********************************************************************************
* main: Lagrar personuppgifter för två personer och skriver ut i terminalen
*       samt till filen "persons.txt".
********************************************************************************/
int main(void)
{
   setlocale(LC_ALL, "Swedish");

   struct person p1, p2;
   FILE* ostream = fopen("persons.txt", "w");

   person_init(&p1, "Erik Pihl", 31, "Lärdomsgatan 3", "Teacher", GENDER_MALE);
   person_init(&p2, "Donald Duck", 88, "1313 Webfoot Street", "Comical Character", GENDER_MALE);

   person_print(&p1, 0);
   person_print(&p2, 0);

   person_print(&p1, ostream);
   person_print(&p2, ostream);

   fclose(ostream);
   return 0;
}