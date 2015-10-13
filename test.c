#include <stdio.h>
#include <stdint.h>

#define ARRAY_SIZE 10

typedef enum
{
   DATA_INDEX=1,
   DATA_NUMBER,
   DATA_ATTRIBUTES = 5,
   DATA_FLAGS,
   DATA_NUM_OF_ELEMENTS,
}AttributeData_t;

int ObjectData[ARRAY_SIZE];

main()
{
   AttributeData_t currentObject;
   uint8_t externalData;

   for (currentObject=0; currentObject<=DATA_NUM_OF_ELEMENTS;)
   {
      switch (currentObject)
      {
         case DATA_INDEX:
            ObjectData[currentObject] = 0xAA;
         case DATA_NUMBER:
            ObjectData[currentObject] = 0xBB;
         case DATA_FLAGS:
            ObjectData[currentObject] = 0xCC;
         case DATA_NUM_OF_ELEMENTS:
            ObjectData[currentObject] = 0xDD;
            break;
         default:
           printf("\n Shouldn't get here!!! CurrentObject=%x \n", currentObject);
           break;
      }
      currentObject++;
   }

   if (currentObject = DATA_NUM_OF_ELEMENTS)
   {
      externalData = (int) 0xDEAD;
   }
   else
   {
      externalData = (int) 0x1234;
   }

   ObjectData[5] = externalData;

   printf("\n Current Object Data 0 is, %x \n", ObjectData[0]);
   printf("\n Current Object Data 1 is, %x \n", ObjectData[1]);
   printf("\n Current Object Data 2 is, %x \n", ObjectData[2]);
   printf("\n Current Object Data 3 is, %x \n", ObjectData[3]);
   printf("\n Current Object Data 4 is, %x \n", ObjectData[4]);
   printf("\n Current Object Data 5 is, %x \n", ObjectData[5]);
   printf("\n Attributes Fit in %d Bytes", sizeof(currentObject));

   printf("\n ---=== Self Test Results ===---");

   for (currentObject=0; currentObject<=ARRAY_SIZE; currentObject++)
   {
      printf("\n ObjectData[%d]: %x", currentObject, ObjectData[currentObject]);
   }
   printf("\n externalData = 0x%x \n", externalData);

}





