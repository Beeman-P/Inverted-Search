#ifndef HEADER_H
#define HEADER_H


typedef enum
{
   SUCCESS ,
   FAILURE
}Status;

typedef struct node
{
	char str[50];
	struct node *link;
}slist_t;

typedef struct hashtable
{
	int index;
	struct main_node *link;
}Hash;


typedef struct main_node
{
	int file_count;
	char word[20];
	struct sub_node *sub_link;
	struct main_node *main_link;
}Main_n;


typedef struct sub_node
{
	int word_count;
	char file_name[20];
	struct sub_node * link;
}Sub_n;


Status read_validation(int argc ,char *argv[],slist_t **head);
Status insert_last(slist_t **,char *);
Status create_hashtable(Hash *,int );
Status create_database(Hash *,Main_n **,Sub_n **,slist_t *,slist_t *);
Status display(Hash *,int,Main_n *,Sub_n *);
Status search(Hash *,Main_n *,Sub_n * ,char *,int);
Status save_database(char *,Hash *,int ,Main_n *,Sub_n *);

Status update(Hash *,Main_n **,Sub_n **,slist_t **,char *,int size);

#endif
