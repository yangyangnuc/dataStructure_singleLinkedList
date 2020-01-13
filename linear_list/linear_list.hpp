#ifndef LINEAR_LIST_HPP
#define LINEAR_LIST_HPP
#include <string>
#include <iostream>
#include <exception>

class Linear_List_Node
{
public:
    std::string stationName;
    Linear_List_Node* next;     // single linearList

    Linear_List_Node()
    {
        this->next = nullptr;
        stationName = "";
    }
};


class Linear_List // 单链表类
{
public:
    Linear_List();
    ~Linear_List();

    void initLinearList();
    void destroyLinearList();
    void clearLinearList();
    bool isEmpty();
    int length();
    void getElement(int i, Linear_List_Node* &ele);
    int locateElement(std::string s);
    void priorElement(Linear_List_Node cur_node, Linear_List_Node priorNode);
    void nextElement(Linear_List_Node cur_node, Linear_List_Node nextNode);
    void insertElement(int indexx, std::string s);
    void deleteElement(std::string s );
    void traverse(void* pFunction);

    // advanced methods
    void converseLinkedList();
    void hasCircle();
    void circlelength();
    void getCircleDoor();
    void findBackwardNode();
    void merge2sortedLists();
    void deleteDuplicateNode();
    void firstSharingNodeIn2Lists();



    int m_nodeNumber = 10;
    std::string m_originalData[10] = {"yueJiGongYuan","wuyigongyuan","shizhongxinyiyuan","longhaixilu",
                                     "tonghuai","houhelu","qiliyan","shidierrenminyiyuan","jingguangnanlu",
                                     "fengzhuang"};
    Linear_List_Node* m_head = new Linear_List_Node;
    Linear_List_Node* m_converseHead = new Linear_List_Node;

};

Linear_List::Linear_List()
{
    std::cout << "linear list, linked node form" << std::endl;
}

void Linear_List::initLinearList()
{
    m_head->next = 0   ;


    // 思路是 for循环；每次循环 创建一个结点，并插入到表头
    for (auto i=0;i<m_nodeNumber;i++)
    {
        Linear_List_Node* newNode = new Linear_List_Node;
        newNode->stationName = m_originalData[i];
        newNode->next = m_head->next;
        m_head->next = newNode;
    }

    std::cout << "linear node list initialized..." << std::endl;
}



Linear_List::~Linear_List()
{

}


void Linear_List::traverse(void* pFunction)
{

    if(m_head == nullptr)
    {
        std::cout << "list not existing or destroyed" << std::endl;
        return;
    }
    Linear_List_Node* p1 = m_head->next;
    while(p1 != nullptr)
    {
        std::cout << p1->stationName << std::endl;
        p1 = p1->next;
    }

    delete  p1;
    std::cout << "linear node list traversed..............................." << std::endl;

}

void Linear_List::clearLinearList() // 只保留头结点的空间，其他结点全部释放掉，以后还可以插入new node
{
    Linear_List_Node* p1 = nullptr/*,*p2 = nullptr*/;
    if(m_head->next != nullptr)
    {
        p1 = m_head->next;

    }
    else
    {
        std::cout << "linear node list is empty..." << std::endl;
        return;
    }

    try
    {
        while (p1 != nullptr)
        {
            m_head->next = p1->next;
            delete p1;
            p1 = m_head->next;
        }
        m_head->next = nullptr;
        std::cout << "linear node list cleared..." << std::endl;

    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }

}

void Linear_List::destroyLinearList() // 头结点和其他结点全部释放掉，以后new node都不能插入了，链表不能使用了
{

    clearLinearList();

    // 把头结点清空
    delete m_head;
    m_head = nullptr;
    std::cout << "linear node list destroyed..." << std::endl;

}

bool Linear_List::isEmpty()
{
    if(m_head->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Linear_List::length()
{
    if(m_head == nullptr)
    {
        std::cout << "list not existing or destroyed" << std::endl;
        return -1;
    }
    Linear_List_Node* p1 = m_head->next;
    int len = 0;
    while(p1 != nullptr)
    {
//        std::cout << p1->stationName << std::endl;
        len++;
        p1 = p1->next;
    }

    delete  p1;

    return len;
//    std::cout << "linear node list traversed..." << std::endl;

}

void Linear_List::getElement(int i, Linear_List_Node* &ele)
{
    if(isEmpty())
    {
        std::cout << "error, list empty " << std::endl;
        return;
    }



    int cnt=0;
    Linear_List_Node* pTemp = new Linear_List_Node;
    pTemp = m_head->next;
    do
    {
        cnt++;

        if(cnt == i)
        {
            ele = pTemp;
            std::cout << ele->stationName << std::endl;

        }


    }while (pTemp = pTemp->next) ;
}

int Linear_List::locateElement(std::string s)
{
    if(m_head == nullptr)
    {
        std::cout << "list not existing or destroyed" << std::endl;
        return -1;
    }
    Linear_List_Node* p1 = m_head->next;
    int idx = 0;
    while(p1 != nullptr)
    {
//        std::cout << p1->stationName << std::endl;
        idx++;
        if(p1->stationName == s)
        {
            return idx;
        }
        p1 = p1->next;
    }

    delete  p1;

    return -1;
}

void Linear_List::insertElement(int indexx, std::string s)
{
    Linear_List_Node* p1 = m_head->next;
    int idx = 0;
    while ( p1 != nullptr)
    {
        if(idx == indexx)
        {
            Linear_List_Node* p2 = new Linear_List_Node;
            p2->stationName = s;
            p2->next = p1->next;
            p1->next = p2;

        }
        idx ++;
        p1 = p1->next;

    }

    delete p1;
    std::cout << "node inserted-------------------------" << std::endl;

}

void Linear_List::deleteElement( std::string s)
{
    int idx = 0;
    Linear_List_Node* p1 = new Linear_List_Node, *p2 = nullptr;
    p1 = m_head->next;
    while (p1->next != nullptr)
    {
        if(p1->stationName == s)
        {
            p2 = p1->next;
            p1->next = p1->next->next;
            delete p2;

        }
        p1 = p1->next;
        idx ++;

    }

    p1 = nullptr;
    p2 = nullptr;
    std::cout << "node deleted------------------------" << std::endl;

}

void Linear_List::converseLinkedList()
{
    // 法1 就地反转法，用这个实现
    // 法2 再建立一个链表，头结点插入一遍，就反序了


    // 就地反转法
    Linear_List_Node *pCur = new Linear_List_Node,*pPrev = new Linear_List_Node, *conversedHead= new Linear_List_Node;
    conversedHead->next = m_head->next;
    pCur = conversedHead->next->next;
    pPrev = m_head->next;

    while (pCur != nullptr)
    {
        pPrev->next = pCur->next; // 将第一个结点的next指向改为下一个原序结点
        pCur->next = conversedHead->next; // 改变当前结点的指向为原序中的parent

        conversedHead->next = pCur; // 反序头结点指向当前结点，以备后用
        pCur = pPrev->next; // 下一个需要改变指向的结点给到当前结点

        int a=0;
    }
    m_converseHead->next = conversedHead;
    m_head->next = conversedHead;

}





#endif // LINEAR_LIST_HPP
