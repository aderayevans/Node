#include <iostream>
struct Polinomial {
    int number;
    int power;
};
typedef Polinomial ElementType;
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
    while (L->Next != NULL) {
        if (L->Next->Element.number == x.number && L->Next->Element.power == x.power) return L;
        L = L->Next;
    }
    return L;
}
ElementType RETRIEVE(Position p, List L) {
    if (p->Next != NULL) {
        return p->Next->Element;
    }
    ElementType x;
    x.number = 0;
    x.power = 1;
    return x;
}
void DELETE_LIST(Position p, List &L) {
    if (p->Next != NULL) {
        Position temp = p->Next;
        p->Next = temp->Next;
        delete temp;
    }
}
Position NEXT(Position p, List L) {
    return p = p->Next;
}
Position PREVIOUS(Position p, List L) {
    while(L->Next != p) L = L->Next;
    return L;
}
Position FIRST(List L) { return L; }
bool EMPTY_LIST(List L) {
    if (L->Next == NULL) return true;
    else return false;
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
    int quantity;
    ElementType x;
    std::cout << "A quantity of list: ";
    std::cin >> quantity;
    for (int index = 0; index < quantity; index++) {
        std::cout << "/<" << index + 1 << ">:\n";
        std::cout << "Number: ";
        std::cin >> x.number;
        if (x.number == 0);
        else {
            std::cout << "Power: ";
            std::cin >> x.power;
            INSERT_LIST(x, ENDLIST(L), L);
        }
    }
}
void PRINT_LIST(List L) {
    int quantity = 0;
    Position temp = L;
    while (L->Next != NULL) {
        quantity++;
        L = L->Next;
    }
    std::cout << "The number of List member: " << quantity << "\n";
    for (int index = 0; index < quantity; index++) {
        std::cout << "/<" << index + 1 << ">:\n";
        std::cout << "Number: " << temp->Next->Element.number << "\n";
        std::cout << "Power: " << temp->Next->Element.power << "\n";
        temp = temp->Next;
    }
}