//
//  Link.hpp
//  Link
//
//  Created by apple on 2023/7/25.
//

#ifndef Link_
#define Link_
using namespace std;
/* The classes below are exported */
#pragma GCC visibility push(default)
class Node
{   public:
    int val;Node* next;
    Node():val(0),next(nullptr){}
};
class Link
{
public:
    Node* head;Node* tail;
    Link(): head(nullptr),tail(nullptr){}
    void pushbacklink(int data);
    void pushbackforward(int data);
    int lengthlink();
    void printLink();
    void reverselink();
    void insertlink(int position,int data);//在第i个位置后面插入
    void deletelink(int position);//删除第i个位置的元素
};

void Link::pushbacklink(int data){
    Node* n = new Node;n->val = data;
    if(head == nullptr){head = n;tail = n;}
    else{
        tail->next = n;tail = tail->next;
    }
}
void Link::pushbackforward(int data){
    Node n;n.val = data;
    if(head == nullptr){head = &n;tail = &n;}
    else{
        Node* temp = new Node(n);
        temp->next = head;head = temp;
    }
}
int Link::lengthlink(){
    Node* temp = head; int len = 1;
    while(temp != tail){temp = temp->next;len +=1;}
    return len;
}

void Link::printLink(){
    Node* temp = head;
    if(head == nullptr){cout<<"This link is empty"<<endl;}
    while(temp != nullptr)
    {cout<<temp->val<<" ";temp = temp->next;}
    
}
void Link::reverselink(){
    Node* temp = new Node;
    Node*a  = new Node;Node*b  = new Node;Node*c  = new Node;
    if(head->next == tail)
    {tail->next = head;head->next = nullptr;temp = head;head = tail;tail = temp;}
    if(head->next != tail && head != tail){
        a= head; b = a->next;c=b->next;
        a->next = nullptr;
        while(c != tail)
        {   b->next = a;
            a=b;b=c;c= c->next;
        }
        b->next = a;c->next = b;
        temp = head;head = tail;tail = temp;
    }
}

void Link::insertlink(int position,int data){
    int i;
    Node* temp = head;Node* temp1 = temp->next;
    Node* insert = new Node;insert->val = data;
    if(position<0){cout<<"Position must greater than 0"<<endl;}
    
    else{
        if(position == 0){insert->next = head;head = insert;}
        else{
            for(i =1;i<=position;i++){
                if(temp==tail){if(i == position){tail->next = insert;tail = tail->next;}else{cout<<"Position is too large"<<endl;break;}}
                else{
                    if(i==position){temp1 = temp->next; insert->next = temp1;temp->next = insert;}
                    else{temp = temp->next;}}
            }
            
            
        }}}

void Link::deletelink(int position){
    Node* temp= head;Node* temp1;int i,P;
    if(position<=0){cout<<"Position must be greater than 0"<<endl;}
    else{
        if(position>1){position = position -1;
            for(i =1;i<=position;i++){
                if(temp->next==tail){if(i == position){temp->next = nullptr;tail = temp;}else{cout<<"Position is too large"<<endl;break;}}
                else{
                    if(i==position){
                        temp1 = temp->next->next;temp->next = temp1;}
                    else{temp = temp->next;}
                    
                }}}
        else{head = head->next;}
    }}


#pragma GCC visibility pop
#endif
