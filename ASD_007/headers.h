#pragma once
#include"types.h"

void getMaxMin(TNode* RootTree, int& Max, int& Min);
void showTree(TNode* RootTree);
void initTree(TNode*& RootTree, int cntEl);
void findInTree(int key, TNode* pNode, TNode* findNode);
void insTree(TNode*& RootTree, TNode* elem);
void PBDOP1(TNode* ptree, double& sum, int& n);
void PBDOP2(TNode* ptree);
void pause();
void deleteAllTree(TNode*& ptree);