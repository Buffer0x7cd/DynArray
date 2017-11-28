#ifndef TYPE_H
#define TYPE int
#define TYPE_SIZE sizeof(int)
#endif

#ifndef STDDEF_H
#include <stddef.h>
#endif

#ifndef STDBOOL_H
#include <stdbool.h>
#endif

#ifndef INIT_BUFFER_SIZE
#define INIT_BUFFER_SIZE 2
#endif


typedef struct DynArray
{
	TYPE *data;
	size_t size;
	size_t capicity;
}DynArray;


bool DynArray_init(DynArray *self);
TYPE DynArray_getElement(const DynArray *self, size_t pos);
bool DynArray_setElement(DynArray *self, size_t pos, TYPE value);
size_t DynArray_getSize(const DynArray *self);
bool DynArray_pushBack(DynArray *self, TYPE value);
bool DynArray_removeElement(DynArray *self, size_t pos);
