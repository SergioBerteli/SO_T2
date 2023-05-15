#include <stdlib.h>
#include <stdio.h>

#include "schedule_rr.h"
#include "schedulers.h"
#include "task.h"
#include "list.h"
#include "CPU.h"

// add a task to the list 
void add(char *name, int priority, int burst){
   Task * temp = malloc(sizeof(Task));
   temp->name = name;
   temp->burst = burst;
   temp->priority = priority;

   int cont = 0;
   struct node *nav;
   nav = (fila);
   while (nav != NULL) {
      cont++;
      nav = nav->next;
   }
   temp->tid = cont;
   insert(&fila, temp);
}

// invoke the scheduler
void schedule(){
   struct node * nav;

   while (fila != NULL) {
      nav = fila;
      while (nav!=NULL) {
         run(nav->task, QUANTUM);
         nav->task->burst-= QUANTUM;
         if (nav->task->burst <= 0) {
            struct node * nav_p = nav->next;
            finish(nav->task);
            delete(&fila, nav->task);
            free(nav->task);
            nav = nav_p;
         }
         else {
            remaining(nav->task);
            nav = nav->next;
         }
      }
   }
}
