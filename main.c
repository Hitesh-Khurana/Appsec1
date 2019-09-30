#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

//#define DICTIONARY "wordlist.txt"
//#define TESTDICT "test1.txt"
//gcc -Wall -c spell.c
//gcc -Wall -o my-main my-main.o spell.o dictionary.o -lcheck -lm -lrt -lpthread -lsubunit
/**
Commands to test with valgrind.
gcc -Wall -o my-main my-main.c -g spell.c dictionary.o -lcheck -lm -lrt -lpthread -lsubunit
valgrind --track-origins=yes --leak-check=full ./my-main 



AFL
gcc -o my-main spell.c dictionary.c my-main.c -g

afl-gcc -o my-main my-main.c spell.c dictionary.c dictionary.h
afl-cmin -i test-cases/ -o tests -- ./my-main @@ wordlist.txt 
afl-fuzz -i tests/ -o output ./my-main @@ wordlist.txt 

**/
int main( int argc, const char* argv[] ){
 node* current_node;
       node* new_node;
	FILE *fp ;
     //   node* tempbruh;
	int num_misspelled =0;
	//FILE *fp = fopen("test1.txt", "r");
	printf("testing wordlist : %s \n", argv[1]);
        fp =fopen( argv[1], "r");
printf("did we open the file");
  	printf("dictionary  : %s \n", argv[2]);
	char *misspelled[MAX_MISSPELLED];
	printf("Main\n");
	printf("1st func\n");
	hashmap_t hashtable[HASH_SIZE];
	bool loaded = load_dictionary(argv[2], hashtable);
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
for ( int y=0; y<HASH_SIZE; y++ ){
    current_node = hashtable[y];
      if (hashtable[y] ==NULL) {
	current_node = hashtable[y];
	//hashmap_t new_node;
	}

          while ( current_node != NULL )
          {
       	      // printf ("%s %i \n", hashtable[y]->word, y) ;
               new_node = current_node->next ;
               free (current_node) ;
               current_node = new_node ;
          }

     }

}
