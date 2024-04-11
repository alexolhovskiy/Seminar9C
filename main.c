////////////////////////////////////
///                              ///
///        ALEX OLHOVSKIY        ///
///                              ///
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void makeTxtFile(char*name,int count,int maxWordSize,int minWordSize,int isNum){
    int i,j,n;
    char c=0;
    FILE*fd=fopen(name,"w");
    if(fd!=NULL){
        printf("Opend\n");
        for(i=0;i<count;i++){
            if(isNum==1){
                if(i%5==0){
                    n=1+rand()%minWordSize;
                    for(j=0;j<n;j++){
                        c=48+rand()%10;
                        fprintf(fd,"%c",c);
                    }
                }else{
                    n=minWordSize+rand()%(maxWordSize-minWordSize);

                    for(j=0;j<n;j++){
                        if(j==0){
                            c=65+rand()%26;
                        }else{
                            c=97+rand()%26;
                        }
                        fprintf(fd,"%c",c);
                    }
                }
            }else{
                n=minWordSize+rand()%(maxWordSize-minWordSize);
                for(j=0;j<n;j++){
                    if(j==0){
                        c=65+rand()%26;
                    }else{
                        c=97+rand()%26;
                    }

                    fprintf(fd,"%c",c);
                }
            }

            fprintf(fd," ");
        }
        fclose(fd);
    }else{
        printf("Cannot open!\n");
    }
}

void printFile(char*name){
    char buffer[256]={0};
    FILE*fd=fopen(name,"r");
    if(fd!=NULL){
        printf("Opend\n");
        while(fscanf(fd,"%s",buffer)==1){
            printf("%s ",buffer);
        }
        fclose(fd);
    }else{
        printf("Cannot open!\n");
    }
}


void putAsFragment(char*sourceFile,char*distFile){
    FILE* fdSource = fopen(sourceFile, "r");
    FILE* fdDist = fopen(distFile, "a+");
    char border[]="\n==============================================\n";
    char buffer[256]={0};
    if(fdSource!=NULL&&fdDist!=NULL){
        printf("Open both");
        fputs(border,fdDist);
        while(fgets(buffer, 256, fdSource) != NULL){
            printf("%s",buffer);
            fputs(buffer,fdDist);
        }
        fputs(border,fdDist);
        fclose(fdSource);
        fclose(fdDist);
    }else{
        printf("Cannot open\n");
    }
}

//void getSingleRepetitions(char*str) {
//    FILE* fd = fopen(str, "a+");
//    char str1[100] = { 0 };
//    char str2[100] = { 0 };
//    char buffer[256]={0};
//    char largerStr[100] = { 0 };
//    char smallerStr[100] = { 0 };
//    if (fd != NULL) {
//        fscanf(fd,"%s %s", str1,str2);
//        fseek(fd,0,SEEK_END);
//        fprintf(fd, "\n");
//        if(strlen(str1)>strlen(str2)){
//            strcpy(largerStr,str1);
//            strcpy(smallerStr,str2);
//        }else{
//            strcpy(largerStr,str2);
//            strcpy(smallerStr,str1);
//        }
//        printf("%s %s\n", largerStr, smallerStr);
//        int i,j,l,n,count,cnt=0;
//        for (i = 0; i < strlen(largerStr); i++) {
//            count = 0;
//            for (j = 0; j < strlen(largerStr); j++) {
//                if (largerStr[j] == largerStr[i]) {
//                    count++;
//                }
//            }
//            if(count==1){
//                count=0;
//                for (l = 0; l < strlen(smallerStr); l++) {
//                    if (smallerStr[l] == largerStr[i]) {
//                        count++;
//                    }
//                }
//                //printf("%d\n",count);
//                if (count == 1) {
//                    printf("%c\n",largerStr[i]);
//                    fseek(fd,0,SEEK_END);
//                    fprintf(fd, "%c ",largerStr[i]);
//                    cnt++;
//                }
//            }
//
//        }
//        if (cnt == 0) {
//            fprintf(fd, "0");
//        }
//        fclose(fd);
//    }
//    else {
//        printf("Cannot open\n");
//    }
//}






void letterSort(char*arr,int size){
    int i,j;
    char temp;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}


void getSingleRepetitions(char*str) {
    FILE* fd = fopen(str, "a+");
    char str1[100] = { 0 };
    char str2[100] = { 0 };
    char buffer[256]={0};
    int i,j,l=0,flag=0,size=0;
    if (fd != NULL) {
        fscanf(fd,"%s %s", str1,str2);
        strcat(str1,str2);
        printf("Start str %s\n",str1);
        size=strlen(str1);
        for(i=0;i<size;i++){
            flag=0;
            for(j=0;j<size;j++){
                if(str1[i]==str1[j]){
                    flag++;
                }
            }
            if(flag==1){
                buffer[l++]=str1[i];
            }
        }

        letterSort(buffer,strlen(buffer));
        printf("\n==================\n");
        printf("Final str %s\n",buffer);

        fseek(fd,0,SEEK_END);
        fprintf(fd,"\n==================\n");
        for(i=0;i<l;i++){
            fprintf(fd,"%c ",buffer[i]);
        }

        fclose(fd);
    }
    else {
        printf("Cannot open\n");
    }
}



void aToB(char*name){
    FILE*fd=fopen(name,"a+");
    char distFile[]="../task22.txt";
    FILE*fd2=fopen(distFile,"a+");
    char buffer[256]={0};
    long int pos=0;
    int i;
    if(fd!=NULL){
        printf("Open\n");

        while ((fgets(buffer, 256, fd)) != NULL)
        {
            for(i=0;i<256;i++){
                switch(buffer[i]){
                    case 'a':buffer[i]='b';break;
                    case 'A':buffer[i]='B';break;
                    case 'b':buffer[i]='a';break;
                    case 'B':buffer[i]='A';break;
                    default:;
                }
            }
            fputs(buffer,fd2);
        }

        fclose(fd);
        fclose(fd2);
    }else{
        printf("Cannot open\n");
    }
    putAsFragment(distFile,name);
}

void arrSort(int*arr,int size){
    int j,i,temp;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}

void getNums(char*name){
    FILE*fd=fopen(name,"a+");
    char buffer[256]={0};
    int i,j=0,flag,count=0;
    if(fd!=NULL){
        printf("Open\n");
        while(fscanf(fd,"%s",buffer)==1){
            printf("%s\n",buffer);
            flag=0;
            for(i=0;i<strlen(buffer);i++){
                if(buffer[i]>47&buffer[i]<58){
                    flag=1;
                }
            }
            if(flag==1){
                count++;
            }
        }

        int*arr=(int*)malloc(count);
        fseek(fd,0,SEEK_SET);
        printf("\n==============\n");
        while(fscanf(fd,"%s",buffer)==1){
            flag=0;
            for(i=0;i<strlen(buffer);i++){
                if(buffer[i]>47&buffer[i]<58){
                    flag=1;
                }
            }
            if(flag==1){
                printf("%s\n",buffer);
                arr[j++]=strtol(buffer,NULL,10);
            }
        }

        arrSort(arr,count);
        fprintf(fd,"\n=================\n");
        for(i=0;i<count;i++){
            printf("%d ",arr[i]);
            fprintf(fd,"%d ",arr[i]);
        }


        fclose(fd);
    }else{
        printf("Cannot open\n");
    }
}

void putAsFragment2(char*sourceFile,char*distFile){
    FILE* fdSource = fopen(sourceFile, "r");
    FILE* fdDist = fopen(distFile, "a+");
    char border[]="\n==============================================\n";
    char buffer[256]={0};
    if(fdSource!=NULL&&fdDist!=NULL){
        printf("Open both");
        fprintf(fdDist,"%s",border);
        while(fscanf(fdSource,"%s",buffer)==1){
            printf("%s",buffer);
            fprintf(fdDist,"%s",buffer);
        }
        fprintf(fdDist,"%s",border);
        fclose(fdSource);
        fclose(fdDist);
    }else{
        printf("Cannot open\n");
    }
}

void remover(char*name){
    FILE*fd=fopen(name,"a+");
    FILE*fd2=fopen("../text42.txt","a+");
    char buffer[256]={0};
    int i,j=0,l=0,flag,count=0,size=0;
    if(fd!=NULL){
        printf("Open\n");
        while(fscanf(fd,"%s",buffer)==1){
            printf("%s",buffer);
            size=strlen(buffer);
            for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                    if(buffer[i]==buffer[j]&&j!=i){
                        buffer[j]=' ';
                    }
                }
            }
            fprintf(fd2,"%s",buffer);
        }
        fclose(fd2);
        fclose(fd);
    }else{
        printf("Cannot open\n");
    }
    putAsFragment2("../text42.txt",name);
}


void longestWord(char*name){
    FILE*fd=fopen(name,"a+");
    char buffer[256]={0};
    char longestWord[256]={0};
    int i,j=0,l=0,flag,count=0,max=0;
    if(fd!=NULL){
        printf("Open\n");
        while(fscanf(fd,"%s",buffer)==1){
            printf("%s\n",buffer);
            if(strlen(buffer)>max){
                max=strlen(buffer);
                strcpy(longestWord,buffer);
            }
        }
        printf("\n=================\n");
        printf("%s\n",longestWord);
        fprintf(fd,"\n=================\n");
        fprintf(fd,"%s",longestWord);
        fclose(fd);

    }else{
        printf("Cannot open\n");
    }
}

void aEnded(char*name){
    FILE*fd=fopen(name,"a+");
    char buffer[256]={0};
    int count=0,size=0;
    if(fd!=NULL){
        printf("Open\n");
        while(fscanf(fd,"%s",buffer)==1){
            printf("%s\n",buffer);
            size=strlen(buffer);
            if(buffer[size-1]=='a'){
                count++;
            }
        }
        printf("\n=================\n");
        printf("%d\n",count);
        fprintf(fd,"\n=================\n");
        fprintf(fd,"%d",count);
        fclose(fd);

    }else{
        printf("Cannot open\n");
    }
}

int main()
{
    srand(time(NULL));
    printf("Hello world!\n");


    //1
//    makeTxtFile("../task1.txt",2,20,5,0);
//    getSingleRepetitions("../task1.txt");
//    printFile("../task1.txt");

    //2
//    makeTxtFile("../task2.txt",500,10,5,0);
//    aToB("../task2.txt");
//
//    //3
//    makeTxtFile("../task3.txt",100,8,3,1);
//    printFile("../task3.txt");
//    getNums("../task3.txt");
//
//    //4
//    makeTxtFile("../task4.txt",100,8,3,0);
//    remover("../task4.txt");
//
//    //5
//    makeTxtFile("../task5.txt",100,16,3,0);
//    longestWord("../task5.txt");
//
//    //6
    makeTxtFile("../task6.txt",50,7,3,0);
    aEnded("../task6.txt");

    return 0;
}
