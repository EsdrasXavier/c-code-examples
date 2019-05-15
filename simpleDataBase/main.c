#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Database.h"
#include "Person.h"

int main(int argc, char **argv) {

  struct Person person;

  person.age = 20;
  person.name = "Linus Torvalds";
  person.email = "tux@tux.com";

  if (addNewPerson("database.dat", &person) != SUCCESS) {
    printf("[ERROR] Error on add new person\n");
    return EXIT_FAILURE;
  }

  return 0;
}