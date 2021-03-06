#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

const int DX_SIZE = 8;
const int DX[] = {-1,-1,-1,0,0,1,1,1};
const int DY[] = {-1,0,1,-1,1,-1,0,1};
FILE * fin;
int num, row, column;
int size;

char** inputDictionary();
char gridSearch();
int binsearch(int low, int high, char* searchval);
char** grid=NULL, **dic = NULL;


int main(){
  dic = inputDictionary();
  int testCase, i, j, k, l, m, n, o, p;
  char key;

  scanf("%d\n", &testCase);
  for(i=0; i<testCase; i++){
    scanf("%d %d\n", &row, &column);
    char line[column];
    grid = malloc(sizeof(char*)*row);
    for(j=0; j<row; j++){
      grid[j] = malloc(sizeof(char)*column);
    }

    for(k=0; k<row; k++){
      scanf("%s", line);
      for(l=0; l<column; l++){
        grid[k][l]= line[l];
      }

    }
    printf("Words Found Gird #%d:\n", i+1);
    gridSearch();
}
  //After everything is done free the memory

  for(i=0; i<row; i++){ //free dic
    free(grid[i]);
  }
  free(grid);

  for(i=0; i<num; i++){ //free dic
    free(dic[i]);
  }
  free(dic);
return 0;
}



char** inputDictionary(){
  int i;
  fin = fopen("dictionary.txt", "r");

  if((fin = fopen("dictionary.txt", "r")) == NULL){
    printf("File could not be opened!\n");
  }else{
    fscanf(fin, "%d", &num);
    dic =  malloc(sizeof(char*)*num);
    for(i=0; i<num; i++){
      dic[i] =(char*) malloc(sizeof(char)*20);
      fscanf(fin, "%s\0", dic[i]);
    }
  }
  return dic;
}


//Goes through every direction in Gird
char gridSearch(){
  const int MAX_WORD_SIZE =20;
  const int MIN_WORD_SIZE =3;
  char str[20]= {0};
  int i, j, k, nextX, nextY, length =1;
  size = num-2;

  for(i=0; i<row; i++){
    for(j=0; j<column; j++){
      str[0]= grid[i][j]; //always start the new string at the grid point

      for(k=0; k< DX_SIZE; k++){

        length=1;
        while(length < MAX_WORD_SIZE){
          nextX = i + DX[k]*length;
          nextY = j + DY[k]*length;

          if(nextX < 0 || nextX >= row) break;
          if(nextY < 0 || nextY >= column) break;

          str[length] = grid[nextX][nextY];

          if (length>=MIN_WORD_SIZE){  //Search for str in dic
            str[length+1]= '\0'; //null termination

            if(binsearch(0, size, str) == 1){
              printf("%s\n", str);
            }
          }
            length++;
        }
          memset(&str[1], '\0', 20); //resets the memory of the string
        }
    }
  }
  return 0;
}


int binsearch(int low, int high, char* searchval){
  int mid =(high+low)/2, cmp=0, n=0;

  cmp = strcmp(dic[mid], searchval);

  if( low>high){
    return -1;
  }
  if (cmp<0) {//If you are above the word
    return binsearch(mid+1, high, searchval);
  } else if (cmp>0) {//If you are below the word
      return binsearch(low, mid-1, searchval);
  } else if (cmp==0) {
    return 1; //If you found the word
  }
  return 0;
}
