#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
using namespace std;

class ArrayList{
public:
    ArrayList();
    bool empty();
    int size();
    void createNode(std::basic_string<char,std::char_traits<char>,std::allocator<char>> obj);
    void insert_start(std::basic_string<char,std::char_traits<char>,std::allocator<char>> obj);
    void insert_position(std::basic_string<char,std::char_traits<char>,std::allocator<char>> obj, int pos);
    void delete_first();
    void delete_last();
    void delete_position(int pos);

private:
    struct Node
    {
        std::basic_string<char,std::char_traits<char>,std::allocator<char>> m_data;
        Node *next;
    };
    Node *head;
    Node *tail;
};

#endif // ARRAYLIST_H
