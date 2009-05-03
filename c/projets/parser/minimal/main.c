#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int heat_state = 0;
float temp = 22.6;

void set(char *param) {
  if (*param++) {
    if (sscanf(param,"temperature %f",param,&temp) == 2)
      printf("New temperature set to %3.1f\n", temp);
  }
}

void get(char *param) {
  if (*param++) {
    if (!strcmp("heat",param))
      printf("Heat is %s\n", heat_state?"on":"off");
    if (!strcmp("temperature",param))
      printf("Temperature is %3.1f\n", temp);
  }
}

void heat(char *param) {
  if (*param++) {
    if (!strcmp("on",param))
      heat_state = 1;
    if (!strcmp("off",param))
      heat_state = 0;
  }
  printf("Heat is %s\n", heat_state?"on":"off");
}

typedef struct cmdlist_t {
  char *commandname;
  void (*commandfunc)(char *);
} cmdlist_t;

cmdlist_t cmdlist[] = {
  { "set",  set  },
  { "get",  get  },
  { "heat", heat },
  { NULL,   NULL }
};

int parse(char *cmdline) {
  cmdlist_t *cp = cmdlist;
  while (cp->commandname) {
    if (strstr(cmdline,cp->commandname) == cmdline) {
      cp->commandfunc(cmdline + strlen(cp->commandname));
      return 1;
    }
    cp++;
  }
  return 0;
}

int main(void) {
  parse("heat on");
  parse("heat off");
}