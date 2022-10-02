#include <stdio.h>
#include <string.h>

int main()
{
    int i = 3;
    int *p, *t;
    p = &i;
    p = p;
//    t = *p;
//    *t = *p;
 //   *p = 100;
  //  *p = &p;
  //  p = &i;
  //  printf("\n%d", i);
  //  printf("\n%d", &i);
 //   printf("\n%p", i);
 //   printf("\n%p", i);
    printf("\n1 %d", i);
  //  printf("\n2 %d", *t);
   // printf("\n%p", i);
  //  printf("\n%d", &i);
 //   printf("\n9 %p", t);
 //   printf("\n3 %p", &*t);
 //   printf("\n4 %p", &t);
    printf("\n5 %p", &*p);
    printf("\n6 %p", &p);
    printf("\n7 %p", &i);
    return 0;
}

int main1() {
  int myAge = 43;  // An int variable
  int* ptr = &myAge;  // A pointer variable, with the name ptr, that stores the address of myAge

  // Output the value of myAge (43)
  printf("%d\n", myAge);

  // Output the memory address of myAge (0x7ffe5367e044)
  printf("%p\n", &myAge);

  // Output the memory address of myAge with the pointer (0x7ffe5367e044)
  printf("%p\n", ptr);

  return 0;
}