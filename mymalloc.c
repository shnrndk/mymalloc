#include <stdio.h>
#define MAX 25       //Implementing the char array with 25000 elements/bytes;
char arr[MAX];


char* mymalloc(unsigned int size){
    if(size>MAX-2){             //Checking whether the requested size is larger than the array
        printf("\nError! Requested size is larger than the size of the byte array\n");     //Prints this msg if the required size is larger than the array
        return NULL;
    }else{
        char*p=arr;
        if(*p=='\0'){                //Checking whether the array is completely free
            *p='z';                 //Iniializing the bytearray, by putting 'z' into the array as the first element
        }
        char*w=arr;               //It pointing to the last address of the block and hold it while *t is traversing through the array
        for(int i=0;i<MAX-1;i++){
           if(*w=='z' && *(w+1)!='a'){      //It checks whether there is an free block
                int count=0;               //It will count the the blocks which will pass until the start address of the next allocated block
                char*t;         //It is used to traverse to find a start of a free block which is 'a'.
                t=w;
                for(int j=i;j<MAX-1;j++){
                    *t++;           //traversing through the free block;
                    count++;
                    if(*t=='a' && count<size+2){      //If there is an allocated block while traversing this will ignore that block
                        break;
                    }
                    else if(count>size+2){       //Checking whether the free space has sufficient space to fit the size
                        *(w+1)='a';                 //Allocating the block by putting 'a' to the front of the block;
                        *(t-1)='z';                 //Allocating the block by putting 'z' to the back of the block, The allocated block resides in the 'a' and 'z' marked elements;
                        return (w+2);              //Returning the first address of the recently allocated block
                    }
                }
            }
            *w++;       //This will increment by 1 after 1 free block search
        }               //After the t finds an free block and then allocate the block or not, then the w will increase
        printf("\nError! Due to insuffisient Space\n");        //If there is not enough space for a new block to allocate then this msg will be printed
        }
    }

void myfree(char * target){             //This function will free the target blocks
    if(target==NULL || *(target-1)!='a'){       //Checking whether the given address is valid
        printf("\nError! Requested Address is Not Found In the Byte Array\n");
    }else{
        char* ptr=target;                   //ptr will pointing to the start address of the target block
        *(ptr-1)='\0';                      //ptr-1 will be marked 'a' to '0'
        while(*ptr!='z'){                   //ptr traversing throughout the block until 'z' meets
            *ptr++;
        }
        *ptr='\0';                          //ptr will be marked 'z' to '0', removing the marks 'a' and the 'z' signifies the freeing of the block
        printf("\nAddress %p has been freed!\n",target);   //printing the freed block
    }

}


int main(){
    printf("\n%p\n",mymalloc(5));
    printf("\n%p\n",mymalloc(2));
    char*c=mymalloc(1);
    myfree(c);
    printf("\n%p\n",mymalloc(5));
    printf("\n%p\n",mymalloc(2));
}
