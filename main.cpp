#include <iostream>
#include "binarytree.h"

int main()
{
    BinaryTree<int>* BT = new BinaryTree<int>();
    while(true) {
        short unsigned int choice = 0;
        std::cout<<"1>>>Insert data"<<std::endl;
        std::cin>>choice;
        if(choice==1)
            BT->insert();
        else
            break;
    }
    return 0;
}
