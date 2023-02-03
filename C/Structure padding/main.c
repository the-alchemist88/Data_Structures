#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct DataSet
{
    char data1;
    int data2;
    char data3;
    short data4;
};
int main(){

    uint8_t *ptr; // identifying a pointer,pointing to uint8_t type

    struct DataSet *data; // identifying "data" variable as struct type DataSet pointer
    data=calloc(1,sizeof(struct DataSet));// cleaning up a chunk of memory
    ptr=(uint8_t*)data;//initializing data ptr, from address which data pointer points to

data->data1=0x11;// assigning some variables to DataSet struct elements
data->data2=0xAABBCCDD;
data->data3=0x55;
data->data4=0xAABB;


uint8_t totalSize=sizeof(struct DataSet);//identifying totalSize variable to see the size of DataSet

printf("Memory address                  Content\n");
printf("=======================================\n");

for(uint8_t i=0;i<totalSize;i++){ // printing out the consecutive values of DataSet byte by byte as uint8_t type by incrementing ptr
    printf("%p=                         %X\n",ptr,*ptr);
    ptr++;
}
printf("\n\nTotal memory consumed by struct variable=%d\n",sizeof(struct DataSet));// Total size of DataSet

/* In the program output lines with "00" content are sign of memory loss
* because processor allocates memory the according to next variable boundary
*for example as data1 is char type and data2 is int, so processor allocates 3
* more extra memory(byte) since sizeof(int)-sizeof(char)=3
*/

return 0;
}

