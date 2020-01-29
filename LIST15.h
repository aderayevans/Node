#include <iostream>
#include <string>
typedef short ElementType;
struct Node {
    ElementType Element;
    Node* Next;
};
typedef Node* Position;
typedef Position List;
void INSERT_LIST(ElementType x, Position p, List &L) {
    Position t = new Node();
    t->Element = x;
    t->Next = p->Next;
    p->Next = t;
}
Position LOCATE(ElementType x, List L) {
    while (L->Next != NULL) {
        if (L->Next->Element == x) return L;
        L = L->Next;
    }
    std::cout << "Location Not found";
    return L;
}
ElementType RETRIEVE(Position p, List L) {
    if (p->Next != NULL) {
        return p->Next->Element;
    }
    std::cout << "Element Not found";
    return 0;
}
void DELETE_LIST(Position p, List &L) {
    if (p->Next != NULL) {
        Position t = p->Next;
        p->Next = t->Next;
        delete t;
    }
}
Position NEXT(Position p, List L) { return L->Next; }
Position PREVIOUS(Position p, List L) {
    while (L->Next != p) L = L->Next;
    return L;
}
Position FIRST(List L) { return L; }
bool EMPTY_LIST(List L) {
    if (L->Next == NULL) return true;
    return false;
}
void MAKENULL_LIST(List &L) {
    L = new Node();
    L->Next = NULL; 
}
//Extra abstract function
Position ENDLIST(List L) {
    while (L->Next != NULL) L = L->Next;
    return L;
}
void READ_LIST(List &L) {
    std::string BigGuy;
    std::getline (std::cin, BigGuy);
    for (int index = 0; index < BigGuy.length(); index++) {
        int x = BigGuy[index] - 48;
        INSERT_LIST(x, FIRST(L), L);
    }
}
void PRINT_LIST(List L) {
    while (L->Next != NULL) {
        std::cout << L->Next->Element;
        L = L->Next;
    }
}