//Left Leaning Red-Black BSTs
//Members: Collin Beaird, Andrew DiBiase, Enoch Osamaye
//CSC 212

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ios>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>

class LLRB
{
    private:
        std::string key; //stores node values
        LLRB *L;
        LLRB *R;

        int repeats = 1;

        bool rLink;

        //void colorSwap() {red = !red;}

    public:
       LLRB(); //default constructor
        LLRB(std::string key);
        ~LLRB();

        friend class RedBlack; //can access private variables in LLRB
};

LLRB::LLRB()
{
    this->L = nullptr;
    this->R=nullptr;
}

LLRB::LLRB(std::string key)
{
    this->key = key;
    this->rLink = true;
    this->repeats = 1;
}

LLRB::~LLRB()
{

}

class RedBlack
{
    private:
        LLRB* rNode;

        LLRB* insertion(std::string key, LLRB* rNode);

        bool search(std::string key, LLRB* rNode);

        bool redLink(LLRB* n); //is link red?

        int height(LLRB* rNode);

        LLRB* rLeft(LLRB* rlNode);

        LLRB* rRight(LLRB* rrNode);

        void preOrder(LLRB* rNode, std::ostream& os);
        void inOrder(LLRB* rNode, std::ostream& os);
        void postOrder(LLRB* rNode, std::ostream& os);

        void Arnold(LLRB* rNode);


    public:

        RedBlack();
        RedBlack(std::string key);
       // ~RedBlack();

        ~RedBlack();

      void insertion(std::string key);

       int height();
       bool search(std::string key);

       void clear();

       void preOrder(std::ostream& os = std::cout);
       void inOrder(std::ostream& = std::cout);
       void postOrder(std::ostream& = std::cout);

};

RedBlack::RedBlack()
{
    this->rNode = nullptr;
}

RedBlack::RedBlack(std::string key)
{
    //std::cout << "before" << std::endl;
    this->rNode->key = rNode->key;
   //std::cout << "after" << std::endl;
}

RedBlack::~RedBlack()
{
    this->Arnold(this->rNode);
}

/////////////////////////
///PRIVATE FUNCTIONS
/////////////////////////

bool RedBlack::redLink(LLRB* n)
{
    //std::cout << "RB redlink private" << std::endl;
    if(n == NULL)
    {
        return false;
    }

    return n->rLink;
}


bool RedBlack::search(std::string key, LLRB* rNode)
{
    //std::cout << "RB search private" << std::endl;
    if (rNode == NULL)
    {
        return false;
    }

    if(key == rNode->key) //if key = root, we found the key we're looking for!
    {
        return true;
    }

    if (key < rNode->key) //if key is less than root, go left down the list
    {
        return this->search(key, rNode->L);
    }
    else //otherwise, go right
    {
        return this->search(key, rNode->R);
    }

}


LLRB* RedBlack::insertion(std::string key, LLRB* rNode)
{

    if(rNode == NULL)
    {
     //   std::cout << "if 1" << std::endl;
        return new LLRB(key); //base case, return new node as root
       // std::cout << "if 1 after" << std::endl;
    }
    if (key.compare(rNode->key) == 0) //tests for duplicates
    {
        //std::cout << "if 2" << std::endl;
         rNode->repeats++;
    }
    //std::cout<< "repeated nodes: " << repeats << std::endl;

    else if (key.compare(rNode->key) > 0)

    {
        // std::cout << "else if 1" << std::endl;
        rNode->R = insertion(key, rNode->R);

    }
    else
    {
        // std::cout << "else" << std::endl;
        rNode->L = insertion(key, rNode->L);
    }
    if(redLink(rNode->R)) // rotate left
    {
       // std::cout << "if 3" << std::endl;
        rNode = rLeft(rNode);
    }
    if(redLink(rNode->L) && redLink(rNode->L->R)) // rotate right
    {
        // std::cout << "if 4" << std::endl;
        rNode = rRight(rNode);
    }
    if(redLink(rNode->R) && redLink(rNode->L)) //swap colors
    {
        // std::cout << "if 5" << std::endl;

        //set both child links to black
        rNode->R->rLink = false;
        rNode->L->rLink = false;

        //set parent link to red
        rNode->rLink = true;
    }


    //std::cout << "RB insertion private end" << std::endl;
    return rNode;
}

LLRB* RedBlack::rLeft(LLRB* lrNode)
{
   // std::cout << "RB left private" << std::endl;
    //need variable to hold value to return
    LLRB* lr;

    //set new variable = root node which is to the right
    lr = lrNode->R;

    //root node that goes right is = root node that goes right which we want to go left
    lrNode->R = lrNode->R->L;

    //set variable rl going left = root node
    lr->L = lrNode;

    //new variable lr goes to red, set equal to lr going to red which would go left
    lr->rLink = lr->L->rLink;
    //set lr going to left which goes red to true, making red link
    lr->L->rLink = true;

    return lr;

}

int RedBlack::height(LLRB* rNode)
{
    //std::cout << "RB height private" << std::endl;
    if(rNode == NULL)
    {
        return -1;

    }

    int left = height(rNode->L);
    int right = height(rNode->R);

    return (left > right ? left + 1 : right + 1);
}

LLRB* RedBlack::rRight(LLRB* rrNode) //
{

   // std::cout << "RB rright private" << std::endl;
    //need variable to hold value to return
    LLRB* rr;

    //set rr = root node which is to the left
    rr = rrNode->L;

    //root node going to left is equal to root node going left then going right
    rrNode->L = rrNode->L->R;

    //rr going right is equal to rnode, which goes right
    rr->R = rrNode;

    //set rr to red, set it equal to rr going right which makes a redlink
    rr->rLink = rr->R->rLink;

    //sets redlink after rotation to true
    rr->R->rLink = true;


    return rr;
}

void RedBlack::preOrder(LLRB* rNode, std::ostream& os)
{
  //  std::cout << "RB preorder private" << std::endl;
    if (rNode == NULL)
    {
        return;
    }

    os << rNode->key << ":" << rNode->rLink << ", ";

    this->preOrder(rNode->L, os);

    this->preOrder(rNode->R, os);

    return;
}


void RedBlack::inOrder(LLRB* rNode, std::ostream& os)
{
  //  std::cout << "RB inorder private" << std::endl;
    if (rNode == NULL)
    {
        return;
    }

    this->inOrder(rNode->L, os);

    os << rNode->key << ":" << rNode->rLink << ", ";

    this->inOrder(rNode->R, os);

    return;
}


void RedBlack::postOrder(LLRB* rNode, std::ostream& os)
{
  //  std::cout << "RB postorder private" << std::endl;
    if (rNode == NULL)
    {
        return;
    }

    this->postOrder(rNode->L, os);

    this->postOrder(rNode->R, os);

    os << rNode->key << ":" << rNode->rLink << ", ";

    return;
}

void RedBlack::Arnold(LLRB* rNode)
{
  //  std::cout << "get to tha choppa" << std::endl;
    if(rNode == NULL)
    {
        return;
    }

    this->Arnold(rNode->L);

    this->Arnold(rNode->R);

    delete rNode->L;

    delete rNode->R;
}

////////////////////////////////////////////////////////////////////////////////////////
//PUBLIC FUNCTIONS///////////////////////////////////////////////////////////////////////
//////////////



int RedBlack::height()
{
   // std::cout << "public RB height" << std::endl;
    return this->height(this->rNode);
}

bool RedBlack::search(std::string key)
{
   // std::cout << "public RB search" << std::endl;
    return this->search(key, this->rNode);
}

void RedBlack::insertion(std::string key) // calls insertion function recursively
{
   // std::cout << "public RB insertion" << std::endl;
    insertion(key, this->rNode);

    if(this->rNode->rLink == true)
    {
        this->rNode->rLink = false;
    }
}

void RedBlack::preOrder(std::ostream& os)
{
   // std::cout << "public RB preorder" << std::endl;
    this->preOrder(this->rNode, os);

    os << "\n";
}

void RedBlack::inOrder(std::ostream& os)
{
      //  std::cout << "public RB inorder" << std::endl;
    this->inOrder(this->rNode, os);

    os << "\n";
}

void RedBlack::postOrder(std::ostream& os)
{
   // std::cout << "RB postorder" << std::endl;
    this->postOrder(this->rNode, os);

    os << "\n";
}

void RedBlack::clear() //recursively calls the clear function above
{
  //  std::cout << "public RB clear" << std::endl;
    this->Arnold(this->rNode);

    this->rNode = nullptr;
}




///////MAIN FUNCTION/////


int main(int argc, char *argv[])
{

    int choose;
    //std::vector<std::string> Key;

    char* fname = argv[1];

    std::ifstream src(fname);
    std::vector<std::string> vec;

    std::string file;

    while (src >> file)
    {
        vec.push_back(file);
    }
    int linecount = 0;



    //displays text file in a row, removes any unnecessary spaces between words
    for (std::vector<std::string>::iterator it=vec.begin(); it!=vec.end(); ++it) {
        if (linecount = 0) {
            std::cout << *it;
            linecount++;
        }
        else {
            std::cout << " " << *it;
        }

    }
    std::cout << std::endl;

    int fileSize = vec.size();
    std::cout << fileSize << std::endl;

    std::string rb = vec[0];
    std::cout << rb << std::endl;
   RedBlack redBlack(rb);

    for (std::vector<std::string>::iterator it=vec.begin(); it!=vec.end(); ++it)
    {
        redBlack.insertion(*it);

    }


}
