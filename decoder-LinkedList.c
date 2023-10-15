#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char data;
    struct Node* right;
    struct Node* left;
}NODE;

NODE * createNode(){

    //allocating memory for the new node.
    NODE * new = (NODE *)malloc(sizeof(NODE));

    //links to NULL since this node is independent of other nodes during creation.
    new -> right = NULL;
    new -> left = NULL;

    //return the address to the newly created link.
    return new;
}

NODE* root;


// Morse Code Binary Tree Creation
void insertNode(char s[]){
    
    //temporary variable so that root does not change.
    NODE * temp = root;

    for(int j=0; j<strlen(s); j++){

        // if the input is '.', we go left in the binary tree.
        if(s[j] == '.'){
            if(temp->left == NULL){
                temp->left = createNode();
                temp = temp->left;
            }
            else{
                temp = temp->left;
            }
        }

        // if the input is '-', we go right in the binary tree.
        else if(s[j] == '-'){
            if(temp->right == NULL){
                temp->right = createNode();
                temp = temp->right;
            }
            else{
                temp = temp->right;
            }
        }

        // if the input is anything else(will only be an Alphabet), store the Alphabet in that node.
        else{
            temp->data = s[j];
        }
    }
}

// Morse Code Decoder
void decode(char s[]){

    NODE * temp =root;
    for(int j=0; j<strlen(s); j++){
        if(s[j] == '.'){
            temp = temp->left;
        }
        else if(s[j] == '-'){
            temp = temp->right;
        }
        else{
            printf("%c", temp->data);

            //reset temp back to the root before checking for the next alphabet
            temp = root;
        }
    }
    printf("\n");
}

int main(){
    root =  createNode();

    char s[][5] = {
        {'.', '-', 'A'}, // A
        {'-', '.', '.', '.', 'B'}, // B
        {'-', '.', '-', '.', 'C'}, // C
        {'-', '.', '.', 'D'}, // D
        {'.', 'E'}, // E
        {'.', '.', '-', '.', 'F'}, // F
        {'-', '-', '.', 'G'}, // G
        {'.', '.', '.', '.', 'H'}, // H
        {'.', '.', 'I'}, // I
        {'.', '-', '-', '-', 'J'}, // J
        {'-', '.', '-', 'K'}, // K
        {'.', '-', '.', '.', 'L'}, // L
        {'-', '-', 'M'}, // M
        {'-', '.', 'N'}, // N
        {'-', '-', '-', 'O'}, // O
        {'.', '-', '-', '.', 'P'}, // P
        {'-', '-', '.', '-', 'Q'}, // Q
        {'.', '-', '.', 'R'}, // R
        {'.', '.', '.', 'S'}, // S
        {'-', 'T'}, // T
        {'.', '.', '-', 'U'}, // U
        {'.', '.', '.', '-', 'V'}, // V
        {'.', '-', '-', 'W'}, // W
        {'-', '.', '.', '-', 'X'}, // X
        {'-', '.', '-', '-', 'Y'}, // Y
        {'-', '-', '.', '.', 'Z'}, // Z
    };


    for(int i=0; i<26; i++){
        insertNode(s[i]);
    }

    char input[100];
    fgets(input, sizeof(input), stdin);

    decode(input);

}