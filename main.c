#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char **input(int H){
    FILE * file = fopen("letters.txt", "r");
    char** letters = malloc(H*sizeof(char*));
    for(int i=0; i<H; i++){
        char ROW[1025];
        fscanf(file, "%[^\n]", ROW); fgetc(file);//fgetc to backline
        letters[i] = malloc((strlen(ROW)+1)*sizeof(char));
        strcpy(letters[i], ROW);
    }
    fclose(file);
    return letters;
}

int main(){
    int L = 4, H = 5; //length and height of letters
    printf("Quelle chaîne de caractères afficher ?\n");
    char T[257];
    scanf("%[^\n]", T);
    char** letters = input(H);
    char colors[5][8] = {"\x1b[31m", "\x1b[32m", "\x1b[33m", "\x1b[34m", "\x1b[35m"};
    char colorReset[7] = "\x1b[0m";

    for (int i = 0; i < H; i++) {
        for(int j=0; j<strlen(T); j++){
            if('a'<=T[j]&&T[j]<='z'){
                int begin = L*(T[j]-97);
                for(int k=begin; k<(begin+L); k++){
                    printf("%s", colors[j%5]);
                    printf("%c", letters[i][k]);
                    printf("%s", colorReset);
                }
            }else if('A'<=T[j]&&T[j]<='Z'){
                int begin = L*(T[j]-65);
                for(int k=begin; k<(begin+L); k++){
                    printf("%s", colors[j%5]);
                    printf("%c", letters[i][k]);
                    printf("%s", colorReset);
                }
            } else {
                int begin = L*26;
                for(int k=begin; k<(begin+L); k++){
                    printf("%s", colors[j%5]);
                    printf("%c", letters[i][k]);
                    printf("%s", colorReset);
                }
            }
        }
        printf("\n");
    }
    return 0;
}