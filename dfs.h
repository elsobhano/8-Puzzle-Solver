#ifndef DFS_H
#define DFS_H
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
class Dfs
{
public:
    Dfs(std::vector<std::vector<int>>v,size_t d,std::vector<std::vector<int>>g={{1,2,3},{4,5,6},{7,8,0}});
    class Node
    {
        public:
        std::vector<std::vector<int>> vec;
        Node* p;
        Node* u;
        Node* d;
        Node* r;
        Node* l;
        int num_child;
        int ug ;
        int dg ;
        int rg ;
        int lg ;
        std::string dir;
    };
    Node* head = nullptr;
    std::stack<Node*> in;
    std::deque<std::vector<std::vector<int>>> open;
    std::vector<std::vector<int>> goal ;
    std::deque<std::vector<std::vector<int>>> out;
    std::deque<std::string> guid;
    bool comp(std::vector<std::vector<int>>);
    std::vector<int> pos(std::vector<std::vector<int>>);
    void show(Node&);
};
#endif