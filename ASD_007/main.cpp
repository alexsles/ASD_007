#include <iostream>
#include <string>
#include <Windows.h>
#include "types.h"
#include "headers.h"
using namespace std;
TNode* root;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int ch;
    do
    {
        system("cls");
        SetConsoleTitleA("ASD-007");
        cout << "1.���������� ������. \n";
        cout << "2.����� ���������� � ������������� �������� � �������������� �������� �����.\n";
        cout << "3.��������� ������." << endl;
        cout << "4.������ ����� ������� �� ������." << endl;
        cout << "5.������ ������ �������� �������� ������." << endl;
        cout << "6.������ ���� ����� ������." << endl;
        cout << "7.�������� ������." << endl;
        cout << "8.������ �������.\n";
        cout << "16.���i� i� ��������!\n";
        cout << "-------------------------------------------\n";
        cout << "����i�� ������i� ��� ������: ";
        cin >> ch;
        cout << "-------------------------------------------\n";
        switch (ch)
        {
            case 1:
            {
                int cnt;
                cout << "������ ������� �������� ������: ";
                cin >> cnt;
                cout << endl;
                initTree(root, cnt);
                showTree(root);
                break;
            }
            case 2:
            {
                showTree(root);
                int max = INT_MIN, min = INT_MAX;
                cout << "-------------------------------------------\n";
                getMaxMin(root, max, min);
                cout << "����������� ��������: " << max << endl;
                cout << endl;
                cout << "̳������� ��������: " << min << endl;
                break;
            }
            case 3:
            {
                showTree(root);
                break;
            }
            case 4:
            {
                cout << "������ ����� ������� ������: ";
                TNode* elem = new TNode;
                cin >> elem->inf;
                elem->left = NULL;
                elem->right = NULL;
                insTree(root, elem);
                showTree(root);
                break;
            }
            case 5:
            {
                double sum = 0;
                int n = 0;
                showTree(root);
                PBDOP1(root, sum, n);
                cout << "������ �������� �������� ������: " << sum / n << endl;
                break;
            }
            case 6:
            {
                showTree(root);
                PBDOP2(root);
                break;
            }
            case 7:
            {
                showTree(root);
                deleteAllTree(root);
                showTree(root);
                break;
            }
            case 8:
            {
                TNode* findNode = new TNode;
                int key;
                cout << "������ �������, ���� ��������� ������: " << endl;
                cin >> key;
                findInTree(key, root, findNode);
                break;
            }
            case 16:
            {
                cout << "�� ���i��� ��������� ������i� ������ � ��������!" << endl;
                exit(0);
            }
            default:
                cout << "�� ������� ���������� ������i�!\n\n";
                break;
        }
        pause();
    } while (true);
    return 0;
}