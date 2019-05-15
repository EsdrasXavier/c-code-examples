#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 50

/**
 * Create an struct for Person, where each Person has a name,
 * email and age.
*/
struct Person {
  char name[MAX_STR_LEN];
  char email[MAX_STR_LEN];
  int age;
};


int main(int argc, char **argv) {

  /* Declares the person1 */
  struct Person person1;

  /** Will do the basics of read user inputs */
  printf("Enter your age: ");
  fflush(stdin);
  scanf("%i", &person1.age);
  fflush(stdin);
  printf("Enter your email: ");

  /**
   * In most of the cases you do not need this. But there is an issue
   * with the scanf followed for an fgets where the fgets is ignored
   * the caracters left by the scanf. You can remove it, but can causes
   * problem.
  */
  getchar();
  fgets(person1.email, sizeof(person1.email), stdin);
  printf("Enter your name: ");
  fgets(person1.name, sizeof(person1.name), stdin);

  /* Gets the len of the text readed */
  int len = strnlen(person1.email, MAX_STR_LEN);

  /**
   * Will remove the line break of each propertie in the person,
   * since fgets sometimes save an `\n` in the end of the buffer
   * you may remove it to avoid problems in the future
  */
  if (person1.email[len - 1] == '\n') // If has a line break will replace for `\0` which is
    person1.email[len - 1] = '\0';    // a NULL character

  len = strnlen(person1.name, MAX_STR_LEN);
  if (person1.name[len - 1] == '\n')
    person1.name[len - 1] = '\0';

  /**
   * Here it's just printed for the user the input info
  */
  printf("Name: %s\n", person1.name);
  printf("Email: %s\n", person1.email);
  printf("Age: %i\n", person1.age);
  return 0;
}