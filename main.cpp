#include <iostream>
#include <iomanip>
#include "binarytree.h"

void PrintList()
{
    std::cout<<"1>>>Insert data"<<std::endl;
    std::cout<<"2>>>Search data"<<std::endl;
    std::cout<<"3>>>display preorder"<<std::endl;
    std::cout<<"4>>>display inorder"<<std::endl;
    std::cout<<"5>>>display postorder"<<std::endl<<std::endl;
}

int main()
{
    BinaryTree<int>* BT = new BinaryTree<int>();

    PrintList();

    while(true) {
        short int choice = 0;
        std::cout<<"choice:";
        std::cin>>choice;

        switch (choice) {
        case 1:
            BT->insert();
            break;
        case 2:
            BT->Search();
            break;
         case 3:
            BT->display_preorder();
            break;
         case 4:
            BT->display_inorder();
            break;
        default:
            std::cerr<<"invalid input"<<std::endl;
            break;
        }
    }
    return 0;
}
