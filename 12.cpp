#include <iostream>
#include "LIST12.h"

int main() {
    List L;
    ElementType x, y;
    Position* Dual;
    MAKENULL_LIST(L);
    READ_LIST(L);
    REDUCE_FRACTION(L);
    PRINT_LIST(L);
    Dual = SPECIAL_FUNC(L);
    if (*(Dual + 0) != NULL) {
        x = RETRIEVE(*(Dual + 0), L);
        y = RETRIEVE(*(Dual + 1), L);
        std::cout << "Cap phan so co tich bang nhau la: "
        << x.Numerator << "/" << x.Denominator << " x " 
        << y.Numerator << "/" << y.Denominator << "\n";
    }
    else std::cout << "Khong co phan so nao bang nhau\n";
}