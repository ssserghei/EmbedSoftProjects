/*swapping two arrays
 * */

#include <stdio.h>
#include <stdlib.h>

void wait_for_user_input(void);
void display_array(int32_t *pArray1, uint32_t nItem);

/***************************MAIN*******************/
int main(void)
{
	printf("Begin\n");											fflush(stdout);

	int32_t nItem1, nItem2;
	printf("Array swapping program\n");							fflush(stdout);
	printf("Enter no of elements of Array-1 and Array-2:");		fflush(stdout);
	scanf("%ld %ld", &nItem1, &nItem2);							fflush(stdout);

	if ((nItem1<0)||(nItem2<0))
	{
		printf("Number of elements cannot be negative\n");		fflush(stdout);
		wait_for_user_input();
		return 0;
	}

	int32_t array1[nItem1];
	int32_t array2[nItem2];

	for(uint32_t i=0; i<nItem1; i++)
	{
		printf("Enter %d element of array1:\n", i);		fflush(stdout);
		scanf("%d",array1[i]);							fflush(stdout);
	}

	for(uint32_t i=0; i<nItem2; i++)
	{
		printf("Enter %d element of array1:\n", i);		fflush(stdout);
		scanf("%dd",array2[i]);							fflush(stdout);
	}

	printf("Contents of array before swap\n");			fflush(stdout);

	display_array(array1,nItem1);

	printf("\n");										fflush(stdout);

	display_array(array2,nItem2);


	wait_for_user_input();

//

return 0;
}//END MAIN

void display_array(int32_t *pArray1, uint32_t nItem)
{
	for(uint32_t i=0; i<nItem; i++)
	{
		printf("%d ", pArray1[i]);						fflush(stdout);
	}
}

void wait_for_user_input(void)
{

}
