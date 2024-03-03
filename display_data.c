#include <stdio.h>
#include "header.h"

Status display(Hash *hash,int size,Main_n *main,Sub_n *sub)
{
  printf("--------------------------------------------------------------\n");
  printf("Index   Word           Filecount    Filename       Wordcount\n");
  printf("--------------------------------------------------------------\n");
  for(int i=0;i<size;i++)
  {
       if(hash[i].link!=NULL)
	   {
		   main=hash[i].link;
           while(main)
		   {
		       printf("[%2.2d]  %-15s %-9d",i,main->word,main->file_count);
			   sub=main->sub_link;
			   int c=0;
			   while(sub)
			   {
				   
				   if(c==0)
				   {
				      printf("    %-15s%-8d\n",sub->file_name,sub->word_count);
				   } 
				   else
				   {
					   printf("\t\t\t\t    %-15s %-8d\n",sub->file_name,sub->word_count);
				   }
				   sub=sub->link;
				   c++;
			   }
			   main=main->main_link;
			   printf("\n");
printf("---------------------------------------------------------------\n");
		   }

	   }
  }
	
  return SUCCESS;
}

