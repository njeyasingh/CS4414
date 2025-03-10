#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

void visit(void *v){
    printf("%s",(char *)v); 
//printf("string");
}

int main(int argc, char ** argv){
    if (argc != 3) {
        printf("ERROR\n");
        return 1;
    }
    
    if(strcmp("echo", argv[2])== 0){
        FILE *file = fopen(argv[1], "r");
        char line[41];
        if(fgets(line, 42, file) == NULL) 
            printf("<EMPTY>");
        else{
           if (line[0] != '\n') {
                 printf("%s", line);
             
            }
        }

        while(fgets(line, 41, file) != NULL  ) {
            if (line[0] != '\n'){
            printf("%s", line);
            }
    }

    }

    if(strcmp("tail", argv[2])== 0){
        FILE *file = fopen(argv[1], "r");
        list_t *singly = (list_t*) malloc(sizeof(list_t));
        singly ->head = NULL;
        singly->tail = NULL;
        char line[42];
        if(fgets(line, 42, file) == NULL) 
            printf("<EMPTY>");
        else{
           if (line[0] != '\n') {
                list_insert_tail(singly, line);
             
            }
        }
        while(fgets(line, 42, file) != NULL) {
            if (line[0] != '\n') {       
                list_insert_tail(singly, line);
            }
        }
       
        list_visit_items(singly, visit);
     

    }

    if(strcmp("tail-remove", argv[2])== 0){
        FILE *file = fopen(argv[1], "r");
        //printf("hi");
        list_t *singly = (list_t*) malloc(sizeof(list_t));
        //printf("hi2");
        singly ->head = NULL;
        singly->tail = NULL;
        char line[42];
        //printf("hi3");
       if(fgets(line, 42, file) == NULL) 
            printf("<EMPTY>");
        else{
           if (line[0] != '\n') {
                list_insert_tail(singly, line);
             
            }
        }


        
        while(fgets(line, 42, file) != NULL) {
            //printf("hi4");
            // debugging testing line
            //printf("(%s)",line);
            if (line[0] != '\n') {
                list_insert_tail(singly, line);
            }
        }
            //printf("\n done reading file \n");
        int removed = 0;
        while(singly->number > 0){
            while(removed <3){
                list_remove_head(singly);
                removed+=1;
            }
            removed = 0;
            list_visit_items(singly, visit);
            if(singly->number == 0)
                printf("<EMPTY>");
            else
                printf("\n----------\n");
                
            
    
             

        }
    }
}