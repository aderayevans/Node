#include <iostream>
#include "LIST12.h"

int main() {
    List L;
    ElementType x;
    x.Numerator = 5;
    x.Denominator = 6;
    MAKENULL_LIST(L);
    READ_LIST(L);
    PRINT_LIST(L);
    std::cout << "Phan tu (tu so) " << RETRIEVE(LOCATE(x, L), L).Numerator << "\n";
    std::cout << "Phan tu (mau so) " << RETRIEVE(LOCATE(x, L), L).Denominator << "\n";
    std::cout << "Deleting..\n";
    DELETE_LIST(LOCATE(x, L), L);
    PRINT_LIST(L);
}