typedef int intElementType;
struct intNode {
    intElementType Element; //contains Element of the previous intNode
    intNode* Next; //contains address of the next intNode
};
typedef intNode* intPosition; //assign intNode address to intPosition pointer
//intList contains Header-intNode address
typedef intPosition intList; //In essence, when we declare a intList, we are declare a Header intNode
void INSERT_intList(intElementType x, intPosition p, intList &L) {
    intPosition t = new intNode(); //declare and allocate a intNode to contain x
    t->Element = x; //put x to the intNode, in essence that x is p's element
    t->Next = p->Next; //assign (p+1)'s address to t->Next which is containing in p->Next
    p->Next = t; //assign t (a intNode address) to p->Next
}
intPosition LOCATE(intElementType x, intList L) {
    //Now we see L as a intPosition
    while (L->Next != NULL)
        if (L->Next->Element == x) return L;
        else L = L->Next;
    return L;
}
intElementType RETRIEVE(intPosition p, intList L) {
    if (p->Next != NULL)
        return p->Next->Element;
    std::cout << "intPosition Not Found!!!";
    return 0;
}
void DELETE_intList(intPosition p, intList &L) {
    //In essence, we're working on, p->Next = P->Next->Next;
    //But we need to delete the pointer that contain p->Next->Element;
    if (p->Next != NULL) {
        intPosition temp = p->Next;
        p->Next = temp->Next;
        delete temp;
    }
}
intPosition NEXT(intPosition p, intList L) {
    return p->Next;
}
intPosition PREVIOUS(intPosition p, intList L) {
    //See L as Header intNode
    while (L->Next != p)
        L = L->Next;
    return L;
}
intPosition FIRST(intList L) {
    return L;
}
bool EMPTY_intList(intList L) {
    return L->Next == NULL;
}
void MAKENULL_intList(intList &L) {
    //Now &L is &Header
    L = new intNode(); //allocate Header
    L->Next = NULL;
}
//Extra abstract function
intPosition ENDintList(intList L) {
    while (L->Next != NULL)
        L = L->Next;
    return L;
}
void READ_intList(intList &L) {
    int amount;
    intElementType x;
    std::cout << "Nhap so phan tu danh sach: ";
    std::cin >> amount;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << index + 1 << ">: ";
        std::cin >> x;
        INSERT_intList(x, FIRST(L), L);
    }
}
void PRINT_intList(intList L) {
    int amount = 0;
    intPosition temp = L;
    while (L->Next != NULL) {
        amount++;
        L = L->Next;
    }
    std::cout << "intList amount: " << amount << std::endl;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << (index + 1) << ">: "
        << temp->Next->Element << std::endl;
        temp = temp->Next;
    }
}