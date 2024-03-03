#include <stdio.h>
#include "header.h"
#include <string.h>
#include <stdlib.h>
Status read_validation(int argc,char *argv[],slist_t **head)
{
	FILE *fp;
	for(int i=1;i<argc;i++)
	{
		if((strstr(argv[i],".txt"))!=NULL)
		{
			if((fp=fopen(argv[i],"r"))!=NULL)
			{
				fclose(fp);
				fp=fopen(argv[i],"a");
				if(ftell(fp)>1)
				{
					
                    //printf("%s File is non empty\n",argv[i]);
					 if(insert_last(head,argv[i])==FAILURE)
					 {
						 printf("Warning : %s Duplicate files found\n",argv[i]);
					 }   
				}
				else
				{
					printf("Warning : %s File is empty\n",argv[i]);
				}
                fclose(fp);
			}
			else
			{
				printf("Warning : %s File does Not Exist\n",argv[i]);
			}


		}
		else
		{
			printf("Warning : %s Pass Valid file \n",argv[i]);
		}
	}

	
  return SUCCESS;
}
Status insert_last(slist_t **head,char *string)
{

	  slist_t *new_node=malloc(sizeof(slist_t));
	  if(new_node==NULL)
      {
			printf("Error : Memory Not allocated for node\n");
		    return FAILURE;
	   }
	   strcpy(new_node->str,string);
	   new_node->link=NULL;
	   if(*head==NULL)
	   {
     		 *head=new_node;
	   }
	   else
	   {
		   slist_t *temp=*head;
		   int flag=0;
		   while(temp!=NULL)
		   {
             if(strcmp(temp->str,string)==0)
			 {
					flag=1;
					break;
			 }
		      temp=temp->link;
	       }
		  temp=*head;
		  if(flag==0)
		  {
             while(temp->link!=NULL)
			 {
					temp=temp->link;
			 }
			 temp->link=new_node;
		  }
		 else if(flag==1)
		 {
				return FAILURE;
		 }
      }
}
