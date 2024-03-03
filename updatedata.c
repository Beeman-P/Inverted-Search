#include <stdio.h>
#include "header.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

Status update(Hash *hash,Main_n **main,Sub_n **sub,slist_t **up_head,char *filename,int size)
{

	FILE *fp;
	char ch,c;
	char str[50];
	int index;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		return FAILURE;
	}
	ch=getc(fp);
	fseek(fp,-2,SEEK_END);
    c=getc(fp);
	if(*up_head!=NULL)
	{ 
		printf("INFO : Database is already Updated\n ");
		return FAILURE;
	}
	if(ch=='#' && c=='#')
	{
		fseek(fp,0,SEEK_SET);
		while(fscanf(fp,"%s",str)==1)
		{
          index=atoi(strtok(&str[1],";"));
	      if(hash[index].link==NULL)
		  {
			  Main_n *new_main=malloc(sizeof(Main_n));
			  *main=new_main;
			  hash[index].link=new_main;
			  if(new_main==NULL)
			  {
				  return FAILURE;
			  }
			  strcpy(new_main->word,strtok(NULL,";"));
			  new_main->file_count=atoi(strtok(NULL,";"));
			  new_main->sub_link=NULL;
			  new_main->main_link=NULL;
			  for(int i=0;i<new_main->file_count;i++)
			  {
				  Sub_n *new_sub=malloc(sizeof(Sub_n));
				  if(new_sub==NULL)
				  {
					  return FAILURE;
				  }
				  if(new_main->sub_link==NULL)
				  {
					  new_main->sub_link=new_sub;
					  *sub=new_sub;
				  }
				  else
				  {
					  (*sub)->link=new_sub;
					  *sub=new_sub;
				  }
				  strcpy(new_sub->file_name,strtok(NULL,";"));
				  new_sub->word_count=atoi(strtok(NULL,";"));
				  new_sub->link=NULL;
				  
              }
		  }
		   else if(hash[index].link!=NULL)
		   {
			   Main_n *temp_main=hash[index].link;
			   Main_n *prev_main=hash[index].link;
			   while(temp_main!=NULL)
			   {
				   prev_main=temp_main;
				   temp_main=temp_main->main_link;
			   }
			    Main_n *new_main=malloc(sizeof(Main_n));
				if(new_main==NULL)
				{
					return FAILURE;
				}
				prev_main->main_link=new_main;
				strcpy(new_main->word,strtok(NULL,";"));
				new_main->file_count=atoi(strtok(NULL,";"));
				new_main->sub_link=NULL;
				new_main->main_link=NULL;
				for(int i=0;i<new_main->file_count;i++)
				{
					Sub_n *new_sub = malloc(sizeof(Sub_n));
					if(new_sub==NULL)
					{
						return FAILURE;
					}
					if(new_main->sub_link==NULL)
					{
						new_main->sub_link=new_sub;
						*sub=new_sub;
					}
					else
					{
						(*sub)->link=new_sub;
						*sub=new_sub;
					}
					strcpy(new_sub->file_name,strtok(NULL,";"));
					new_sub->word_count=atoi(strtok(NULL,";"));
					new_sub->link=NULL;

				}
		   }
		}
		fclose(fp);
    for(int i=0;i<size;i++)
	{
		
		if(hash[i].link!=NULL)
		{
		   Main_n *main=hash[i].link;
			while(main)
			{
				Sub_n *sub=main->sub_link;
				while(sub)
				{
					insert_last(up_head,sub->file_name);
					sub=sub->link;
				}
				main=main->main_link;
			}

		}

	}



		return SUCCESS;
	}
	else
	{
         printf("Info : %s file is not a Backup file\n",filename);
		return FAILURE;
	}
}
	


