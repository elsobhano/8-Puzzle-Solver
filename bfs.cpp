# include "bfs.h"
# include "color.h"
Bfs::Bfs(std::vector<std::vector<int>> v,size_t d,std::vector<std::vector<int>>g)
{
    Node* node = new Node;
    node->vec = v;
    node->dir = "Start";
    this->head = node;
    this->in.push_back(node);
    this->goal = g;
    int x;
    int y;
    size_t layer = 0;
    while (true){
        size_t count = this->in.size();
        int b;
        for (size_t i = 0; i < count; i++)
        {
            Node* s = this->in.front();
            this->in.pop_front();
            std::vector<int>grid = this->pos(s->vec);
            x = grid[0];
            y = grid[1];
            if (s->dir!= "Go UP" && x>0)
            {
                Node* node1 = new Node;
                node1->vec = s->vec;
                int up = node1->vec[x-1][y];
                node1->vec[x][y] = up;
                node1->vec[x-1][y] = 0;
                s->u = node1;
                node1->p = s;
                node1->dir = "Go Down";
                this->in.push_back(node1);
                b = this->comp(node1->vec);
                if(b==1)
                {
                    this->show(*node1);
                    break;
                }
            }
            if(s->dir!="Go Down" && x<2)
            {
                Node* node2 = new Node;
                node2->vec = s->vec;
                int down = node2->vec[x+1][y];
                node2->vec[x][y] = down;
                node2->vec[x+1][y] = 0;
                s->d = node2;
                node2->p = s;
                node2->dir = "Go UP";
                this->in.push_back(node2);
                b = this->comp(node2->vec);
                if(b==1)
                {
                    this->show(*node2);
                    break;
                }
            }
            if(s->dir!="Go Left" && y>0)
            {
                Node* node3 = new Node;
                node3->vec = s->vec;
                int left = node3->vec[x][y-1];
                node3->vec[x][y] = left;
                node3->vec[x][y-1] = 0;
                s->l = node3;
                node3->p = s;
                node3->dir = "Go Right";
                this->in.push_back(node3);
                b = this->comp(node3->vec);
                if(b==1)
                {
                    std::cout<<"Left"<<std::endl;
                    this->show(*node3);
                    break;
                }
            }
            if(s->dir != "Go Right" && y<2)
            {
                Node* node4 = new Node;
                node4->vec = s->vec;
                int right = node4->vec[x][y+1];
                node4->vec[x][y] = right;
                node4->vec[x][y+1] = 0;
                s->r = node4;
                node4->p = s;
                node4->dir = "Go Left";
                this->in.push_back(node4);
                b = this->comp(node4->vec);
                if(b==1)
                {
                    this->show(*node4);
                    break;
                }
            }
        }
        layer ++;
        if (b==1)
        {
            break;
        }
        if(layer == d + 1 && b==0)
        {
            std::cout<<"Sorry We Can`t Solve Your Puzzle"<<std::endl;
            for (size_t i = 0; i < 3; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    std::cout<<this->head->vec[i][j]<<" ";
                }
                std::cout<<std::endl;
                
            }
            break;
        }
    }   
}

bool Bfs::comp(std::vector<std::vector<int>> vec)
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
std::vector<int> Bfs::pos(std::vector<std::vector<int>> vec)
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
void Bfs::show(Node& node)
{
    std::vector<std::vector<int>> l;
    l.assign(node.vec.begin(),node.vec.end());
    this->out.push_front(l);
    this->guid.push_front(node.dir);
    while(node.p!=head)
    {
        l = {};
        node = std::move(*node.p);
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