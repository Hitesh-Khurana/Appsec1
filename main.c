#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

#define DICTIONARY "wordlist.txt"
#define TESTDICT "test1.txt"
//gcc -Wall -c spell.c
//gcc -Wall -o my-main my-main.o spell.o dictionary.o -lcheck -lm -lrt -lpthread -lsubunit

	
int main( int argc, const char* argv[] ){
 node* current_node;
       node* new_node;
     //   node* tempbruh;
//	node* current = *head_ref;  
int num_misspelled =0;
	FILE *fp = fopen("test1.txt", "r");
	char *misspelled[MAX_MISSPELLED];
	printf("Main\n");
	printf("1st func\n");
	hashmap_t hashtable[HASH_SIZE];
	bool loaded = load_dictionary(DICTIONARY, hashtable);
	if (!loaded) {
	    printf("Failed to load dictionary\n");
	    return -1;
	}

printf("2nd func\n");
	bool check = check_word("JusTin", hashtable);
	if (!check) {
	    printf("Failed to check the word\n");
	    return -1;
	}
printf("3rd func\n");
    num_misspelled = check_words(fp, hashtable, misspelled);
	
	fclose(fp);
	printf("End Main\n");
printf("value of num_misspelled: %d\n",num_misspelled);
	for(int i=0;i<num_misspelled;i++){	
	free(misspelled[i]);

}

for ( int y=0; y<HASH_SIZE; y++ )
     {
       if ( hashtable[y] == NULL ) 
		continue;
//	printf ("%s %i \n", hashtable[x]->word, x) ;
          current_node = hashtable[y] ;
          while ( current_node != NULL )
          {
               new_node = current_node->next ;
               free (current_node) ;
               current_node = new_node ;
          }
     }



}

//        node->word--;
//hashtable[i], hashtable[i]->next  (hashtable[i]->next)->next e
//ode = nextLink;
   //         if(currLink != 0)
     //           nextLink = currLink->next;
//make func to deallocate misspelled and the dictionary
//loop through misspelled[i] and set misspelled[i] to null
//deallocate every node in linked list and then deallocate t
//for and while
//tell professor what i learned and how did i approach to fix it
//for the report explain what is the error in valgrind and how to fix it.
//afl
//if there are unique crashes why	
	//why did it crash and how would you fix it.
//wont be unique because we dont take input from the user. 
//rework main to take input from the user.
// if there are not unique crashes why not

