#include <iostream>
#include "circular_doubleList.h"

using namespace std;
int main() {
    List L;
    MAKENULL_LIST(L);
    READ_LIST(L);
    PRINT_LIST(L);
    INSERT_LIST(11, LOCATE(RETRIEVE(LOCATE(6, L), L), L), L);
    PRINT_LIST(L);
}