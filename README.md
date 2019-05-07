# mymalloc
Allocating and Deallocating of space without using malloc/free function in C

This is a home assingment of our university. This is a home assingment of our university. We need to write a program to write a program to allocate required memory from the RAM without using malloc() in C language. In this program

#define MAX 25000 

tells us the MAX memory that we can allocate. U can change it from the by changing the MAX value.
When we call the mymalloc(size) it will allocate the memory which will given as a size parameter. It will return the starting address of that memory block as char* data type.

To deallocate we need to call myfree() and give the starting address of the required memory block to deleted as the parameter.


