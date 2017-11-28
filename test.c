#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dyn_array.h"




void test_initilization(DynArray *ptr)
{

	assert(DynArray_init(ptr));
	assert(ptr->size == 0);
	assert(ptr->capicity != 0);
	assert(ptr->data[0] == 0);
}

void test_pushBack_and_getElement(void)
{
	DynArray *ptr =  malloc(sizeof(DynArray));
	test_initilization(ptr);
	assert(DynArray_pushBack(ptr, 1));
	assert(DynArray_pushBack(ptr, 2));
	assert(ptr->size == 2);
	assert(DynArray_getElement(ptr, 0) == 1);
	assert(DynArray_getElement(ptr,1) == 2);
}

void test_getSize(void)
{
	DynArray *ptr = malloc(sizeof(DynArray));
	assert(ptr);
	DynArray_init(ptr);
	assert(DynArray_getSize(ptr) == 0);
	DynArray_pushBack(ptr,1);
	DynArray_pushBack(ptr, 2);
	DynArray_pushBack(ptr,3);
	assert(DynArray_getSize(ptr) == 3);
}
int main(void)
{
	DynArray *ptr = malloc(sizeof(DynArray));
	DynArray_init(ptr);
	test_initilization(ptr);
	test_pushBack_and_getElement();
	test_getSize();
	return 0;
}
