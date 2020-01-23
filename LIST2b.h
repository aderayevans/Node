typedef int ElementType;
struct Node {
    ElementType Element; //contains Element of the previous Node
    Node* Next; //contains address of the next Node
};
typedef Node* Position; //assign Node address to Position pointer
//List contains Header-Node address
typedef Position List; //In essence, when we declare a list, we are declare a Header Node
void INSERT_LIST(ElementType x, Position p, List &L) {
    Position t = new Node(); //declare and allocate a Node to contain x
    t->Element = x; //put x to the Node, in essence that x is p's element
    t->Next = p->Next; //assign (p+1)'s address to t->Next which is containing in p->Next
    p->Next = t; //assign t (a Node address) to p->Next
}
Position LOCATE(ElementType x, List L) {
    //Now we see L as a position
    while (L->Next != NULL)
        if (L->Next->Element == x) return L;
        else L = L->Next;
    return L;
}
ElementType RETRIEVE(Position p, List L) {
    return p->Next->Element;
}
void DELETE_LIST(Position p, List &L) {
    //In essence, we're working on, p->Next = P->Next->Next;
    //But we need to delete the pointer that contain p->Next->Element;
    Position temp;
    if (p->Next != NULL) {
        temp = p->Next;
        p->Next = temp->Next;
        delete temp;
    }
}
Position NEXT(Position p, List L) {
    return p->Next;
}
Position PREVIOUS(Position p, List L) {
    //See L as Header Node
    while (L->Next != p)
        L = L->Next;
    return L;
}
Position FIRST(List L) {
    return L;
}
bool EMPTY_LIST(List L) {
    return L->Next == NULL;
}
void MAKENULL_LIST(List &L) {
    //Now &L is &Header
    L = new Node(); //allocate Header
    L->Next = NULL;
}
//Extra abstract function
Position ENDLIST(List L) {
    while (L->Next != NULL)
        L = L->Next;
    return L;
}
void READ_LIST(List &L) {
    int amount;
    ElementType x;
    std::cout << "Nhap so phan tu danh sach: ";
    std::cin >> amount;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << index + 1 << ">: ";
        std::cin >> x;
        INSERT_LIST(x, FIRST(L), L);
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
        std::cout << "/<" << (index + 1) << ">: "
        << temp->Next->Element << std::endl;
        temp = temp->Next;
    }
}