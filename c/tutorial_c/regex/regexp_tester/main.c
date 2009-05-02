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
	    //printf("oui\n");
		
		size_t len;
		len=(subs[0].rm_eo - subs[0].rm_so);
		if (subs[0].rm_so != -1) {
		  if (len !=0) {
		    printf("-> '%.*s'\n", (int) len, argv[2] + subs[0].rm_so);
		  }
		}
		int i;
		for (i=1;i<NS;i++) {
		  if(subs[i].rm_so!=-1) {
		    printf("(%d) '%.*s'\n", i,
			  (int)(subs[i].rm_eo-subs[i].rm_so),
			  argv[2]+subs[i].rm_so);
		  }
		}
	  } else {
	    printf("non ! a ne matche pas !\n");
	  }
	}
  }
  
  return 0;
}
