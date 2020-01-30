#include <iostream>
typedef int ElementType;
struct Node {
    ElementType Element;
    Node* Next;
};
typedef Node* Position;
typedef Position List;
void INSERT_LIST(ElementType x, Position p, List &L) {
    Position temp = new Node();
    temp->Element = x;
    temp->Next = p->Next;
    p->Next = temp;
}
Position LOCATE(ElementType x, List L) {
    Position temp = L;
    while (L->Next != temp) {
        if (L->Next->Element == x) return L;
        L = L->Next;
    }
    std::cout << "Can NOT Locate, Element Not Found\n";
    return L;
}
ElementType RETRIEVE(Position p, List L) {
    Position temp = L;
    if (p->Next != temp)
        return p->Next->Element;
    else {
        return 0;
        std::cout << "Can NOT Retrieve, Position Not Found\n";
    }
}
void DELETE_LIST(Position p, List &L) {
    Position tempL = L;
    if (p->Next != tempL) {
        Position temp = p->Next;
        p->Next = temp->Next;
        delete temp;
    }
    else std::cout << "Can NOT Delete, Element Not Found\n";
}
Position NEXT(Position p, List L) {
    return p->Next;
}
Position PREVIOUS(Position p, List L) {
    while (L->Next != p) L = L->Next;
    return L;
}
Position FIRST(List L) {
    return L;
}
bool EMPTY_LIST(List L) {
    if (L->Next == L) return true;
    else return false;
}
void MAKENULL_LIST(List &L) {
    L = new Node();
    L->Next = L;
}
//Extra abstract function
Position ENDLIST(List L) {
    Position temp = L;
    while (L->Next != temp) L = L->Next;
    return L;
}
void READ_LIST(List &L) {
    int number;
    int x;
    std::cout << "Number of member: ";
    std::cin >> number;
    for (int index = 0; index < number; index++) {
        std::cout << "/<" << index + 1 << ">: ";
        std::cin >> x;
        INSERT_LIST(x, ENDLIST(L), L);
    }
}
void PRINT_LIST(List L) {
    Position temp = L;
    int index = 0;
    while (L->Next != temp) {
        std::cout << "/<" << index + 1 << ">: " << L->Next->Element << "\n";
        L = L->Next;
        index++;
    }
}