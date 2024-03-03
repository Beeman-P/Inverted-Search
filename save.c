#include <stdio.h>
#include "header.h"
#include <string.h>

Status save_database(char *file,Hash *hash,int size,Main_n *main,Sub_n  *sub)
{
	if(strstr(file,".txt")!=NULL)
	{
		FILE *fp=fopen(file,"w");
		if(fp==NULL)
		{
			return FAILURE;
		}
		for(int i=0;i<size;i++)
		{
			if(hash[i].link!=NULL)
			{

				main=hash[i].link;
				Main_n  *temp=main;

				while(main)
				{
                    int c=0;
                    
                    fprintf(fp,"#%d;",i);
					fprintf(fp,"%s;",main->word);
					fprintf(fp,"%d;",main->file_count);
					sub=main->sub_link;
					while(sub)
					{
						fprintf(fp,"%s;",sub->file_name);
						fprintf(fp,"%d;",sub->word_count);
						sub=sub->link;
					}

					fprintf(fp,"#\n");
					main=main->main_link;

				}
				

			}

		}
		fclose(fp);

	}
	else
	{
		printf("Please pass valid file\n");
		return FAILURE;
	}

	
  return 0;
}

