/* How to use Regular Expression in C
man regex
regcomp() and regexec()
*/

#include <stdio.h>
#include <regex.h>

char* str="world";
char* pattern="[a-z]*";

int main (void)
{
  regex_t re;

  regcomp(&re, pattern, REG_EXTENDED); /* compile RegEx */

  puts(str);
  puts(pattern);
  
  if (regexec(&re, str, 0, NULL, 0)) {
    puts("match");
  } else {
    puts("doesn't match");
  }
  return 0;
}
