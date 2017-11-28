#include "dyn_array.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>






/*Allocate an pool of memory to store data upto N elements
 * 
 * @param capicity
 * 	capacity for the data pool 
 *
 * @returns 
 * 	Pointer to a memory area of type TYPE with given number
 *  */


TYPE * __DynArray_createDataPool(size_t capicity)
{
	if (capicity != 0)
	{
		size_t bytesize =  TYPE_SIZE * capicity;
		TYPE *tmp = malloc(bytesize);
		if (!tmp)
			return NULL;
		tmp = memset(tmp, 0x00, bytesize);
		return tmp;
	}
	return NULL;
}

/*Initilize an DynArray
 * 
 * @param  self
 * 		A pointer to an DynArray struct
 *
 * @returns
 * 	true if initilization is successful or false if initlization is
 * 	unsuccessful (possible reason - out of memory or bad pointer)
 *
 * 	
 * */
bool DynArray_init(DynArray *self)
{
	if (self)
	{
		self->size = 0;
		self->data = __DynArray_createDataPool(INIT_BUFFER_SIZE);
		if (!self->data)
			return false;
		self->capicity = INIT_BUFFER_SIZE;
		return true;
	}
	return false;
}

/**
 *returns the element at a given index
 *
 * @param index
 * 		index of the element that need to be read
 *
 * @returns
 * 		value of the element at given index,
 * 		assert Fails if the it's called with an invalid index
 * 		and NDEBUG is not defined.
 *
 **/

TYPE DynArray_getElement(const DynArray *self, size_t index)
{
	assert(index < (self->size));
	return self->data[index];
}

/* double the capicity of an array
 *
 * */
bool __DynArray_expendArray(DynArray *self)
{
	if (self)
	{
		TYPE *tmp = __DynArray_createDataPool(2*(self->capicity));
		if (!tmp)
			return false;
		size_t byteToCopy = TYPE_SIZE* (self->size);
		tmp = memcpy(self->data , tmp, byteToCopy);
		free(self->data);
		self->data =  tmp;
		return true;

	}
	return false;
}

/* push an element to last of the array
 *
 * @param self
 * 		pointer to the DynArray struct
 *
 * @param value
 * 		Value that need to be pushed
 *
 * @returns 
 * 		true if push is successfule otherwise false
 * */

bool DynArray_pushBack(DynArray *self, TYPE value)
{
	if ((self->size) == (self->capicity))
	{
		bool res =  __DynArray_expendArray(self);
		if(!res)
			return false;
	}
	self->data[self->size] = value;
	self->size += 1;
	return true;
}


size_t DynArray_getSize(const DynArray *self)
{
	return self->size;
}
