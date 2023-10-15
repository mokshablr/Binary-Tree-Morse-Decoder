#include<stdio.h>
#include<string.h>

//Array of characters in order from top to bottom and left to right.
//Keeping spaces in between as it is in the morse tree.
char s[29] = "ETIANMSURWDKGOHVF L PJBXCYZQ";

int main(){

    char input[100];
    fgets(input, sizeof(input), stdin);
    int parent=0;

    for(int i=0; i<= strlen(input); i++){

        //if char is a '.' we go left. Formula for left child is "(2*parent)+1";
        if(input[i] == '.'){
            parent = (2*parent) + 1;
        }

        //if char is a '-' we go right. Formula for right child is "(2*parent)+2";
        else if(input[i] == '-'){
            parent = (2*parent) + 2;

        }

        //if char is anything else(in this case only a space), print the character at the position in the array.
        else{
            printf("%c", s[parent-1]);
            parent =0;
        }
    }
    printf("\n");
}