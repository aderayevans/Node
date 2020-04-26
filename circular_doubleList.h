typedef int ElementType;
struct Node {
    ElementType Element;
    Node* Next;
    Node* Prev;
};
typedef Node* Position;
struct List {
    Position Header;
};
void INSERT_LIST(ElementType x, Position p, List &L);
Position LOCATE(ElementType x, List L);
ElementType RETRIEVE(Position p, List L);
void DELETE_LIST(Position p, List &L);
Position NEXT(Position p, List L);
Position PREVIOUS(Position p, List L);
Position FIRST(List L);
bool EMPTY_LIST(List L);
void MAKENULL_LIST(List &L);
//Extra abstract function
Position ENDLIST(List L);
void READ_LIST(List &L);
void PRINT_LIST(List L);

void INSERT_LIST(ElementType x, Position p, List &L) {
    Position temp = new Node();
    temp->Element = x;
    temp->Next = p->Next;
    temp->Prev = p;
    p->Next->Prev = temp;
    p->Next = temp;
}
Position LOCATE(ElementType x, List L) {
    if (EMPTY_LIST(L)) return NULL;
    Position right = L.Header;
    Position left = L.Header->Prev;
    do {
        if (right->Next->Element == x) return right;
        else if (left->Element == x) return left->Prev;
        else {
            right = right->Next;
            left = left->Prev;
        }
    } while (right != left);
    return NULL;
}
ElementType RETRIEVE(Position p, List L) {
    return p->Next->Element;
}
void DELETE_LIST(Position p, List &L) {
    Position t = p->Next;
    p->Next->Next->Prev = p;
    p->Next = p->Next->Next;
    delete t;
}
Position NEXT(Position p, List L) {
    return p->Next;
}
Position PREVIOUS(Position p, List L) {
    return p->Prev;
}
Position FIRST(List L) {
    return L.Header;
}
bool EMPTY_LIST(List L) {
    return L.Header == L.Header->Next;
}
void MAKENULL_LIST(List &L) {
    L.Header = new Node();
    L.Header->Next = L.Header;
    L.Header->Prev = L.Header;
}
//Extra abstract function
Position ENDLIST(List L) {
    return L.Header->Prev;
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
    Position temp = L.Header;
    int index = 0;
    while (temp->Next != L.Header) {
        std::cout << "/<" << index + 1 << ">: " << temp->Next->Element << "\n";
        temp = temp->Next;
        index++;
    }
}