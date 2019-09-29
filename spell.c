#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

//professor said i would get full credit even though i get 1!=2 for buffer overflow.
int check_words(FILE* fp, hashmap_t hashtable[], char *misspelled[]);
bool load_dictionary(const char *dictionary_file, hashmap_t hashtable[]);
bool check_word(const char *word, hashmap_t hashtable[]);
int hash_function(const char *word);

bool check_word(const char *word, hashmap_t hashtable[])
{

int bucket;
char temp[LENGTH + 1];
node* node ;
//strcpy(temp,word);
for (int i=0;i<=strlen(word); i++) {

	temp[i]=tolower(word[i]);
//	}
}

bucket = hash_function(temp);
node = hashtable[bucket];
while (node != NULL)
{
//printf("word=%s\n", node->word);
if (strcmp(temp, node->word) == 0) //seg faulting.
   return true;

node = node->next;

}

return false;
}

bool load_dictionary(const char *dictionary_file, hashmap_t hashtable[])
{
#define BUZZ_SIZE 1024

int i,bucket, wordalength;
char worda[LENGTH + 1] = "\0";
char tempa[LENGTH + 1] = "\0";
int x;
x = 0;
wordalength =0;
for( i=0; i<=2000; i++){    // SHOULD BE HASH_SIZE, whatever is 2000
	hashtable[i] = NULL;
	 //word[i] = '\0' ;
}

FILE *fp = fopen(dictionary_file, "r");

if (fp == NULL)
    return false;
while (fgets (worda,46,fp) != NULL ){
	wordalength = strlen(worda);
	for( i=0; i<=wordalength; i++){
		if ((worda[i] == ' ') || (worda[i] == '\n'))
			tempa[i]='\0';
		else
			tempa[i] = tolower(worda[i]);
		
		}
x = x +1;

    hashmap_t hash = (hashmap_t) malloc(sizeof(node));
	hash->next = NULL;
	strcpy(hash->word,(tempa)); 

	bucket = hash_function(hash->word);
//printf(" this is tempa bro %s %x \n",hash->word, x);


	if (bucket < HASH_SIZE){ // tried this but still seg fault.

		if (hashtable[bucket] == NULL){
			hash->next = NULL;
			hashtable[bucket] = hash;
	}
		else{
			hash->next = hashtable[bucket];
			hashtable[bucket] = hash;
			}
	}
//free(hash);
}
fclose(fp);

return true;
}


int check_words(FILE *fp, hashmap_t hashtable[], char* misspelled[])
{

//char c;
int num_misspelled =0;
int i = 0;
char word[LENGTH + 1]="\0";
char tempb[LENGTH + 1]="\0";
bool result = true;

while (fscanf(fp, "%46s", tempb) != EOF){
int lengthaa= strlen(tempb); //if null byte doesnt exist break out of the loop
	if (lengthaa > LENGTH)
		continue;
  for(i=0;i<=45;i++){ 
  if((tempb[i] == ' ') || (tempb[i] == '\n') || (tempb[i] == '\r')){
		break;}
	
  else{
	//printf("%c",c);
	word[i] = tolower(tempb[i]);}
}
word[LENGTH] = '\0';	
int lengtha = strlen(word);
//printf("length of word: %d", lengtha);
if((isalpha(word[lengtha-1])) == 0){
	word[lengtha-1] = '\0';}
if((isalpha(word[0])) == 0)
	word[0] = '\0';
    
	result = check_word(word, hashtable);
	if(result == false){
     misspelled[num_misspelled] = malloc(strlen(word));    
	 strcpy(misspelled[num_misspelled], word);
	num_misspelled++;
}
//printf(" num of misspelled %d || the word is : %s || value of i is : %d \n", num_misspelled, word, i);
memset(word, 0, sizeof(word));
}

return num_misspelled;
}

