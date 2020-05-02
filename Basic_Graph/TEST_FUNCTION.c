#include"ALL.h"

#ifdef TEST_SET
void Print_Route_info_FIXED(int(*ap)[END])
{
	int row, col, i;
	int size = 4;

	printf("  ");
	for (i = 0; i < size; i++)
		printf("%c ", 'A' + i);
	puts("");
	for (row = 0; row < size; row++)
	{
		printf("%c ", 'A' + row);
		for (col = 0; col < size; col++)
		{
			printf("%d ", ap[row][col]);
		}
		puts("");
	}

}

Graph** Make_Node_FIXED()
{
	int i;
	int size = END;
	Graph** node;

	node = (Graph**)malloc(size * sizeof(Graph*));
	for (i = 0; i < size; i++)
	{
		node[i] = (Graph*)malloc(sizeof(Graph));
		node[i]->ch = 'A' + i;
		node[i]->link = (Graph**)malloc(size * sizeof(Graph*));//size-1
		memset(node[i]->link, 0, size * sizeof(Graph*));
	}

	return node;
}

void Input_Route_FIXED(Graph** node, int(*ap)[END])
{
	int row, col;
	int size = END;
	//0:A, 1:B, ....
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (ap[row][col] == 1)
				node[row]->link[col] = node[col];
		}
	}
}
#endif