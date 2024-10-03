#include <stdio.h>

int main()
  
{
  char input[100];
  printf("Hello, there!\n");

  printf("Please enter a string: \n");
  fgets(input, sizeof(input), stdin);
  
  printf("You entered: %s\n", input);
  return 0;
}
