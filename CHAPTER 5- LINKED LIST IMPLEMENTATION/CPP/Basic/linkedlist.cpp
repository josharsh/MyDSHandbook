#include <iostream>
using namespace std;
class Node{
    public: int data;
    Node* next;
};
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
return 0;
}
