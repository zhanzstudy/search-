#include <stdio.h>
#include <malloc.h>

typedef int DataType;

typedef struct
{
    DataType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
