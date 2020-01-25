#include <iostream>
struct Fraction { //Phan so
    int Numerator; //Tu so
    int Denominator; //Mau so
};
typedef Fraction ElementType;
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
        if (L->Next->Element.Numerator == x.Numerator && L->Next->Element.Denominator == x.Denominator) return L;
        L = L->Next;
    }
    return L;
}
ElementType RETRIEVE(Position p, List L) {
    if (p->Next != NULL)
        return p->Next->Element;
    ElementType x;
    x.Numerator = 1;
    x.Denominator = 1;
    std::cout << "Position Not Found!!!";
    return x;
}
void DELETE_LIST(Position p, List &L) {
    if (p->Next != NULL) {
        Position temp = p->Next;
        p->Next = temp->Next;
        delete temp;
    }
}
Position NEXT(Position p, List L) { return p->Next; }
Position PREVIOUS(Position p, List L) {
    while (L->Next != p) L = L->Next;
    return L;
}
Position FIRST(List L) { return L; }
bool EMPTY_LIST(List L) { return L->Next == NULL; }
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
    int amount;
    int tempDen;
    ElementType x;
    std::cout << "List amount: ";
    std::cin >> amount;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << index + 1 << ">:\n";
        while (true) {
            std::cout << "Numerator: "; std::cin >> x.Numerator;
            std::cout << "Denominator: "; std::cin >> tempDen;
            if (tempDen != 0) {
                x.Denominator = tempDen;
                break;
            }
            else {
                std::cout << "ValueError!!!\nThe denominator CANNOT have the value zero.\n";
            }
        }
        INSERT_LIST(x, ENDLIST(L), L);
    }
}
void PRINT_LIST(List L) {
    int amount = 0;
    Position temp = L;
    while (L->Next != NULL) {
        amount++;
        L = L->Next;
    }
    std::cout << "List amount: " << amount << std::endl;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << (index + 1) << ">: ";
        std::cout << temp->Next->Element.Numerator;
        std::cout << "/" << temp->Next->Element.Denominator;
        std::cout << std::endl;
        temp = temp->Next;
    }
}