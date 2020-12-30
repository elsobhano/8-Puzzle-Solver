#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "bfs.h"
#include "color.h"
#include "dfs.h"
#include <deque>
#include <list>
#include <experimental/random>


int main()
{
    int sit = 1;
    while(sit == 1){
        std::cout<<color::bold_cyan<<"Hi there"<<color::reset<<'\n';
        std::cout<<color::bold_magenta<<"Let`s Solve 8-Puzzle"<<color::reset<<'\n';
        std::cout<<"Do you want to solve "<<color::bold_cyan <<"Random Puzzle "<<color::reset<<"Or "<<color::bold_cyan<< "Your Puzzle"<<color::reset<<'\n';
        std::cout<<"1: Print"<<color::bold_yellow<<" R "<<color::reset<<",If you want to solve Random Puzzle "<<'\n';
        std::cout<<"2: Print"<<color::bold_yellow<<" M "<<color::reset<<",If you want to solve Your Puzzle "<<'\n';
        std::string G;
        std::cin >> G;
        std::vector<std::vector<int>> vec;
        if(G=="M")
        {
            std::vector<int> row_1 = {0,0,0};
            std::vector<int> row_2 = {0,0,0};
            std::vector<int> row_3 = {0,0,0};
            std::cout<<color::bold_red<<"Notice for Entering the rows "<<color::reset<<'\n';
            std::cout<<"Example: for entering this row -> [1 2 3] "<<'\n';
            std::cout<<"Print 1 then "<<color::bold_yellow<<"Press Enter"<<color::reset<<'\n';
            std::cout<<"Print 2 then "<<color::bold_yellow<<"Press Enter"<<color::reset<<'\n';
            std::cout<<"Print 3 then "<<color::bold_yellow<<"Press Enter"<<color::reset<<'\n';
            std::cout<<"1: Please enter the "<<color::bold_cyan<<"first row: "<<color::reset<<std::endl;
            std::cin >> row_1[0]>>row_1[1]>>row_1[2];
            vec.push_back(row_1);
            std::cout<<"2: Please enter the "<<color::bold_cyan<<"second row: "<<color::reset<<std::endl;
            std::cin >> row_2[0]>>row_2[1]>>row_2[2];
            vec.push_back(row_2);
            std::cout<<"3: Please enter the "<<color::bold_cyan<<"third row: "<<color::reset<<std::endl;
            std::cin >> row_3[0]>>row_3[1]>>row_3[2];
            vec.push_back(row_3);
        }
        else if(G == "R")
        {
            int a[9] = {};
            vec = {{},{},{}};
            std::vector<int> v1;
            for (size_t i = 0; i < 9; i++)
            {
                int r = std::experimental::randint(0,8);
                while(a[r] != 0)
                {
                    r = std::experimental::randint(0,8);
                }
                a[r] = 1;
                v1.push_back(r);
            }
            int k = 0;
            for (size_t i = 0; i < 9; i = i + 3)
            {
                for (size_t j = 0; j < 3; j++ )
                {
                    vec[k].push_back(v1[i+j]);
                    
                }
                k = k + 1;
            }
        }
        std::cout<<color::bold_cyan<<"Your Starting state, Please Check it !"<<color::reset<<'\n';
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                std::cout<<vec[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        size_t depth;
        std::cout<<"Please Enter the "<<color::bold_yellow <<"Maximum depth"<<color::reset<<'\n';
        std::cin>>depth;
        std::string N;
        std::cout<<"Please define your method "<<color::bold_cyan<<"Dfs Or Bfs"<<color::reset<<'\n';
        std::cout<<"1: Print "<<color::bold_yellow<<"B"<<color::reset<<" for"<<color::bold_yellow<<" Bfs"<<color::reset<<'\n';
        std::cout<<"2: Print "<<color::bold_yellow<<"D"<<color::reset<<" for"<<color::bold_yellow<<" Dfs"<<color::reset<<'\n';
        std::cin >> N;
        std::string H;
        std::cout<<"Do you want to change "<<color::bold_yellow<<"Goal Node"<<color::reset<<'\n';
        std::cout<<"1: Print "<<color::bold_yellow<<"Y"<<color::reset<<" for YES"<<color::reset<<'\n';
        std::cout<<"2: Print "<<color::bold_yellow<<"N"<<color::reset<<" for NO"<<color::reset<<'\n';
        std::cin>>H;
        std::vector<std::vector<int>> g_node;
        if(H=="Y")
        {
            std::cout<<"Ok, Let`s change it!"<<'\n';
            g_node = {};
            std::vector<int> row_1 = {0,0,0};
            std::vector<int> row_2 = {0,0,0};
            std::vector<int> row_3 = {0,0,0};
            std::cout<<color::bold_red<<"Notice for Entering the rows "<<color::reset<<'\n';
            std::cout<<"Example: for entering this row -> [1 2 3] "<<'\n';
            std::cout<<"Print 1 then "<<color::bold_yellow<<"Press Enter"<<color::reset<<'\n';
            std::cout<<"Print 2 then "<<color::bold_yellow<<"Press Enter"<<color::reset<<'\n';
            std::cout<<"Print 3 then "<<color::bold_yellow<<"Press Enter"<<color::reset<<'\n';
            std::cout<<"Please enter the "<<color::bold_cyan<<"first row: "<<color::reset<<std::endl;
            std::cin >> row_1[0]>>row_1[1]>>row_1[2];
            g_node.push_back(row_1);
            std::cout<<"Please enter the "<<color::bold_cyan<<"second row: "<<color::reset<<std::endl;
            std::cin >> row_2[0]>>row_2[1]>>row_2[2];
            g_node.push_back(row_2);
            std::cout<<"Please enter the "<<color::bold_cyan<<"third row: "<<color::reset<<std::endl;
            std::cin >> row_3[0]>>row_3[1]>>row_3[2];
            g_node.push_back(row_3);
        }
        if(N == "B")
        {
            if(H=="Y"){
                Bfs{vec,depth,g_node};
            }
            else
            {
                Bfs{vec,depth};
            }
            
        }
        else if(N == "D")
        {
            if(H=="Y"){
                Dfs{vec,depth,g_node};
            }
            else
            {
                Dfs{vec,depth};
            }
        }
        std::cout<<"Do you have another puzzle"<<'\n';
        std::cout<<"1: Print "<<color::bold_yellow<<"Y"<<color::reset<<" for YES"<<color::reset<<'\n';
        std::cout<<"2: Print "<<color::bold_yellow<<"N"<<color::reset<<" for NO"<<color::reset<<'\n';
        std::cin>>sit;
    }
    std::cout<<color::bold_cyan<<"Thanks!"<<color::reset<<'\n';
}
