#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 256
#define WORD 30




int similar (char *s, char *t, int n) {
    int len1, len2;
    len1 = strlen(s);
    len2 = strlen(t);
    if (len1 < len2 || len1 - n < len2) {
        return 0;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    while (cnt1<len1) {
        if (*(s + cnt1) == *(t + cnt2)) {
            cnt1++;
            cnt2++;
        } else if (*(s + cnt1) != *(t + cnt2)) {
            cnt1++;
        }
    }
    if (cnt2 == len2 && len1 - n == cnt2) {
        return 1;
    } else {
        return 0;
    }
}

int is_substring(const char* a, const char* b) {
    // Check if b is a substring of a
    if (strstr(a, b) != NULL) {
        // b is a substring of a
        return 1;
    } else {
        // b is not a substring of a
        return 0;
    }
}
int getlinee(char s[]){
    bzero(s,LINE);
    for (int i = 0; i < LINE; ++i) {
        char c=getc(stdin);
        if(c=='\0'||c==EOF){
            return 0;
        }
        if(c=='\n'){
            break;
        }
        if(c!='\r'){
            s[i]=c;
        }

    }
    return 1;


}
int getword(char w[]){

    bzero(w,WORD);
    for(int i=0;i<WORD;i++){
        char c= getc(stdin);
        if(c=='\0'|| c==EOF){
            return 0;
        }
        if(c==' '||c=='\t'||c=='\n'){
            break;
        }
        w[i]=c;
    }
    return 1;
}
void print_lines(char * str){
    char line[LINE]={'\0'};
    while(getlinee(line)!=0){
        if(is_substring(line,str)==1){
            printf("%s\n",line);
        }

    }
}
void print_similar_words(char * str){
    char word[WORD]={'\0'};
    while(getword(word)!=0){
        if(similar(word,str,1)==1||similar(word,str,0)==1){
            printf("%s\n",word);
        }
    }
}

int main(){
    char target[WORD]={'\0'};
    getword(target);
    char ab = getc(stdin);
    if(ab=='a'){
        print_lines(target);
    }
    if(ab=='b'){
        print_similar_words(target);
    }
    return 0;
}







