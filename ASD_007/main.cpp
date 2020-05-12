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
        cout << "1.Заповнення дерева. \n";
        cout << "2.Пошук мінімального і максимального елемента в упорядкованому бінарному дереві.\n";
        cout << "3.Виведення дерева." << endl;
        cout << "4.Додати новий елемент до дерева." << endl;
        cout << "5.Знайти середнє значення елементів дерева." << endl;
        cout << "6.Знайти парні листи дерева." << endl;
        cout << "7.Видалити дерево." << endl;
        cout << "8.Знайти елемент.\n";
        cout << "16.Вихiд iз програми!\n";
        cout << "-------------------------------------------\n";
        cout << "Оберiть операцiю для списку: ";
        cin >> ch;
        cout << "-------------------------------------------\n";
        switch (ch)
        {
            case 1:
            {
                int cnt;
                cout << "Введіть кількість елементів дерева: ";
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
                cout << "Максимальне значення: " << max << endl;
                cout << endl;
                cout << "Мінімальна значення: " << min << endl;
                break;
            }
            case 3:
            {
                showTree(root);
                break;
            }
            case 4:
            {
                cout << "Введіть новий елемент дерева: ";
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
                cout << "Середнє значення елементів дерева: " << sum / n << endl;
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
                cout << "Введіть елемент, який необхідно знайти: " << endl;
                cin >> key;
                findInTree(key, root, findNode);
                break;
            }
            case 16:
            {
                cout << "Ви успiшно завершили операцiю виходу з програми!" << endl;
                exit(0);
            }
            default:
                cout << "Ви вибрали неозначену операцiю!\n\n";
                break;
        }
        pause();
    } while (true);
    return 0;
}