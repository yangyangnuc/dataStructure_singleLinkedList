#include <QCoreApplication>
#include "linear_list.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Linear_List i1;
    i1.initLinearList();
    i1.traverse(nullptr);

//    Linear_List_Node* p1 = new Linear_List_Node;
//    i1.getElement(10, p1);
//    std::cout << p1->stationName << std::endl;
//    delete  p1;

//    i1.insertElement(5,"linshi");
//    i1.traverse(nullptr);

//    i1.deleteElement("linshi");
//    i1.traverse(nullptr);

//    i1.clearLinearList();
//    i1.traverse(nullptr);

//    i1.destroyLinearList();
//    i1.traverse(nullptr);

    i1.converseLinkedList();
    i1.traverse(nullptr);



    return a.exec();
}
