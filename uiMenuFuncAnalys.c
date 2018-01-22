#include "stdio.h"
#include "stdlib.h"
#include "feFuncAnalys.h"


char       cbuff[10];                         /* input buffer         */

/****************************************************************************/
/*  dispmenu: display the user menu                                          */
/*****************************************************************************/
char uiGetChoice(){
   printf("\nChoice: ");
   scanf("%s", cbuff);

   return cbuff[0];
}


static void uiDispMenu() {

   printf("\n");
   printf("***************************************************************\n");
   printf("***                                                         ***\n");
   printf("***   a:   Display this menu                                ***\n");
   printf("***   b:   All tests                                        ***\n");
   printf("***                                                         ***\n");
   printf("***   Bubblesort:                                           ***\n");
   printf("***   c:   Best case                                        ***\n");
   printf("***   d:   Worst case                                       ***\n");
   printf("***   e:   Random                                           ***\n");
   printf("***                                                         ***\n");
   printf("***   Insertion sort:                                       ***\n");
   printf("***   f:   Best case                                        ***\n");
   printf("***   g:   Worst case                                       ***\n");
   printf("***   h:   Random                                           ***\n");
   printf("***                                                         ***\n");
   printf("***   Quicksort:                                            ***\n");
   printf("***   i:   Best case                                        ***\n");
   printf("***   j:   Worst case                                       ***\n");
   printf("***   k:   Random                                           ***\n");
   printf("***                                                         ***\n");
   printf("***   Linear Search:                                        ***\n");
   printf("***   l:   Best case                                        ***\n");
   printf("***   m:   Worst case                                       ***\n");
   printf("***   n:   Random                                           ***\n");
   printf("***                                                         ***\n");
   printf("***   Binary Search:                                        ***\n");
   printf("***   o:   Best case                                        ***\n");
   printf("***   p:   Worst case                                       ***\n");
   printf("***   q:   Random                                           ***\n");
   printf("***                                                         ***\n");
   printf("***   r:   quit the program                                 ***\n");
   printf("***                                                         ***\n");
   printf("***************************************************************\n");
   printf("\n");
   }

/****************************************************************************/
/*  runmenu: execute the user menu                                          */
/****************************************************************************/

void uiRunMenu(){
   char   choice;                     /* user menu selection  */

   // uiDispMenu();
   // printf("\nChoice: ");

   do {
      uiDispMenu();
      choice = uiGetChoice();
      switch(choice) {

         case 'a': case 'A':     uiDispMenu();                 break;
         case 'b': case 'B':     feRunAllTests();              break;
         //Bubble
         case 'c': case 'C':     febsbc();                     break;
         case 'd': case 'D':     febswc();                     break;
         case 'e': case 'E':     febsrc();                     break;
         //Insertion
         case 'f': case 'F':     feisbc();                     break;
         case 'g': case 'G':     feiswc();                     break;
         case 'h': case 'H':     feisrc();                     break;
         //Quicksort
         case 'i': case 'I':     feqsbc();                     break;
         case 'j': case 'J':     feqswc();                     break;
         case 'k': case 'K':     feqsrc();                     break;
         //Linear
         case 'l': case 'L':     felsbc();                     break;
         case 'm': case 'M':     felswc();                     break;
         case 'n': case 'N':     felsrc();                     break;
         //Binary
         case 'o': case 'O':     febisbc();                    break;
         case 'p': case 'P':     febiswc();                    break;
         case 'q': case 'Q':     febisrc();                    break;

         case 'r': case 'R': exit(0);                          break;

         default:  /*ui_InvalidChoice(); UI_dispmenu();   */        break;
      }
      } while (choice != 'Z' && choice != 'z');
      printf("\n");
   }

/****************************************************************************/
/* end of menu functions                                                    */
/***************************************************************************/