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