/********************************************************************************
* person.c: Inneh�ller definitioner av associerade funktioner tillh�rande
*           strukten person, som anv�nds f�r agring samt utskrift av persondata.
********************************************************************************/
#include "person.h"

/********************************************************************************
* person_init: Lagrar angiven persondata i ett person-objekt.
*
*              - self      : Pekare till objektet som ska lagra uppgifterna.
*              - name      : Personens namn.
*              - age       : Personens �lder.
*              - address   : Personens hemadress.
*              - occupation: Personens yrke.
*              - gender    : Personens k�n.
********************************************************************************/
void person_init(struct person* self,
                 const char* name,
                 const unsigned int age,
                 const char* address,
                 const char* occupation,
                 const enum gender gender)
{
   self->name = name;
   self->age = age;
   self->address = address;
   self->occupation = occupation;
   self->gender = gender;
   return;
}

/********************************************************************************
* person_clear: Nollst�ller persondata lagrat av angivet person-objekt.
*
*               - self: Pekare till objektet som ska nollst�llas.
********************************************************************************/
void person_clear(struct person* self)
{
   self->name = 0;
   self->age = 0;
   self->address = 0;
   self->occupation = 0;
   self->gender = GENDER_NONE;
   return;
}

/********************************************************************************
* person_print: Skriver ut lagrad persondata via angiven utstr�m, d�r
*               standardutenheten stdout anv�nds som default f�r utskrift
*               i terminalen.
*
*               - self   : Pekare till objektet som lagrar persondatan.
*               - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void person_print(const struct person* self,
                  FILE* ostream)
{
   if (!ostream) ostream = stdout;
   fprintf(ostream, "--------------------------------------------------------------------------------\n");
   fprintf(ostream, "Name: %s\n", self->name);
   fprintf(ostream, "Age: %u\n", self->age);
   fprintf(ostream, "Address: %s\n", self->address);
   fprintf(ostream, "Occupation: %s\n", self->occupation);
   fprintf(ostream, "Gender: %s\n", person_gender_str(self));
   fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
   return;
}

/********************************************************************************
* person_gender_str: Returnerar personens k�n p� textform.
*
*                    - self: Pekare till objektet som lagrar persondatan.
********************************************************************************/
const char* person_gender_str(const struct person* self)
{
   if (self->gender == GENDER_MALE) return "Male";
   else if (self->gender == GENDER_FEMALE) return "Female";
   else if (self->gender == GENDER_OTHER) return "Other";
   else return "Unspecified";
}