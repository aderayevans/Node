#include <iostream>
#include "LIST12.h"
#include "LIST2b.h"

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
    PRINT_intList(Primes);
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
int main() {
    List L;
    ElementType x;
    MAKENULL_LIST(L);
    READ_LIST(L);
    PRINT_LIST(L);
    REDUCE_FRACTION(L);
    PRINT_LIST(L);
}