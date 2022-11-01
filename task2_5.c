#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char* word;
    void* next;
} spis;
spis* start = NULL;
char ADD(spis* spisok, char* word) {
    spis* owner;
    while (spisok != NULL) {
        owner = spisok;
        spisok = spisok->next;
    }
    owner->next = (spis*) malloc(sizeof(spis));
    ((spis*) owner->next)->word = (char*) calloc(strlen(word) + 1, sizeof(char));
    strcpy(((spis*) owner->next)->word, word);
    ((spis*) owner->next)->next = NULL;
}
char preobr(spis* spisok,char* word){
    spis* checker;
    checker = spisok;
    spis* red;
    int counter = 0;
    while(spisok->next!=NULL){
        if(strcmp(spisok->word,word) == 0 && spisok->next != NULL){ /*&*/
            if(checker == spisok){
                spisok->word = "աաաաաա";
                counter += 1;
            }
            red = checker;
            checker = spisok->next;
            spisok=red;
            spisok->next=checker;
            //printf("red - %s\ncheck - %s \nspis - %s\n ",red->word, checker->word,spisok->word);
        }
        if(strcmp(spisok->word,word) !=0 ){
            
            checker = spisok;
            spisok=spisok->next;
        }
       
    }
    return counter;
}

void memory_cleaner(spis* spisok) {
    while (spisok != NULL) {
        spis* next = spisok->next;
        if (spisok->word != NULL) {
            free(spisok->word);
        }
        free(spisok);    
        spisok = next;
    }
}
void print(spis* spisok) {
    while (spisok != NULL) {
        printf("$ %s\n", spisok->word);
        spisok = spisok->next;
    }
}
int main()
{
    char* last_input;
    void* pointer;
    spis* checker;
    printf("Ввод слов : (end -конец ввода)\n");
    char* input = calloc(1024, sizeof(char));
    memset(input, 0, 1024);
    while (strcmp(input, "end") != 0) {
        printf("Слово : ");
        fgets(input, 1024, stdin);
        input[strlen(input)-1] = '\0'; // обрезаем конечный '\n'
        if(strcmp(input,"end") == 0)
        {
            break;
        }
        else if (start == NULL) {
            start = malloc(sizeof(spis));
            pointer = start;
            start->word = (char*) calloc(strlen(input) + 1, sizeof(char));
            strcpy(start->word, input);
            start->next = NULL;
            printf("Добавлено: %s\n", input);
        }
        else {
            ADD(start, input);
            printf("Добавлено: %s\n", input);
        }

    }
    spis* copy;
    copy=start;
    while(copy->next!=NULL){
        copy=copy->next;
    }
    last_input=copy->word;
    int a = preobr(start,last_input);
    if(a>0){
        start=start->next;
    }
    printf("\n\n\n\nСПИСОК:\n\n\n\n");
    print(start);
    memory_cleaner(start);
    free(input);
    return 0;
}