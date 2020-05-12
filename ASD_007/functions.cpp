#include"types.h"
#include"headers.h"

void PBDOP1(TNode* ptree, double& sum, int& n)
{
    //int sum = 0;
    //int n = 0;
    if (ptree == NULL)
        return;
    if (ptree != NULL)
    {
        sum += ptree->inf;  n++;
        PBDOP1(ptree->left, sum, n);
        PBDOP1(ptree->right, sum, n);
        cout << ptree->inf << endl;
    }
}

void PBDOP2(TNode* ptree)
{
    if (ptree == NULL)
        return;
    if (ptree != NULL)
    {
        PBDOP2(ptree->left);
        PBDOP2(ptree->right);
        if (ptree->inf % 2 == 0 && (ptree->left == NULL && ptree->right == NULL))
            cout << "Leaf: " << ptree->inf << endl;
    }

}

void deleteAllTree(TNode*& ptree)
{
    if (ptree == NULL)
        return;
    if (ptree != NULL)
    {
        deleteAllTree(ptree->left);
        deleteAllTree(ptree->right);
    }
}

void insTree(TNode*& RootTree, TNode* elem)
{
    if (RootTree == NULL)
        RootTree = elem;
    else
        if (elem->inf < RootTree->inf)
            insTree(RootTree->left, elem);
        else
            insTree(RootTree->right, elem);
} // insTree

void initTree(TNode*& RootTree, int cntEl)
{
    TNode* pNew; // �������� �� ����� ����� ������

    RootTree = NULL;
    srand(time(NULL) | clock());
    for (int i = 0; i < cntEl; i++)
    {
        pNew = new TNode;
        pNew->inf = rand() % 100;
        pNew->left = NULL;
        pNew->right = NULL;
        insTree(RootTree, pNew);
    }
}

void showTree(TNode* RootTree)
{
    static int tab = 0;                 //������� ������� � ��������� �� ���� �����
    if (!RootTree)                      //����� ��������� ������ �������� �� ����� ������� NULL
    {
        cout << "NULL" << endl;
        return;
    }
    cout << RootTree->inf << endl;      //���� ������
    tab++;                              //��������� ������� �������
    for (int i = 0; i < tab; i++)       //��������� ������� �� �����
        cout << "      ";
    cout << "���:";
    showTree(RootTree->left);           //����������� ����� � ��� ��������
    for (int i = 0; i < tab; i++)       //��������� ������� �� �����
        cout << "      ";
    cout << "��:";
    showTree(RootTree->right);          //����������� ����� � ����� ��������
    tab--;                              //��������� ������� �������
}

void getMaxMin(TNode* RootTree, int& max, int& min)
{
    if (RootTree == NULL) // ����� ��������� ������ ������ �����
        return;
    if (RootTree->inf > max)
        max = RootTree->inf;
    if (RootTree->inf < min)
        min = RootTree->inf;
    getMaxMin(RootTree->left, max, min);
    getMaxMin(RootTree->right, max, min);
}

void pause()
{
    cout << "\n ��� ����������� ������ ���� ������i�� ����-��� ����i��!";
    _getch();
}

void findInTree(int key, TNode* PNode, TNode* findNode)
{
    if (PNode == NULL)
    {
        findNode = NULL;
        return;
    }
    if (PNode->inf > key)                           //����� �� ����� ��������
        findInTree(key, PNode->left, findNode);
    else
        if (PNode->inf < key)                       //����� �� ������� ��������
            findInTree(key, PNode->right, findNode);
        else
        {
            findNode = PNode;
            cout << "����� ���� ��������." << endl;
            return;                                 // ����� ���������
        }
}