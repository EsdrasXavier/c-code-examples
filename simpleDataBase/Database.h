#pragma once

#include <stdio.h>
#include <string.h>

#include "Person.h"

#ifndef DATABASE_H
#define DATABASE_H

#define SUCCESS 0

/**
 * @brief Will open an file and return his pointer
 *
 * @param database. The database name as an char
 * @param mode. The mode to the file be openned:
 *              w, w+, r, r+, a, a+...
*/
FILE *openDatabase(char *database, char *mode);

/**
 * @brief Will close the file, in case of fail
 * will return an error.
 *
 * @param fp. The pointer of the file to be closeDatabase
 *
 * @return If closes successfuly return 0, case not will
 * return another number
*/
int closeDatabase(FILE *fp);

/**
 * @brief Will add an new Person into the database
 *
 * @param database. The database name as an char
 * @param p. The person struct pointer to be appended to the file
 *
 * @return Will return 0 in case of success
*/
int addNewPerson(char *db, struct Person *p);

#endif