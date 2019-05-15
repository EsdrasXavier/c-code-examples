#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "example.txt"

int main(int argc, char **argv) {

  FILE *fp; // Create an pointer to FILE

  /**
   * Here you will open your file using the fopen, for more info see
   * the docs:
   * https://en.cppreference.com/w/c/io/fopen
   * Note: Always when you write an file the system creates a new one,
   * so if the file exists the file will be deleted and if does not exists
   * the file will be created
  */
  fp = fopen(FILE_NAME, "w+"); // When you use `w+` you can write and read the file


  /**
   * Check if was possible to open the file, since fopen returns
   * a pointer in case of success and a null pointer in case of
   * fail you can just check it
  */
  if (fp == NULL) {
    perror("[ERROR] Could not open the file");
    return EXIT_FAILURE; // EXIT_FAILURE is an constant of `stdlib` where is the same as return 1
  }

  /**
   * Here you will append a text into your file, you can use `fprintf` or `fputs`
   * The difference between each one is, with fprintf you can format your string,
   * and with fputs not.
   * Example:
   * fprintf(fp, "This will be add into your file %i, %s \n", 1, "as");
   * This would add the text, the number one and the string 'as'
  */
  fprintf(fp, "This will be add into your file\n");
  fputs("This also will be add into your file\n", fp);

  /** Will close the file, always make sure of using `fclose`, in can not
   * close the file but this can return in problem in your file
  */
  if (fclose(fp) != EOF) {
    printf("\nFile closed successfully.\n");
  } else {
    return EXIT_FAILURE;
  }

  return 0;
}