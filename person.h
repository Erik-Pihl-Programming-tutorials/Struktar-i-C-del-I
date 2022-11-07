/********************************************************************************
* person.h: Innehåller funktionalitet för lagring samt utskrift av persondata
*           via strukten person samt associerade funktioner.
********************************************************************************/
#ifndef PERSON_H_
#define PERSON_H_

/* Inkluderingsdirektiv: */
#include <stdio.h> /* Innehåller funktionalitet för utskrift och inmatning. */

/********************************************************************************
* gender: Enumeration för val av kön.
********************************************************************************/
enum gender
{
   GENDER_MALE,   /* Man. */
   GENDER_FEMALE, /* Kvinna. */
   GENDER_OTHER,  /* Övrigt. */
   GENDER_NONE    /* Ospecificerat. */
};

/********************************************************************************
* person: Strukt för lagring samt utskrift av persondata.
********************************************************************************/
struct person
{
   const char* name;       /* Personens namn. */
   unsigned int age;       /* Personens ålder. */
   const char* address;    /* Personens hemadress. */
   const char* occupation; /* Personens yrke. */
   enum gender gender;     /* Personens kön. */
};

/********************************************************************************
* person_init: Lagrar angiven persondata i ett person-objekt.
* 
*              - self      : Pekare till objektet som ska lagra uppgifterna.
*              - name      : Personens namn.
*              - age       : Personens ålder.
*              - address   : Personens hemadress.
*              - occupation: Personens yrke.
*              - gender    : Personens kön.
********************************************************************************/
void person_init(struct person* self, 
                 const char* name,
                 const unsigned int age,
                 const char* address,
                 const char* occupation,
                 const enum gender gender);

/********************************************************************************
* person_clear: Nollställer persondata lagrat av angivet person-objekt.
* 
*               - self: Pekare till objektet som ska nollställas.
********************************************************************************/
void person_clear(struct person* self);

/********************************************************************************
* person_print: Skriver ut lagrad persondata via angiven utström, där 
*               standardutenheten stdout används som default för utskrift
*               i terminalen.
*
*               - self   : Pekare till objektet som lagrar persondatan.
*               - ostream: Pekare till angiven utström (default = stdout).
********************************************************************************/
void person_print(const struct person* self,
                  FILE* ostream);

/********************************************************************************
* person_gender_str: Returnerar personens kön på textform.
* 
*                    - self: Pekare till objektet som lagrar persondatan.
********************************************************************************/
const char* person_gender_str(const struct person* self);

#endif /* PERSON_H_ */