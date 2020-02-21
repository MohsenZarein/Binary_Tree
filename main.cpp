#include <iostream>
#include "binarytree.h"

void PrintList()
{
    std::cout<<"1>>>Insert data"<<std::endl;
    std::cout<<"2>>>Search data"<<std::endl;
    std::cout<<"3>>>display preorder"<<std::endl;
    std::cout<<"4>>>display inorder"<<std::endl;
    std::cout<<"5>>>display postorder"<<std::endl;
    std::cout<<"6>>>Delete data"<<std::endl;
    std::cout<<"7>>>Exit"<<std::endl<<std::endl;
}

int main()
{
    BinaryTree<std::string>* BT = new BinaryTree<std::string>();

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
         case 5:
            BT->display_postorder();
            break;
         case 6:
            BT->Delete();
            break;
         case 7:
            delete BT;
            return 0;
        default:
            std::cerr<<"invalid input"<<std::endl;
            break;
        }
    }
    delete BT;
    return 0;
}
