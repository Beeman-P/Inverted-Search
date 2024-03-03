#include <stdio.h>
#include <string.h>
#include "header.h"
#include <ctype.h>
#include <stdlib.h>


Status create_database(Hash *hash,Main_n **main,Sub_n **sub,slist_t *head,slist_t *up_head)
{
	FILE *fp;
	char file_name[20];
	int pos;
	char str[20];
	printf("INFO : Data base is created ");
	while(head)
	{
		if(up_head!=NULL)
		{
			slist_t *t=head;
			while(t!=NULL && up_head!=NULL)
			{
				t=t->link;
				up_head=up_head->link;
			}
			head=t;
		}
		strcpy(file_name,head->str);
		fp=fopen(file_name ,"r");
		if(fp==NULL)
		{
			return FAILURE;
		}
		while(fscanf(fp,"%s",str)==1)
		{
			pos=toupper(str[0])%65;
			if(hash[pos].link==NULL)
			{
				Main_n *new_main=malloc(sizeof(Main_n));
				*main=new_main;
				hash[pos].link=new_main;
				if(new_main==NULL)
				{
					return FAILURE;
				}
				new_main->file_count=1;
				strcpy(new_main->word,str);
				new_main->sub_link=NULL;
				new_main->main_link=NULL;
			    Sub_n *new_sub=malloc(sizeof(Sub_n));
		    	if(new_sub==NULL)
			   {
			    	return FAILURE;
			   }
			   new_sub->word_count=1;
			    strcpy(new_sub->file_name,file_name);
		    	new_sub->link=NULL;
			   (*main)->file_count=1;
			   (*main)->sub_link=new_sub;
			   
		    }
			else if(hash[pos].link!=NULL)
			{ 
				Main_n *temp_main=hash[pos].link;
				Main_n *prev_main=hash[pos].link;
				int flag1=0;
				while(temp_main!=NULL)
				{

					if(strcmp(temp_main->word,str)==0)
					{
						flag1=1;
						Sub_n *temp_sub=temp_main->sub_link;
						Sub_n *prev_sub=temp_main->sub_link;
						int flag=0;
						while(temp_sub!=NULL)
						{
							if(strcmp(temp_sub->file_name,file_name)==0)
							{
                                flag=1;
								temp_sub->word_count++;
							}
							prev_sub=temp_sub;
							temp_sub=temp_sub->link;
						}
						if(flag==0)
						{
							Sub_n *new_sub=malloc(sizeof(Sub_n));
							if(new_sub==NULL)
							{
								return FAILURE;
							}
							strcpy(new_sub->file_name,file_name);
							new_sub->word_count=1;
							new_sub->link=NULL;
                            prev_sub->link=new_sub;
							temp_main->file_count++;
						}


					}
					prev_main=temp_main;
					temp_main=temp_main->main_link;

				}
					if(flag1==0)
					{
						Main_n *new_main=malloc(sizeof(Main_n));
						if(new_main==NULL)
						{
							return FAILURE;
						}
						new_main->file_count=1;
						strcpy(new_main->word,str);
						new_main->sub_link=NULL;
						new_main->main_link=NULL;
						prev_main->main_link=new_main;
						Sub_n *new_sub=malloc(sizeof(Sub_n));
						if(new_sub==NULL)
						{
							return FAILURE;
						}
						new_sub->word_count=1;
						strcpy(new_sub->file_name,file_name);
						new_sub->link=NULL;
						new_main->sub_link=new_sub;
			        }
				}

			}
		
			
     fclose(fp);
	 printf("%s ",head->str);
     head=head->link;
	 
	

    }
      return SUCCESS;
}
