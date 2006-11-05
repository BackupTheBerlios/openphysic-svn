#include <stdio.h>
#include <stdlib.h>

//#include <string.h>

#define KEY_UP 'z'
#define KEY_DOWN 'w'
#define KEY_LEFT 'q'
#define KEY_RIGHT 's'
#define KEY_OK 'y'
#define KEY_CANCEL 'n'

enum {
     GO_PARENT = 0,
     GO_BROTHER_NEXT,
     GO_BROTHER_PREVIOUS,
     GO_CHILD_FIRST,
};

struct page_typ
{
   char* name;
   struct page_typ * page_parent;
   struct page_typ * page_brother_next;
   struct page_typ * page_brother_previous;
   struct page_typ * page_child_first;
   void (*display) (); // pointeur de fonction sur fonction d'affichage
   void (*waitkeypad) (); // pointeur de fonction sur fonction d'attente de touches 
};



void copy_page(struct page_typ * page_from, struct page_typ * page_to) {
}

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
   
void waitkey(void) {
   char key;
   key = 0;
   
   while(key!=KEY_OK && key!=KEY_CANCEL
     && key!=KEY_UP && key!=KEY_DOWN
     && key!=KEY_RIGHT && key!=KEY_LEFT) { 

   key = getch();
   
   printf("%c",key);
   
   printf(" : ");
   //printf("\n");
  
   switch(key) {
      case KEY_OK:
           printf("YES");
           break;
      case KEY_CANCEL:
           printf("NO");
           break;
      case KEY_UP:
           printf("UP");
           break;
      case KEY_DOWN:
           printf("DOWN");
           break;
      case KEY_LEFT:
           printf("LEFT");
           break;
      case KEY_RIGHT:
           printf("RIGHT");
           break;           
      default:
           printf("UNDEF");
           break;
   }
      printf("\n");
   }
}



void init_page(struct page_typ* page, char* pgname) {
   page->name = pgname;
   page->page_parent = NULL;
   page->page_brother_next = NULL;
   page->page_brother_previous = NULL;
   page->page_child_first = NULL;
}

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

void disp_page_time(void) {
   printf("disp_page_time");     
}

// TO DO
void page_key_interaction(void) {
   char key;
   key = 0;

   
   while(key!=KEY_OK && key!=KEY_CANCEL
      && key!=KEY_UP && key!=KEY_DOWN
      && key!=KEY_RIGHT && key!=KEY_LEFT) { 

      key = getch();
   
      switch(key) {
         case KEY_OK:
            
            break;
         case KEY_CANCEL:

            break;
         case KEY_UP:
            //printf("PARENT ");
            ptr_page_goto = ptr_current_page->page_parent; // TO FIX
            break;
         case KEY_DOWN:
            //printf("FIRST CHILD ");
            ptr_page_goto = ptr_current_page->page_child_first; // TO FIX
            break;
         case KEY_LEFT:
            //printf("PREVIOUS BROTHER ");
            ptr_page_goto = ptr_current_page->page_brother_previous; // TO FIX
            //page_goto = &page_engine_menu;
            break;
         case KEY_RIGHT:
            //printf("NEXT BROTHER ");
            ptr_page_goto = ptr_current_page->page_brother_next; // TO FIX
            break;           
         default:

            break;
      }
   }
   if (ptr_page_goto != NULL) {
      //printf("NOT NULL");
      ptr_current_page = ptr_page_goto;
      //printf("page_goto :%p",ptr_page_goto);
            
   } else {
      //printf("NULL");
   }                      
}


int main(int argc, char *argv[])
{
   char* strTitle;
   strTitle = "My user interface";
   printf("%s\n\n",strTitle);
   
/*  
   struct page_typ current_page;
   init_page(&current_page);   
   (&current_page)->name="page1";
 
   (&current_page)->display = &disp_page_time; // initialise le pointeur de fonction d'affichage
   ((&current_page)->display)(); // affiche la page
*/     
 
/*
   #define Npages 10 // ATTENTION, il faut changer le nb de pages Npages !
   struct page_typ pages[Npages]; 
   enum {
      page_time = 0,
      page_reset_time,
      page_engine_menu,
         page_engine_select,
         page_engine_stroke,
         page_engine_reset_time,
      page_track_menu,
      page_recall_menu,
   };
*/




   init_page(&page_time, "page_time");  //(&pages[page_time])->name = "page_time";
   //display_page_name(&pages[0]);
   //(&current_page)->display=&disp_page_time;
   
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
   /*
   (&page_time)->display = &;
   (&page_reset_time)->display = &;
   (&page_engine_menu)->display = &;
   (&page_engine_select)->display = &;
   (&page_engine_stroke)->display = &;
   (&page_engine_reset_time)->display = &;
   (&page_track_menu)->display = &;
   (&page_recall_menu)->display = &;
   */
      
   // ask key init
   /*
   (&page_time])->waitkeypad = &;
   (&page_reset_time])->waitkeypad = &;
   (&page_engine_menu])->waitkeypad = &;
   (&page_engine_select])->waitkeypad = &;
   (&page_engine_stroke])->waitkeypad = &;
   (&page_engine_reset_time])->waitkeypad = &;
   (&page_track_menu])->waitkeypad = &;
   (&page_recall_menu])->waitkeypad = &;
   */
   

    ptr_current_page = &page_time; //&page_engine_menu;
  
/*
   struct page_typ current_page;
   current_page = page_time;
*/
    
   while(1) {
      //printf("%p",ptr_current_page);
      //display_page_name(ptr_current_page);
      display_page_type(ptr_current_page);
      page_key_interaction();
/*
      display_page_name(&current_page);
      page_key_interaction(&current_page);
*/
      printf("\n");
   }

   printf("\n");
   
   waitkey();
  
   printf("\n\n");
   system("PAUSE");	
   return 0;
}


