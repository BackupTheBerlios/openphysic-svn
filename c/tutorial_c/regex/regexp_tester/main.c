#include <stdio.h>
#include <string.h>
#include <regex.h>

#define NS 10 /* nb de sous-motifs */

int main (int argc, char *argv[])
{
  regex_t re;
  regmatch_t subs[NS];
  int err;
  
  if (argc==3) {
    err=regcomp(&re, argv[1], REG_EXTENDED);
	if (!err) {
	  err=regexec(&re, argv[2], (size_t) NS, subs, 0);
	  if (!err) {
	    printf("oui\n");
	  } else {
	    printf("non\n");
	  }
	}
  }
  
  return 0;
}
