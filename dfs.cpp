#include "dfs.h"
#include "color.h"
Dfs::Dfs(std::vector<std::vector<int>>v,size_t d,std::vector<std::vector<int>>g)
{
    Node* node = new Node;
    node->vec = v;
    node->dir = "Start";
    this->head = node;
    this->in.push(node);
    this->goal = g;
    int x;
    int y;
    int b;
    std::string action = "";
    int nc;
    size_t depth = d;
    while(this->in.size()>0)
    {
        if(this->in.size() == depth + 1)
        {
            this->in.pop();
            Node* a1 = this->in.top();
            for (int i = 0; i < a1->num_child; i++)
            {
                this->open.pop_back();
            }
        }
        else
        {
            Node* s = this->in.top();
            action = s->dir;
            if(s->ug==1 && s->dg==1 && s->rg==1 && s->lg==1)
            {
                this->in.pop();
                Node* a2;
                if(this->in.size()>0){
                    a2 = this->in.top();
                }
                nc = a2->num_child;
                for (int i = 0; i < nc; i++)
                {
                    if(this->open.size()>0)
                        this->open.pop_back();
                }
            }
            else
            {
                s->num_child = 0;
                std::vector<int>grid = this->pos(s->vec);
                x = grid[0];
                y = grid[1];
                int c = 0;
                if (action != "Go Up" &&  x>0)
                {
                    b = 0;
                    Node* node1 = new Node;
                    node1->vec = s->vec;
                    int up = node1->vec[x-1][y];
                    node1->vec[x][y] = up;
                    node1->vec[x-1][y] = 0;
                    if(s->ug==0 && c==0)
                    {
                        s->u = node1;
                        //node1->depth = s->depth + 1;
                        this->in.push(node1);
                        c = 1;
                        s->ug = 1;
                        if (std::count(this->open.begin(), this->open.end(), node1->vec)==0)
                            b = this->comp(node1->vec);
                        else
                        {
                            b = 0;
                        }
                    }
                    node1->p = s;
                    node1->dir = "Go Down";
                     
                    if(s->ug==0 && this->in.size()<depth)
                    {
                        s->num_child += 1;
                        this->open.push_back(node1->vec);
                    }
                    if(b==1)
                    {
                        this->show(*node1);
                        break;
                    }
                }
                else if((action == "Go Up" || x == 0))
                {
                    s->ug = 1;
                }
                if( action != "Go Down" && x<2)
                {
                    b = 0;
                    Node* node2 = new Node;
                    node2->vec = s->vec;
                    int down = node2->vec[x+1][y];
                    node2->vec[x][y] = down;
                    node2->vec[x+1][y] = 0;
                    if(s->dg==0 && c==0)
                    {
                        s->d = node2;
                        //node2->depth = s->depth + 1;
                        this->in.push(node2);
                        c = 1;
                        s->dg = 1;
                        if (std::count(this->open.begin(), this->open.end(), node2->vec)==0)
                            b = this->comp(node2->vec);
                        else
                        {
                            b = 0;
                        }
                    }
                    node2->p = s;
                    node2->dir = "Go Up";
                    if(s->dg==0 && this->in.size()<depth)
                    {
                        s->num_child += 1;
                        this->open.push_back(node2->vec);
                    }
                    if(b==1)
                    {
                        this->show(*node2);
                        break;
                    }
                }
                else if((action == "Go Down" || x==2))
                {
                    s->dg = 1 ;
                }
                if(action!="Go Left" &&  y>0)
                {
                    b = 0;
                    Node* node3 = new Node;
                    node3->vec = s->vec;
                    int left = node3->vec[x][y-1];
                    node3->vec[x][y] = left;
                    node3->vec[x][y-1] = 0;
                    if(s->lg==0 && c==0)
                    {
                        s->l = node3;
                        //node3->depth = s->depth + 1;
                        this->in.push(node3);
                        c = 1;
                        s->lg = 1;
                        if (std::count(this->open.begin(), this->open.end(), node3->vec)==0)
                            b = this->comp(node3->vec);
                        else
                        {
                            b=0;
                        }
                    }
                    node3->p = s;
                    node3->dir = "Go Right";
                    if(s->lg == 0 && this->in.size()<depth)
                    {
                        s->num_child += 1;
                        this->open.push_back(node3->vec);
                    }
                    if(b==1)
                    {
                        this->show(*node3);
                        break;
                    }
                }
                else if ((action=="Go Left" || y==0))
                {
                    s->lg = 1;
                }
                if(action != "Go Right" && y<2)
                {
                    b = 0;
                    Node* node4 = new Node;
                    node4->vec = s->vec;
                    int right = node4->vec[x][y+1];
                    node4->vec[x][y] = right;
                    node4->vec[x][y+1] = 0;
                    if(s->rg==0 && c == 0)
                    {
                        s->r = node4;
                        //node4->depth = s->depth + 1;
                        this->in.push(node4);
                        c = 1;
                        s->rg = 1;
                        if (std::count(this->open.begin(), this->open.end(), node4->vec)==0)
                        {
                            b = this->comp(node4->vec);
                        }
                        else
                        {
                            b=0;
                        }
                        
                    }
                    node4->p = s;
                    node4->dir = "Go Left";
                    
                    if(s->rg == 0 && this->in.size()<depth)
                    {
                        s->num_child += 1;
                        this->open.push_back(node4->vec);
                    }
                    if(b==1)
                    {
                        this->show(*node4);
                        break;
                    }
                }
                else if((action == "Go Right" || y==2))
                {
                    s->rg = 1;
                }
            }
        }
    }
    if(b==0)
    {
        std::cout<<"Sorry We Can`t Solve Your Puzzle"<<std::endl;
    }
}

bool Dfs::comp(std::vector<std::vector<int>> vec)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(vec[i][j] != this->goal[i][j])
            {
                return 0;
            }
        }
        
    }
    return 1;
    
}
std::vector<int> Dfs::pos(std::vector<std::vector<int>> vec)
{
    std::vector<int> v;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(vec[i][j] == 0)
            {
                v.push_back(i);
                v.push_back(j);
                return v;
            }
        }
        
    }
    return v;

}
void Dfs::show(Node& node)
{
    std::vector<std::vector<int>> l;
    l.assign(node.vec.begin(),node.vec.end());
    this->out.push_front(l);
    this->guid.push_front(node.dir);
    while(node.p!=head)
    {
        l = {};
        node = *node.p;
        l.assign(node.vec.begin(),node.vec.end());
        this->guid.push_front(node.dir);
        this->out.push_front(l);
    }
    l = {};
    l.assign(head->vec.begin(),head->vec.end());
    this->out.push_front(l);
    this->guid.push_front(head->dir);
    std::vector<std::vector<int>> s;
    for (size_t i = 0; i < this->out.size(); i++)
    {
        std::cout<<color::bg_cyan<<i<<":"<<this->guid[i]<<color::reset<<std::endl;
        s = this->out[i];
        std::cout<<'|';
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                
                if(s[j][k] == 0)
                {
                    std::cout<<" "<<"|";
                }
                else
                {
                    std::cout<<s[j][k]<<'|';
                }
                std::cout<<" ";
            }
            std::cout<<std::endl;
            if(j!=2)
                std::cout<<'|';
        }
        std::cout<<std::endl;
    }
    std::cout<<color::bg_red<<"Finish"<<color::reset<<std::endl;
}