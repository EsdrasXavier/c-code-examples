#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "example.txt" // Your file name or path

int main(int argc, char **argv) {

  FILE *fp; // Create an pointer to FILE

  /**
   * Here you will open your file using the fopen, for more info see
   * the docs:
   * https://en.cppreference.com/w/c/io/fopen
  */
  fp = fopen(FILE_NAME, "r");

  /**
   * Check if was possible to open the file, since fopen returns
   * a pointer in case of success and a null pointer in case of
   * fail you can just check it
  */
  if (fp == NULL) {
    perror("[ERROR] Could not open the file");
    return EXIT_FAILURE; // EXIT_FAILURE is an constant of `stdlib` where is the same as return 1
  }

  int c;  // This must be an int, not an char. Since `fgetc` returns an char in case of
          // success and return EOF error in case of fail while was reading the file


  // This loop is an simple operation of I/O file reading in c
  while ((c = fgetc(fp)) != EOF) {
    /**
     * Here will be printed each letter in the terminal using `printf()`, but
     * you also can use `putchar()`;
    */
    printf("%c", c); // Will print each letter in the terminal
  }


  if (ferror(fp)) // Will check if happend some error while was reading the file
    printf("[ERROR] I/O error when reading");
  else if (feof(fp)) /* Check if reached the end of the file successfully */
    printf("\nEnd of file reached successfully");

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
