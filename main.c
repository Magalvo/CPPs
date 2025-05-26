#include <stdio.h>
#include <math.h>

int main(void) {
    /* Array contendo as palavras fornecidas */
    const char *words[] = {
        "a","bbb","dd","f","ggg","ii","k","lll","nn","p","qqq","ss","u","vvv","zz",
        "aa","c","ddd","ff","h","iii","kk","m","nnn","pp","r","sss","uu","x","zzz",
        "aaa","cc","e","fff","hh","j","kkk","mm","o","ppp","rr","t","uuu","xx",
        "b","ccc","ee","g","hhh","jj","l","mmm","oo","q","rrr","tt","v","xxx",
        "bb","d","eee","gg","i","jjj","ll","n","ooo","qq","s","ttt","vv","z"
    };

    size_t count = sizeof(words) / sizeof(words[0]);

    /* Exibe todas as palavras */
    for (size_t i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }
    double i = 2;
    size_t total = 30;
    double split = sizeof(words) / sizeof(words[0]);
    while (split % i == 0)
       split /= i;
    printf("Bef Half %d\n", split);
    split = ceil(split/2);
    printf("Half %d\n", split);
    return 0;
}
