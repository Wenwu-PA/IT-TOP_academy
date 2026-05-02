#define MERETDD_CLASS_FINAL( line ) Test ## line
#define MERETDD_CLASS_RELAY( line ) MERETDD_CLASS_FINAL( line )
#define MERETDD_CLASS MERETDD_CLASS_RELAY( __LINE__ )

MERETDD_CLASS

/*

__LINE__ на строке вызова макроса равен 5

## склеивает Test и 5 в один токен Test5

Директивы # 0 ... — это служебная информация препроцессора

*/;