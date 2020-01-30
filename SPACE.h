#include <iostream>
#define Maxlength 256
#define Null -1
typedef char ElementType;
struct Node {
    ElementType Element;
    int Next;
};
typedef int Position;
typedef Position List;
Node Space[Maxlength];
int Available;
void Initialize() {
    for (int index = 0; index < Maxlength - 1; index++)
        Space[index].Next = index + 1;
    Space[Maxlength - 1].Next = Null;
    Available = 0;
}
bool Move(int& p, int& q) {      //pointer p is pointing to Node P, pointer q is pointing to Node Q
    if (p != Null) {            //If address in pointer p is not Null (-1)                   
        int temp = q;           //Create pointer temp contain address of Node Q (address was contained in q)
        q = p;                  //Pointer q is now contain the same address as pointer p (P)
        p = Space[q].Next;      //Pointer p is now contain the address after P (p->Next)
        Space[q].Next = temp;   //Let The Node (P).Next contain address to temp (address of Node Q at beginning)
        return true;
    }
    return false;
}

void INSERT_LIST(ElementType x, Position p, List &L) {
    if (p == Null) {
        if (Move(Available, L))
            Space[L].Element = x;
        else std::cout << "No more blank memory\n";
        std::cout << "Create L: " << "[ " << L << " | " << Space[L].Element << " | " << Space[L].Next << " ]\n";
    }
    else {
        if (Move(Available, Space[p].Next))
            Space[Space[p].Next].Element = x;
        else std::cout << "No more blank memory\n";
    }
}
Position LOCATE(ElementType x, List L);
ElementType RETRIEVE(Position p, List L);
void DELETE_LIST(Position p, List &L) {
    if (p == Null) {
        if (!Move(L, Available))
            std::cout << "Error!!!";
    }
    else
        if (!Move(Space[p].Next, Available))
            std::cout << "Error!!!";
}
Position NEXT(Position p, List L);
Position PREVIOUS(Position p, List L);
Position FIRST(List L);
bool EMPTY_LIST(List L);
void MAKENULL_LIST(List &L) {
    L = Null;
}
//Extra abstract function
Position ENDLIST(List L) {
    while (L != Null) L = Space[L].Next;
    return L;
}
void READ_LIST(List &L);
void PRINT_LIST(List L) {
    while (L != Null) {
        std::cout << "[ " << L << " | " << Space[L].Element << " | " << Space[L].Next << " ]\n";
        L = Space[L].Next;
    }
}