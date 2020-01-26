#include <iostream>
#include "LIST2b.h"
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
intList PrimeNumber(int n) {
    intList Primes;
    MAKENULL_intList(Primes);
    INSERT_intList(1, ENDintList(Primes), Primes);
    while (n>1) {
		if (n%2 == 0) {
			n = n/2;
			INSERT_intList(2, ENDintList(Primes), Primes);
		}
		else if (n%3 == 0) {
			n = n/3;
			INSERT_intList(3, ENDintList(Primes), Primes);
		}	
		else if (n%5 == 0) {
			n = n/5;
			INSERT_intList(5, ENDintList(Primes), Primes);
		}	
		else if (n%7 == 0) {
			n = n/7;
			INSERT_intList(7, ENDintList(Primes), Primes);
		}
        else
			INSERT_intList(n, ENDintList(Primes), Primes);
	}
    return Primes;
}
int GCD(int number1, int number2){
    intList L1 = PrimeNumber(number1);
    intList L2 = PrimeNumber(number2);
    int result = 1;
    while (L1->Next != NULL && L2->Next != NULL) {
        if (L1->Next->Element == L2->Next->Element) {
            result = result*L1->Next->Element;
            L1 = L1->Next;
            L2 = L2->Next;
        }
        else if (L1->Next->Element > L2->Next->Element) {
            L2 = L2->Next;
        }
        else L1 = L1->Next;
    }
    return result;
}
void REDUCE_FRACTION(List &L) {
    Position p = L;
    int gcd;
    while (p->Next != NULL) {
        if (p->Next->Element.Numerator == 0) {
            p->Next->Element.Numerator = 0;
        }
        else {
            gcd = GCD(p->Next->Element.Numerator, p->Next->Element.Denominator);
            p->Next->Element.Numerator = p->Next->Element.Numerator/gcd;
            p->Next->Element.Denominator = p->Next->Element.Denominator/gcd;
        }
        p = p->Next;
    }
}
void DEL_BIGGER_NUM(List &L) {
    Position p = L;
    while (p->Next != NULL) {
        if (p->Next->Element.Numerator > p->Next->Element.Denominator) DELETE_LIST(p, L);
        else p = p->Next;
    }
}
Position* SPECIAL_FUNC(List L) {
    Position* Dual = new Position[2];
    *(Dual + 0) = new Node();
    *(Dual + 1) = new Node();
    
    Position first = L;
    Position second = L->Next;
    int done = 0;

    while (first->Next != NULL) {
        while (second->Next != NULL) {
            if (first->Next->Element.Numerator*second->Next->Element.Numerator == first->Next->Element.Denominator*second->Next->Element.Denominator) {
                *(Dual + 0) = first;
                *(Dual + 1) = second;
                done = 1;
                break;
            }
            second = second->Next;
        }
        if (done == 1) break;
        first = first->Next;
        second = first->Next;
    }
    if (done == 0) {
        *(Dual + 0) = NULL;
        *(Dual + 1) = NULL;
    }
    return Dual;
}