/*
  simple sample for malloc and pointers pointing to
  structures with pointers pointing to itself, somehow

  From simple to complex but easyier
  - analyse structure of program
  - draw memory diagram
  - static memory alloc. vs. dynamic memory alloc.

  compile with:
  gcc -Wall -g  -o akquise akquise.c

*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>


#define MAX_PERSON 3

int main(){

  /*
	prologue
  */

  char namebuffer[10];
  int len;
  int i;


  /*
	first approach:
	everything is static, i.e. memory space is allocated before the program starts
  */
  struct person1 {
	char name[10];
	int age;
  };

  char *cp;
  char *cpbuffer;
  struct person1 hans;

  printf("Enter Name(1): ");
  scanf("%s", namebuffer);

  printf("name is %s with length %i\n", namebuffer, (int) strlen(namebuffer));

  len = strlen(namebuffer);
  cp=namebuffer; // array ist pointer
  for(i=0;i<len;i++){
	hans.name[i] = namebuffer[i];
  }
  hans.name[i]='\0';


  /*
	second approach:
	some memory space is allocated before the program starts,
	some memory space is allocated during run-time (with malloc)
  */
  struct person2 {
	char *name;
	int age;
  };

  struct person2 peter;

  printf("Enter name(2): ");
  scanf("%s", namebuffer);
  printf("name is %s with length %i\n", namebuffer, (int) strlen(namebuffer));

  len=0;
  while(namebuffer[len++]);
  peter.name = (char *) malloc(len);

  cpbuffer = namebuffer;
  cp=peter.name;
  while(*cpbuffer){
	*(cp++) = *(cpbuffer++);
  }


  /*
	third approach: we now have not only one person but lots of persons
	some memory space is allocated before the program starts,
	some memory space is allocated during run-time (with malloc)
  */


  struct person2 *hotel[MAX_PERSON];

  int agebuffer;

  for(i=0 ; i<MAX_PERSON; i++){
    printf("Enter Name(Hotel %d): ", i);
	scanf("%s", namebuffer);

	printf("Enter age(Hotel %d): ", i);
	scanf("%i", &agebuffer);

	hotel[i] = malloc(sizeof(struct person2));

	len=0;
	while(namebuffer[len++]);

	(*hotel[i]).name = (char *) malloc(len); //cast to char pointer
	cp=(*hotel[i]).name;
	cpbuffer = namebuffer;

	while( (*(cp++) = *(cpbuffer++)) ); // fill name with values of namebuffer

	(*hotel[i]).age = agebuffer;
  }

  for(i=0; i< MAX_PERSON; i++){
	printf("Name(3) is %s\n age(3) is %d\n\n", (*(hotel[i])).name, (*(hotel[i])).age);
  }



  /*
	fourth approach: our hotel of person with just the right amount of needed memory.
	most of the memory is allocated during run-time (dynamic)
  */


  struct node {
	struct person2 *pp;
	struct node *next;
  };

  struct node *list = NULL;

  struct node *head;
  struct node *middle;
  struct node *last;

  head = malloc(sizeof(struct node));
  middle = malloc(sizeof(struct node));
  last = malloc(sizeof(struct node));

  (*head).pp = &peter;
  (*middle).pp = hotel[0];
  (*last).pp = hotel[1];

  (*head).next = middle;
  (*middle).next = last;
  (*last).next = NULL;

  list = head;

  struct node* current;
  for(i=0, current=list; current; current=(*current).next){
	i++;
  }

  printf("We all knew it: length of list is %d\n", i);



  struct node *newnode;

  newnode = malloc(sizeof(struct node));

  (*newnode).pp = hotel[2];

  (*newnode).next = list;

  list = newnode;

  for(i=0, current=list; current; current=(*current).next){
	i++;
  }

  printf("We all knew it: length of list is %d\n", i);

  return 0;
}
