#include <vector>
#include <bits/stdc++.h>
#include <deque>
#ifndef BFS_H
#define BFS_H
class Bfs
{
public:
    Bfs(std::vector<std::vector<int>> v,size_t d,std::vector<std::vector<int>>g={{1,2,3},{4,5,6},{7,8,0}});
    class Node
    {
        public:
        std::vector<std::vector<int>> vec;
        Node* p;
        Node* u;
        Node* d;
        Node* r;
        Node* l;
        std::string dir;
    };
    Node* head = nullptr;
    std::deque<Node*> in;
    std::deque<std::vector<std::vector<int>>> out;
    std::deque<std::string> guid;
    std::vector<std::vector<int>> goal;
    bool comp(std::vector<std::vector<int>>);
    std::vector<int> pos(std::vector<std::vector<int>>);
    void show(Node&);

};



#endif