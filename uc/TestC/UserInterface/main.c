#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


#define KEY_UP 'z'
#define KEY_DOWN 'w'
#define KEY_LEFT 'q'
#define KEY_RIGHT 's'
#define KEY_OK 'y'
#define KEY_CANCEL 'n'

/*
enum {
     DONT_MOVE = 0,
     GO_PARENT,
     GO_BROTHER_NEXT,
     GO_BROTHER_PREVIOUS,
     GO_CHILD_FIRST,
};
uint8_t go = DONT_MOVE;
*/

/* 
struct keypad_typ
{
   bool up;
   bool down;
   bool left;
   bool right;
   bool ok;
   bool cancel;
};

struct keypad_typ key_pressed;

void no_key_pressed() {
   key_pressed.up=false;
   key_pressed.down=false;
   key_pressed.left=false;
   key_pressed.right=false;
   key_pressed.ok=false;
   key_pressed.cancel=false;
}
*/

struct page_typ
{
   char* name;
   
   struct page_typ * page_parent;
   struct page_typ * page_brother_next;
   struct page_typ * page_brother_previous;
   struct page_typ * page_child_first;

   void (*display) (); // pointeur de fonction sur fonction d'affichage

   void (*on_up) ();     // ptr de fct sur evenement appui touche haut 
   void (*on_down) ();   // ptr de fct sur evenement appui touche bas
   void (*on_left) ();   // ptr de fct sur evenement appui touche gauche
   void (*on_right) ();  // ptr de fct sur evenement appui touche droite
   void (*on_ok) ();     // ptr de fct sur evenement appui touche ok
   void (*on_cancel) (); // ptr de fct sur evenement appui touche cancel
};

struct page_typ page_time;
struct page_typ page_reset_time;
struct page_typ page_engine_menu;
struct page_typ page_engine_select;
struct page_typ page_engine_stroke;
struct page_typ page_engine_reset_time;
struct page_typ page_track_menu;
struct page_typ page_recall_menu;
   
struct page_typ * ptr_current_page;
struct page_typ * ptr_page_goto;


void display_page_name(struct page_typ* page) {
   printf("page->name=%s",page->name);
}

void display_page_type(struct page_typ* page) {
   printf("page->name= %s\n",page->name);
   struct page_typ* page_goto;

   page_goto = page->page_parent;
   printf(" parent= ");
   if (page_goto != NULL ) { 
      printf(" %s", page_goto->name);
   } else {
      printf("NULL");
   }
   
   printf("\n");
   
   page_goto = page->page_brother_next;
   printf(" next brother= ");
   if (page_goto != NULL ) {
      printf("%s", page_goto->name);
   } else {
      printf("NULL");
   }
   
   printf("\n");

   page_goto = page->page_brother_previous;
   printf(" previous brother= ");
   if (page_goto != NULL ) {
      printf("%s", page_goto->name);
   } else {
      printf("NULL");
   }
   
   printf("\n");
   
   page_goto = page->page_child_first;
   printf(" child first= ");
   if (page_goto != NULL ) {
      printf("%s", page_goto->name);
   } else {
      printf("NULL");
   }
   
   printf("\n");
}

void display_page_time(void) {
   printf("display_page_time");
   printf("\n");     
}

void display_page_reset_time(void) {
   printf("RESET TIME");
   printf("\n");
   printf("(OK/CANCEL?)");
   printf("\n");
}

void display_page_engine_menu(void) {
   printf("ENGINE MENU");
   printf("\n");
}

void display_page_engine_select(void) {
   printf("SELECT ENGINE");
   printf("\n");
   printf("1"); // TO FIX
   printf("\n");
   printf("(UP/DOWN?)");   
   printf("\n");
}

void display_page_engine_stroke(void) {
   printf("ENGINE 1"); // TO FIX
   printf("\n");
   printf("2 (UP/DOWN?)"); // TO FIX   
   printf("\n");
   printf("STROKES");
   printf("\n");
}

void display_page_engine_reset_time(void) {
   printf("ENGINE 1"); // TO FIX
   printf("\n");
   printf("RESET ENGINE TIME");   
   printf("\n");
   printf("(OK/CANCEL?)");   
   printf("\n");
}

void display_page_track_menu(void) {
   printf("TRACK MENU");
   printf("\n");
}

void display_page_recall_menu(void) {
   printf("RECALL MENU");
   printf("\n");
}

void update_key_pressed(void) {
   char key;
   key = 0;

   while(key!=KEY_OK && key!=KEY_CANCEL
      && key!=KEY_UP && key!=KEY_DOWN
      && key!=KEY_RIGHT && key!=KEY_LEFT) { 

      key = getch();
   
      switch(key) {
         case KEY_OK:
            //key_pressed.ok=true;
            (ptr_current_page->on_ok)();  
            break;
         case KEY_CANCEL:
            //key_pressed.cancel=true;
            (ptr_current_page->on_cancel)(); 
            break;
         case KEY_UP:
            //key_pressed.up=true;
            (ptr_current_page->on_up)();
            break;
         case KEY_DOWN:
            //key_pressed.down=true;
            (ptr_current_page->on_down)();
            break;
         case KEY_LEFT:
            //key_pressed.left=true;
            (ptr_current_page->on_left)();
            break;
         case KEY_RIGHT:
            //key_pressed.right=true;
            (ptr_current_page->on_right)();
            break;           
         default:
            //no_key_pressed();
            ptr_page_goto = ptr_current_page;
            break;
      }
   }
   if (ptr_page_goto != NULL) {
      ptr_current_page = ptr_page_goto;            
   }                  
}

void navigate_on_ok(void) {
   ptr_page_goto = ptr_current_page->page_child_first;
}

void navigate_on_cancel(void) {
   ptr_page_goto = ptr_current_page->page_parent;
}

void navigate_on_left(void) {
   ptr_page_goto = ptr_current_page->page_brother_previous;
}

void navigate_on_right(void) {
   ptr_page_goto = ptr_current_page->page_brother_next;
}

void navigate_on_up(void) {
}

void navigate_on_down(void) {
}


//void init_key_function(void) {
//}     

void init_page(struct page_typ* page, char* pgname) {
   page->name = pgname;
   page->page_parent = NULL;
   page->page_brother_next = NULL;
   page->page_brother_previous = NULL;
   page->page_child_first = NULL;
   
   page->display = &display_page_time;
   
   page->on_ok = &navigate_on_ok;
   page->on_cancel = &navigate_on_cancel;
   page->on_left = &navigate_on_left;
   page->on_right = &navigate_on_right;   
   page->on_up = &navigate_on_up;
   page->on_down = &navigate_on_down;
}

int main(int argc, char *argv[])
{
   init_page(&page_time, "page_time");
   
   init_page(&page_reset_time, "page_reset_time");
   
   init_page(&page_engine_menu, "page_engine_menu");
       init_page(&page_engine_select, "page_engine_select");
       init_page(&page_engine_stroke, "page_engine_stroke");
       init_page(&page_engine_reset_time, "page_engine_reset_time");

   init_page(&page_track_menu, "page_track_menu");   

   init_page(&page_recall_menu, "page_recall_menu");
   
   // parent init
   (&page_time)->page_parent = &page_time; //NULL;
   (&page_reset_time)->page_parent = &page_time; //NULL;
   (&page_engine_menu)->page_parent = &page_time; //NULL;
      (&page_engine_select)->page_parent = &page_engine_menu;
      (&page_engine_stroke)->page_parent = &page_engine_menu;
      (&page_engine_reset_time)->page_parent = &page_engine_menu;
   (&page_track_menu)->page_parent = &page_time; //NULL;
   (&page_recall_menu)->page_parent = &page_time; //NULL;
   

   // first child initialisation 
   (&page_time)->page_child_first = NULL;
   (&page_reset_time)->page_child_first = NULL;
   (&page_engine_menu)->page_child_first = (&page_engine_select);
      (&page_engine_select)->page_child_first = NULL;
      (&page_engine_stroke)->page_child_first = NULL;
      (&page_engine_reset_time)->page_child_first = NULL;   
   (&page_track_menu)->page_child_first = NULL;
   (&page_recall_menu)->page_child_first = NULL;
   
   // next brother init 
   (&page_time)->page_brother_next = &page_reset_time;
   (&page_reset_time)->page_brother_next = &page_engine_menu;
   (&page_engine_menu)->page_brother_next = &page_track_menu;
      (&page_engine_select)->page_brother_next = &page_engine_stroke;
      (&page_engine_stroke)->page_brother_next = &page_engine_reset_time;
      (&page_engine_reset_time)->page_brother_next = &page_engine_select;
   (&page_track_menu)->page_brother_next = &page_recall_menu;
   (&page_recall_menu)->page_brother_next = &page_time;
   
   // previous brother init
   (&page_time)->page_brother_previous = &page_recall_menu;
   (&page_reset_time)->page_brother_previous = &page_time;
   (&page_engine_menu)->page_brother_previous = &page_reset_time;
      (&page_engine_select)->page_brother_previous = &page_engine_reset_time;
      (&page_engine_stroke)->page_brother_previous = &page_engine_select;
      (&page_engine_reset_time)->page_brother_previous = &page_engine_select;
   (&page_track_menu)->page_brother_previous = &page_engine_menu;
   (&page_recall_menu)->page_brother_previous = &page_track_menu;
   
   // display init
   (&page_time)->display = &display_page_time;
   (&page_reset_time)->display = &display_page_reset_time;
   (&page_engine_menu)->display = &display_page_engine_menu;
   (&page_engine_select)->display = &display_page_engine_select;
   (&page_engine_stroke)->display = &display_page_engine_stroke;
   (&page_engine_reset_time)->display = &display_page_engine_reset_time;
   (&page_track_menu)->display = &display_page_track_menu;
   (&page_recall_menu)->display = &display_page_recall_menu;
   
   //init_key_function();
      
   // ask key init
   /*
   (&page_time)->waitkeypad = &;
   (&page_reset_time)->waitkeypad = &;
   (&page_engine_menu)->waitkeypad = &;
   (&page_engine_select)->waitkeypad = &;
   (&page_engine_stroke)->waitkeypad = &;
   (&page_engine_reset_time)->waitkeypad = &;
   (&page_track_menu)->waitkeypad = &;
   (&page_recall_menu)->waitkeypad = &;
   */
   

    ptr_current_page = &page_time; //&page_engine_menu;

    
   while(1) {
      system("cls");
      (ptr_current_page->display)();
      update_key_pressed();

      printf("\n");
   }

/*
   printf("\n");   
   waitkey();
*/
  
   printf("\n\n");
   system("PAUSE");	
   return 0;
}


