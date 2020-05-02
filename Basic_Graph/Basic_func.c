#include"ALL.h"
#ifdef TEST_SET
int** Make_Route()
{
	int** ap;
	//int size = rand() % (END - START + 1) + START;
	int size = 4;
	int row, col;


	ap = (int**)malloc(size * sizeof(int*));
	for (row = 0; row < size; row++)
		ap[row] = (int*)calloc(size, sizeof(int));

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (row != col)
				ap[row][col] = rand() % 2;
		}
	}

	return ap;
}

void Print_Route_info(int** ap)
{
	int row, col, i;
	int size = _msize(ap) / sizeof(int*);

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

Graph** Make_Node(int** ap)
{
	int i;
	int size = _msize(ap) / sizeof(int*);
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

void Input_Route(Graph** node, int** ap)
{
	int row, col;
	int size = _msize(ap) / sizeof(int*);
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

//해당 노드가 2번이 되면 종료
//다른 노드는 2번 방문 불가
void Visit_all_TEST(Graph* node, char* ch_ary, int idx)
{
	int i;
	int cnt_ary[4] = { 0 };
	int target_idx = 0;
	if (node)
	{
		ch_ary[idx] = node->ch;
		idx++;
		for (i = 0; i < 5; i++)
		{
			if (ch_ary[i] == 0)//방문한 노드 저장하는 배열
				break;
			else
			{
				cnt_ary[ch_ary[i] - 'A']++;
				if (cnt_ary[ch_ary[i] - 'A'] == 2)
				{
					target_idx = ch_ary[i] - 'A';
					if (target_idx + 'A' != ch_ary[0])//제일 처음에 들어간 문자와 다르면
						return;
					else if (target_idx + 'A' == ch_ary[0])//제일 처음에 들어간 문자와 같으면
					{

						for (i = 0; i < 5; i++)
						{
							if (ch_ary[i] != 0)
								printf("%c", ch_ary[i]);
						}
						puts("");
						return;
					}
				}

			}
		}
		Visit_all_TEST(node->link[0], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_TEST(node->link[1], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_TEST(node->link[2], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_TEST(node->link[3], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
	}
}

void Print_ary_ptr(Graph* node)
{
	int idx = 0;
	//int size = _msize(node->link) / _msize(node->link[0]);
	printf("%c\n", node->ch);

	while (1)
	{
		if (node->link[idx])
			printf("%c\n", node->link[idx]->ch);

		idx++;
	}
}
#endif
#ifdef ACTUAL
int** Make_Route()
{
	int** ap;
	int size = rand() % (END - START + 1) + START;
	int row, col;

	ap = (int**)malloc(size * sizeof(int*));
	for (row = 0; row < size; row++)
		ap[row] = (int*)calloc(size, sizeof(int));

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (row != col)
				ap[row][col] = rand() % 2;
		}
	}

	return ap;
}

void Print_Route_info(int** ap)
{
	int row, col, i;
	int size = _msize(ap) / sizeof(int*);

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

Graph** Make_Node(int** ap)
{
	int i;
	int size = _msize(ap) / sizeof(int*);
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

void Input_Route(Graph** node, int** ap)
{
	int row, col;
	int size = _msize(ap) / sizeof(int*);
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

//해당 노드가 2번이 되면 종료
//다른 노드는 2번 방문 불가
void Visit_all(Graph* node, char* ch_ary, int idx, int size)
{
	int i;
	//int cnt_ary[4] = { 0 };
	int* cnt_ary = (int*)calloc(size - 1, sizeof(int));
	int target_idx = 0;
	int alphabet = 0;

	if (node)
	{
		ch_ary[idx] = node->ch;
		idx++;
		for (i = 0; i < size; i++)
		{
			if (ch_ary[i] == 0)//방문한 노드 저장하는 배열
				break;
			else
			{
				cnt_ary[ch_ary[i] - 'A']++;
				if (cnt_ary[ch_ary[i] - 'A'] == 2)
				{
					target_idx = ch_ary[i] - 'A';
					if (target_idx + 'A' != ch_ary[0])//제일 처음에 들어간 문자와 다르면
						return;
					else if (target_idx + 'A' == ch_ary[0])//제일 처음에 들어간 문자와 같으면
					{

						for (i = 0; i < size; i++)
						{
							if (ch_ary[i] != 0)
								printf("%c", ch_ary[i]);
						}
						puts("");
						return;
					}
				}

			}
		}
	
		while (alphabet < size-1)
		{
			Visit_all(node->link[alphabet], ch_ary, idx, size);
			for (i = idx; i < size; i++)
				ch_ary[idx] = 0;
			alphabet++;
		}
	}
}

void Print_ary_ptr(Graph* node)
{
	int idx = 0;
	//int size = _msize(node->link) / _msize(node->link[0]);
	printf("%c\n", node->ch);

	while (1)
	{
		if (node->link[idx])
			printf("%c\n", node->link[idx]->ch);

		idx++;
	}
}
#endif


#ifdef NOT

void Visit_all(Graph* node, char* ch_ary, int idx)
{
	int i;
	int cnt_ary[4] = { 0 };
	int target_idx = 0;
	if (node)
	{
		ch_ary[idx] = node->ch;
		idx++;
		for (i = 0; i < 6; i++)
		{
			if (ch_ary[i] == 0)//방문한 노드 저장하는 배열
				break;
			else
			{
				cnt_ary[ch_ary[i] - 'A']++;
				if (cnt_ary[ch_ary[i] - 'A'] == 2)
				{
					target_idx = ch_ary[i] - 'A';
					if (target_idx + 'A' != ch_ary[0])//제일 처음에 들어간 문자와 다르면
						return;
					else if (target_idx + 'A' == ch_ary[0])//제일 처음에 들어간 문자와 같으면
					{

						for (i = 0; i < 6; i++)
						{
							if (ch_ary[i] != 0)
								printf("%c", ch_ary[i]);
						}
						puts("");
						return;
					}
				}

			}
		}
		Visit_all(node->link[0], ch_ary, idx);
		for (i = idx; i < 6; i++)
			ch_ary[idx] = 0;
		Visit_all(node->link[1], ch_ary, idx);
		for (i = idx; i < 6; i++)
			ch_ary[idx] = 0;
		Visit_all(node->link[2], ch_ary, idx);
		for (i = idx; i < 6; i++)
			ch_ary[idx] = 0;
		Visit_all(node->link[3], ch_ary, idx);
		for (i = idx; i < 6; i++)
			ch_ary[idx] = 0;
	}
}



int i = 0;
int alphabet = 0;
int target_idx = 0;
int cnt_ary[4] = { 0 };//0:'A', 1:'B'......, 이렇게 생각하고 카운트 해당 문자가 몇번 저장되었는지 횟수가 저장됨
if (node)
{
	//printf("%c", node->ch);
	ch_ary[idx] = node->ch;

	for (i = 0; i < 6; i++)
	{
		if (ch_ary[i] == 0)//방문한 노드 저장하는 배열
			break;
		else
		{
			cnt_ary[ch_ary[i] - 'A']++;
			if (cnt_ary[ch_ary[i] - 'A'] == 2)
			{
				target_idx = ch_ary[i] - 'A';
				if (target_idx + 'A' != ch_ary[0])//제일 처음에 들어간 문자와 다르면
					return;
				else if (target_idx + 'A' == ch_ary[0])//제일 처음에 들어간 문자와 같으면
				{

					for (i = 0; i < 6; i++)
					{
						if (ch_ary[i] != 0)
							printf("%c", ch_ary[i]);
					}
					puts("");
					return;
				}
			}

		}
	}

	/*if (target_idx + 'A' != ch_ary[0])//제일 처음에 들어간 문자와 다르면
		return;
	*/

	idx++;
	if (ch_ary[1] == 'D')
		puts("");
	while (alphabet < 4)
	{
		Visit_all(node->link[alphabet], ch_ary, idx);
		alphabet++;
	}
}
}

int Check_ary(char* ch_ary)
{
	int cnt = 0;
	int idx = 0;

	for (idx = 0; idx < 6; idx++)
	{
		if (ch_ary[0] == ch_ary[idx])
			cnt++;
	}
#endif