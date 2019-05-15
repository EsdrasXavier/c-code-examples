#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "Database.h"
#include "Person.h"

FILE *openDatabase(char *database, char *mode) {
  FILE *fp;
  fp = fopen(database, mode);

  return fp;
}

int closeDatabase(FILE * fp) {
  if (fclose(fp) != EOF) {
    return 0;
  }

  return EXIT_FAILURE;
}

int addNewPerson(char *db, struct Person *p) {
  FILE *fp;
  if ((fp = openDatabase(db, "a+")) == NULL)
    return EXIT_FAILURE;

  fprintf(fp, "%s - %s - %i\n", p->name, p->email, p->age);

  if (closeDatabase(fp) != 0)
    return EXIT_FAILURE;

  return SUCCESS;
}