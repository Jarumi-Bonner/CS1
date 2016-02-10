#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

const int DX_SIZE = 8;
const int DX[] = {-1,-1,-1,0,0,1,1,1};
const int DY[] = {-1,0,1,-1,1,-1,0,1};
FILE * fin;
int num, row, column;

char** inputDictionary();
char gridSearch();
int binsearch(int low, int high, char* searchval);
char** grid=NULL, **dic = NULL;


int main(){
  dic = inputDictionary();
  int testCase, i, j, k, l, m, n, o, p;
  char key;

  scanf("%d\n", &testCase);
//  printf("Test\n");
  for(i=0; i<testCase; i++){
    scanf("%d %d\n", &row, &column);
    char line[column];
  //  printf("Test1\n");
    grid = malloc(sizeof(char*)*row);
    for(j=0; j<row; j++){
      grid[j] = malloc(sizeof(char)*column);
    }

    for(k=0; k<row; k++){
      scanf("%s", line);
      for(l=0; l<column; l++){
        grid[k][l]= line[l];
    //    printf("Test2\n");
      }

    }
    printf("Words Found Gird #%d:\n", i+1);
    for(m=0; m < row; m++) {
        for(n=0; n < column; n++) {
            printf(" %c", grid[m][n]);
        }
        printf("\n");
    }
        gridSearch();
}

  //After everything is done free the memory
  //printf("test3\n");

  for(i=0; i<row; i++){ //free dic
    free(grid[i]);
  }
  free(grid);

  for(i=0; i<num; i++){ //free dic
    free(dic[i]);
  }
  free(dic);
//  printf("test3-2\n");
return 0;
}



char** inputDictionary(){
  int i;
  fin = fopen("dictionary.txt", "r");

  if((fin = fopen("dictionary.txt", "r")) == NULL){
  //  printf("test2\n");
    printf("File could not be opened!\n");
  }else{
    fscanf(fin, "%d", &num);
    dic =  malloc(sizeof(char*)*num);
    for(i=0; i<num; i++){
      dic[i] =(char*) malloc(sizeof(char)*20);
      fscanf(fin, "%s\0", dic[i]);
    }
  }
//  printf("test4\n");
  return dic;
}



char gridSearch(){
  const int MAX_WORD_SIZE =20;
  const int MIN_WORD_SIZE =3;
  char str[20]= {0};
  int i, j, k, nextX, nextY, length =1;
//  printf("test\n");

  for(i=0; i<row; i++){
    for(j=0; j<column; j++){
      str[0]= grid[i][j];
    //  printf("grid value: %c\n",grid[i][j]);
      //printf("Postion i:%d, j:%d\n", i, j);
    //  printf("Test5\n");
      for(k=0; k< DX_SIZE; k++){
        //int nextX, nextY;
        length=1;
        while(length < MAX_WORD_SIZE){
          nextX = i + DX[k]*length;
          nextY = j + DY[k]*length;
      //    printf("X:%d, Y:%d\n", nextX, nextY );
          if(nextX < 0 || nextX >= row) break;
          if(nextY < 0 || nextY >= column) break;
        //  printf("Test6\n");
          str[length] = grid[nextX][nextY];

      //    printf("The string created: %s\n", str);

          if (length>=MIN_WORD_SIZE) {  //Search for str in dic
            str[length+1]= '\0'; //null termination
            printf("%s\n", str);
          //  ;

            if(binsearch(0, num, str) == 1){
            //  printf("test\n");
              printf("Found!!! %s\n", str);
            }
          //  printf("test2\n");
          }
            length++;
        }


          memset(&str[1], '\0', 20);
    //      printf("Test7\n");
        }
    }
}
//printf("Test!!!\n");
}


int binsearch(int low, int high, char* searchval){
  high = high -1;
  int mid =(high+low)/2, cmp=0;
  /*
printf("--------------------------\n");
  printf("searchval: %s\n", searchval);
//  printf("high: %d\n", high);
  //printf("mid: %d\n", mid);
//  printf("low: %d\n", low);

printf("\n");
  printf("dic low: %s\n", dic[low]);
  printf("dic mid: %s\n", dic[mid]);
  printf("dic high: %s\n", dic[high]);
printf("\n");
  printf("dic word: %s\n", dic[mid]);
  //*/
  cmp = strcmp(dic[mid], searchval);
  //printf("cmp: %d\n", cmp);
//  printf("help1\n");
  if(low>= high){
    return -1;
  }
  if (cmp<0) {
  //  printf("help2\n");
    return binsearch(mid+1, high, searchval);
  } else if (cmp>0) {
    //  printf("help3\n");
      return binsearch(low, mid-1, searchval);
  } else if (cmp==0) {
  //  printf("%s\n", dic[mid]);
    return 1;
  }
}

/*
int binsearch(int low, int size, char *searchval){
    int mid;
    int high = size - 1;
​
    while(low <= high){
        mid = (low + high)/2;
        if (strcmp(dic[mid], searchval) == 0){
            printf("%s found at location %d.\n", searchval, mid+1);
            return 1;
        } else if (strcmp(dic[mid], searchval) > 0){
            high    = mid - 1;
            return -1;
        } else if (strcmp(dic[mid], searchval) < 0){
            low = mid + 1;
            return -2;
        }
    }
}
*/
