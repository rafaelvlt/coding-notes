#include <stdio.h>
#include <stdlib.h>

char** split(const char *str, char delimitador, int* num_palavras){

  size_t og_len = 0;
  while(str[og_len] != '\0')++og_len;
  if (str == NULL || og_len == 0){
    *num_palavras = 0;
    return NULL;
  } 
  
  char** m = NULL;
  int cnt = 0;
  m = malloc(sizeof(char*));

  int f = 0;
  for (size_t i = 0; i <= og_len; i++){
    if (str[i] == delimitador || i == og_len){
      m[cnt] = malloc(i - f + 1);
      if (m[cnt] == NULL){
        for (int z = cnt-1; z >= 0; z--){
          free(m[z]);
        }
        free(m);
        exit(1);
      }
      else{
        for (int j = f ; j < i; j++){
          m[cnt][j-f] = str[j];
          if (j == i-1) m[cnt][i-f] = '\0';
        }
        
        f = i + 1;
        cnt++;

        char** ptemp = NULL;
        ptemp = realloc(m, (sizeof(char*) * (cnt + 1)));

        if (ptemp == NULL){
          for (int z = cnt-1; z >= 0; z--){
            free(m[z]);
          }
          free(m);
          exit(1);
        }
        else{
          m = ptemp;
        }
      }
    } 
    ++i;
  }

  *num_palavras = cnt;
  return m;
}

int main(){



  return 0;
}
