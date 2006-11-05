#include <stdio.h>
#include <stdlib.h>

//#include <string.h>

#define KEY_UP 'z'
#define KEY_DOWN 'w'
#define KEY_LEFT 'q'
#define KEY_RIGHT 's'
#define KEY_OK 'y'
#define KEY_CANCEL 'n'


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

void disp_page_time(void) {
   printf("disp_page_time");     
}

// TO DO
void page_key_interaction(struct page_typ* page) {
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
            page = page->page_parent; // TO FIX
            break;
         case KEY_DOWN:
            page = page->page_child_first; // TO FIX
            break;
         case KEY_LEFT:
            page = page->page_brother_previous; // TO FIX
            break;
         case KEY_RIGHT:
            page = page->page_brother_next; // TO FIX
            break;           
         default:

            break;
      }
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
/*   
   (&pages[page_time])-
   (&pages[page_reset_time])-
   (&pages[page_engine_menu])-
   (&pages[page_engine_select])-
   (&pages[page_engine_stroke])-
   (&pages[page_engine_reset_time])-
   (&pages[page_track_menu])-
   (&pages[page_recall_menu])-
*/

   init_page(&pages[page_time], "page_time");  //(&pages[page_time])->name = "page_time";
   //display_page_name(&pages[0]);
   //(&current_page)->display=&disp_page_time;
   
   init_page(&pages[page_reset_time], "page_reset_time");
   
   init_page(&pages[page_engine_menu], "page_engine_menu");
       init_page(&pages[page_engine_select], "page_engine_select");
       init_page(&pages[page_engine_stroke], "page_engine_stroke");
       init_page(&pages[page_engine_reset_time], "page_engine_reset_time");

   init_page(&pages[page_track_menu], "page_track_menu");   

   init_page(&pages[page_recall_menu], "page_recall_menu");

   
   // parent init
   (&pages[page_time])->page_parent = NULL;
   (&pages[page_reset_time])->page_parent = NULL;
   (&pages[page_engine_menu])->page_parent = NULL;
      (&pages[page_engine_select])->page_parent = &pages[page_engine_menu];
      (&pages[page_engine_stroke])->page_parent = &pages[page_engine_menu];
      (&pages[page_engine_reset_time])->page_parent = &pages[page_engine_menu];
   (&pages[page_track_menu])->page_parent = NULL;
   (&pages[page_recall_menu])->page_parent = NULL;
   

   // first child initialisation 
   (&pages[page_time])->page_child_first = NULL;
   (&pages[page_reset_time])->page_child_first = NULL;
   (&pages[page_engine_menu])->page_child_first = (&pages[page_engine_select]);
      (&pages[page_engine_select])->page_child_first = NULL;
      (&pages[page_engine_stroke])->page_child_first = NULL;
      (&pages[page_engine_reset_time])->page_child_first = NULL;   
   (&pages[page_track_menu])->page_child_first = NULL;
   (&pages[page_recall_menu])->page_child_first = NULL;
   
   // next brother init 
   (&pages[page_time])->page_brother_next = &pages[page_reset_time];
   (&pages[page_reset_time])->page_brother_next = &pages[page_engine_menu];
   (&pages[page_engine_menu])->page_brother_next = &pages[page_track_menu];
      (&pages[page_engine_select])->page_brother_next = &pages[page_engine_stroke];
      (&pages[page_engine_stroke])->page_brother_next = &pages[page_engine_reset_time];
      (&pages[page_engine_reset_time])->page_brother_next = &pages[page_engine_select];
   (&pages[page_track_menu])->page_brother_next = &pages[page_recall_menu];
   (&pages[page_recall_menu])->page_brother_next = &pages[page_time];
   
   // previous brother init
   (&pages[page_time])->page_brother_previous = &pages[page_recall_menu];
   (&pages[page_reset_time])->page_brother_previous = &pages[page_time];
   (&pages[page_engine_menu])->page_brother_previous = &pages[page_reset_time];
      (&pages[page_engine_select])->page_brother_previous = &pages[page_engine_reset_time];
      (&pages[page_engine_stroke])->page_brother_previous = &pages[page_engine_select];
      (&pages[page_engine_reset_time])->page_brother_previous = &pages[page_engine_select];
   (&pages[page_track_menu])->page_brother_previous = &pages[page_engine_menu];
   (&pages[page_recall_menu])->page_brother_previous = &pages[page_track_menu];
   
   // display init
   /*
   (&pages[page_time])->display = &;
   (&pages[page_reset_time])->display = &;
   (&pages[page_engine_menu])->display = &;
   (&pages[page_engine_select])->display = &;
   (&pages[page_engine_stroke])->display = &;
   (&pages[page_engine_reset_time])->display = &;
   (&pages[page_track_menu])->display = &;
   (&pages[page_recall_menu])->display = &;
   */
      
   // ask key init
   /*
   (&pages[page_time])->waitkeypad = &;
   (&pages[page_reset_time])->waitkeypad = &;
   (&pages[page_engine_menu])->waitkeypad = &;
   (&pages[page_engine_select])->waitkeypad = &;
   (&pages[page_engine_stroke])->waitkeypad = &;
   (&pages[page_engine_reset_time])->waitkeypad = &;
   (&pages[page_track_menu])->waitkeypad = &;
   (&pages[page_recall_menu])->waitkeypad = &;
   */
   
   struct page_typ* ptr_current_page;
   ptr_current_page = &pages[page_time];

    
   while(1) {
      display_page_name(ptr_current_page);
      page_key_interaction(ptr_current_page);

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


