#include <stdio.h>
#include <math.h>

#define PI 4*atan(1)

int main (void)
{
  int x, y;
  x = 0;
  y = 0;

  printf("%i\t%i\n", x, y);
  x++;

  do {
    y = -127*cos(2*PI/255*x) + 128;
    printf("%i\t%i\n", x, y);
    x++;
  } while (x <= 255);

  return 0;
}
