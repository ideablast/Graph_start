#include"ALL.h"

#ifdef TEST_SET

int main()
{
	srand((unsigned int)time(NULL));
	Graph** node;
	int ap[4][4] = { {0,1,0,1},{1,0,0,1},{1,0,0,0},{1,1,1,0} };
	//int ap[4][4] = { {0,1,0,0},{0,0,1,0},{1,0,0,1},{0,1,0,0} };
	char ch_ary[5] = { 0 };
	int cnt_ary[4] = { 0 };
	int row, col;
	int size = 4;



	Print_Route_info_FIXED(ap);
	puts("");

	node = Make_Node_FIXED(ap);
	Input_Route_FIXED(node, ap);


	Visit_all_TEST(node[0], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[1], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[2], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[3], ch_ary, 0);


}

#endif
#ifdef ACTUAL
int main()
{
	srand((unsigned int)time(NULL));
	Graph** node;
	int** ap = Make_Route();
	int size = _msize(ap) / sizeof(int*);
	char* ch_ary = (char*)calloc(size + 1, sizeof(char));
	int i = 0;
	//char ch_ary[5] = { 0 };
	int row, col;
	//0:A, 1:B, ....

	Print_Route_info(ap);
	puts("");
	node = Make_Node(ap);
	Input_Route(node, ap);

	for (row = 0; row < size; row++)
	{
		printf("%c:", node[row]->ch);
		for (col = 0; col < size; col++)
		{
			if (node[row]->link[col])
				printf("%c ", node[row]->link[col]->ch);
		}
		puts("");
	}
	puts("");
	puts(""); 
	puts("");
	for (i = 0; i < size; i++)
	{
		Visit_all(node[i], ch_ary, 0, size + 1);
		puts("");
	}
	
	


}
#endif

#ifdef TEST
for (row = 0; row < size; row++)
{
	printf("%c:", node[row]->ch);
	for (col = 0; col < size; col++)
	{
		if (node[row]->link[col])
			printf("%c ", node[row]->link[col]->ch);
	}
	puts("");
}



int row, col;
int size = _msize(ap) / sizeof(int*);
//0:A, 1:B, ....
for (row = 0; row < size; row++)
{
	printf("%c:", node[row]->ch);
	for (col = 0; col < size; col++)
	{
		if (node[row]->link[col])
			printf("%c ", node[row]->link[col]->ch);
		}
	puts("");
	}

while (1)
{
	ap = Make_Route();
	Print_Route_info(ap);
	system("pause");
	}

#endif

#ifdef BASIC_SET

srand((unsigned int)time(NULL));
Graph** node;
int** ap = Make_Route();
char ch_ary[5] = { 0 };



Print_Route_info(ap);
puts("");
node = Make_Node(ap);
Input_Route(node, ap);

Visit_every_node(node[0]);



#endif
