#pragma once

#ifndef __FUNC_H__
#define __FUNC_H__

int** Make_Route();
void Print_Route_info(int** ap);
Graph** Make_Node(int** ap);
void Input_Route(Graph** node, int** ap);
void Visit_all(Graph* node, char* ch_ary, int idx, int size);
void Print_ary_ptr(Graph* node);

/*TEST*/
void Print_Route_info_FIXED(int(*ap)[END]);
Graph** Make_Node_FIXED();
void Input_Route_FIXED(Graph** node, int(*ap)[END]);
void Visit_all_TEST(Graph* node, char* ch_ary, int idx);
#endif
