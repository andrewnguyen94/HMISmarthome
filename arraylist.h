#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <QObject>
using namespace std;

class ArrayList{
public:
    ArrayList(){
        head = NULL;
        tail = NULL;
    };
    bool empty();
    int size();
    void delNode(QObject *obj);
    void createNode(QObject obj);
    void insert_start(QObject obj);
    void insert_position(QObject obj, int pos);
    void delete_first();
    void delete_last();
    void delete_position(int pos);

private:
    struct Node
    {
        QObject m_data;
        Node *next;
    };
    Node *head;
    Node *tail;
}

#endif // ARRAYLIST_H
