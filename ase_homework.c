
/**************************************************************************************************/
/* Copyright (C) Github.com/Reusssss, SSE@USTC, 2014-2015                                         */
/*                                                                                                */
/*  FILE NAME             :  ase_homework                                                         */
/*  PRINCIPAL AUTHOR      :  Jiang Zihao                                                          */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/11                                                           */
/*  DESCRIPTION           :  A simple cmd menu program                                            */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by JiangZihao, 2014/09/11
 *
 */


#include <stdio.h>
#include <stdlib.h>

#define CMD_LEN 1014
#define CMD_NUM 10

/*define the data struct*/
typedef struct DataNode{
    int  cmd;
    char cmd_list[CMD_LEN];
    struct DataNode *next;
}tDataNode;

main(){
/*initial the list*/
    tDataNode *head = NULL;
    int n;
    int i;
    tDataNode *p = NULL;
    
    for(n=0;n<CMD_NUM;n++){
      p = (tDataNode*)malloc(sizeof(tDataNode));  
      p->cmd = n ;
      i = n + 1;
      snprintf(p->cmd_list,CMD_LEN, "This is the %d cmd",i);
      p->next = head;
      head = p;  
      
    }
    printf("Menu List:\n");
    p = head;
    while(p != NULL){
        printf("the %d cmd is %s\n", p->cmd + 1, p->cmd_list);
        p = p->next;
    }
/*main cmd menu*/
    while(1){
      int cmd;
      printf("Please input a number between 1-10:");
      scanf("%d",&cmd);
      cmd--;
      if(cmd>=CMD_NUM||cmd<0){
         printf("This is a wrong cmd,please input again!\n");
         continue;
      }
      p = head;
      while(p!=NULL){
         if(p->cmd ==cmd){
           printf("the %d cmd is %s\n", p->cmd + 1, p->cmd_list);
           break;
         }
         p = p->next;  

      }
    }
}


    

