/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Node{
    public: int data;
    Node* next;
};
void printlist(Node* initial){
    while(initial!=NULL){
        cout<< initial->data;
        initial=initial->next;
    }
}
int main()
{
    Node* head=new Node();
    Node* middle=new Node();
    Node* end=new Node();
    head->data=1;
    head->next=middle;
    middle->data=2;
    middle->next=end;
    end->data=3;
    end->next=NULL;
    printlist(head);
return 0;
}
