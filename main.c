#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

#define DICTIONARY "wordlist.txt"
#define TESTDICT "test.txt"
//gcc -Wall -c spell.c
//gcc -Wall -o my-main my-main.o spell.o dictionary.o -lcheck -lm -lrt -lpthread -lsubunit

	
int main( int argc, const char* argv[] ){
 node* current_node;
       node* new_node;
     //   node* tempbruh;
//	node* current = *head_ref;  

	FILE *fp = fopen("test.txt", "r");
	char *misspelled[1000];
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
	bool checksw = check_words(fp, hashtable, misspelled);
	if (!checksw) {
	     printf("Failed to check the wordsss\n");
	    return -1;
	}
	fclose(fp);
	printf("End Main\n");
	for(int i=0;i<1000;i++){	
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

