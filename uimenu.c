#include "uimenu.h"
#include "stdio.h"

/****************************************************************************/
/*  dispmenu: display the user menu                                          */
/*****************************************************************************/

static void UIdispMenu() {

   printf("\n");
   printf("***************************************************************\n");
   printf("***                                                         ***\n");
   printf("***   m:   display this menu                                ***\n");
   printf("***   o:   display current mode (sorted/pos/stack/queue)    ***\n");
   printf("***                                                         ***\n");
   printf("***   v:   sequence is sorted                               ***\n");
   printf("***   w:   sequence is by position                          ***\n");
   printf("***   x:   sequence is a stack                              ***\n");
   printf("***   y:   sequence is a queue                              ***\n");
   printf("***                                                         ***\n");
   // if      (seqmode==2) {
   printf("***   d:   display the stack                                ***\n");
   printf("***   a:   add a value to the stack (push)                  ***\n");
   printf("***   f:   find a value in the stack                        ***\n");
   printf("***   r:   remove a value from the stack (pop)              ***\n");

   // }
   // else if (seqmode==3) {
   printf("***   d:   display the queue                                ***\n");
   printf("***   a:   add a value to the queue (enqueue)               ***\n");
   printf("***   f:   find a value in the queue                        ***\n");
   printf("***   r:   remove a value from the queue (dequeue)          ***\n");
   // }
   // else {
   printf("***   d:   display the sequence                             ***\n");
   printf("***   a:   add a value to the sequence                      ***\n");
   printf("***   f:   find a value in the sequence                     ***\n");
   printf("***   r:   remove a value from the sequence                 ***\n");
   // }
   printf("***                                                         ***\n");
   printf("***   q:   quit the program                                 ***\n");
   printf("***                                                         ***\n");
   printf("***************************************************************\n");
   printf("\n");
   }

/****************************************************************************/
/*  runmenu: execute the user menu                                          */
/****************************************************************************/

void UIrunMenu(){
   char   choice;                     /* user menu selection  */

   UIdispMenu();
   do {
      // choice = UIgetChoice();
      switch(choice) {

         case 'm': case 'M': UIdispMenu();                     break;
         case 'o': case 'O': //UIshowMode();                     break;

         case 'v': case 'V': //seqmode=0;                         break;
         case 'w': case 'W': //seqmode=1;                         break;
         case 'x': case 'X': //seqmode=2;                         break;
         case 'y': case 'Y': //seqmode=3;                         break;
         case 'z': case 'Z': //echomode=1;                        break;

         case 'd': case 'D': //fe_display();                      break;
         case 'a': case 'A': //UI_add();                          break;
         case 'f': case 'F': //UI_is_member();                    break;
         case 'r': case 'R': //UI_remove();                       break;

         case 'q': case 'Q': /*ui_byebye();*/                       break;

         default:  /*ui_InvalidChoice(); UI_dispmenu();   */        break;
      }
      } while (choice != 'Q' && choice != 'q');
      printf("\n");
   }

/****************************************************************************/
/* end of menu functions                                                    */
/***************************************************************************/