#include "hello.h"

char *helloGet()
{
  char *hi = (char *)malloc(17);
  strcpy(hi, "1Hello GTK CMake");
}