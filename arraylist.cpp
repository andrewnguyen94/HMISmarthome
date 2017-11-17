#include "arraylist.h"
#include <iostream>

void ArrayList::delNode(QObject *obj)
{

}

void ArrayList::createNode(QObject obj)
{
    Node *temp = new Node;
    temp->m_data = obj;
    temp->next = NULL;
    if(head == NULL){

        head = temp;
        tail = temp;
        temp = NULL;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void ArrayList::insert_start(QObject obj)
{
    Node *tmp = new Node;
    tmp->m_data = QObject;
    tmp->next = head;
    head = tmp;
}

void ArrayList::insert_position(QObject obj, int pos)
{
    Node *prev = new Node;
    Node *cur = new Node;
    Node *tmp = new Node;
    cur = head;
    for(int i = 1; i < pos; i++){
        prev = cur;
        cur = cur->next;
    }
    tmp->m_data = obj;
    prev->next = tmp;
    tmp->next = cur;
}

void ArrayList::delete_first()
{
    Node *tmp = new Node;
    tmp = head;
    head = head->next;
    delete tmp;
}

void ArrayList::delete_last()
{
    Node *cur = new Node;
    Node *prev = new Node;
    cur = head;
    while(cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }
    tail = prev;
    prev->next = NULL;
    delete cur;
}

void ArrayList::delete_position(int pos)
{
    Node *cur = new Node;
    Node *prev = new Node;
    cur = head;
    for(int i = 1; i < pos; i++){
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
}
