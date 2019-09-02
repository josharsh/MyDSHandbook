#include <stdio.h>
struct Node{
    int data;
    struct Node* link;
};
int main()
{  
   /* Pointers To Three Nodes of the linked list */
   struct Node* head;
   struct Node* middle;
   struct Node* end;
   /*Dynamic Memory Allocation for Three nodes */
   head=(struct Node*)malloc(sizeof(struct Node));
   middle=(struct Node*)malloc(sizeof(struct Node));
   end=(struct Node*)malloc(sizeof(struct Node));
   /*Data in Nodes and Creation of Internal Links */
   head->data=1;
   head->link=middle;
   middle->data=2;
   middle->link=end;
   end->data=3;
   end->link=NULL;
return 0;
}
