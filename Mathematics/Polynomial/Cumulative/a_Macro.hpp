// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/a_Macro.hpp

#pragma once
#define DF_OF_PROD(RECURSION,UNIT,APPLY)if(f.empty()){f.push_back(UNIT);}if(f.SZ()== 1){RE f.front();}auto IT = f.BE(),EN = f.EN();WH(IT != EN){T& t = *IT;IT++;if(IT != EN){APPLY;IT = f.erase(IT);}}RE RECURSION;
#define EXPRESSION1_FOR_RATIONAL_SUM {PO<T>::zero(),PO<T>::one()}
#define EXPRESSION2_FOR_RATIONAL_SUM {t.first * itr->second + t.second * itr->first,t.second * itr->second}
#define EXPRESSION3_FOR_RATIONAL_SUM {TRPO<T>(),TRPO<T>(1,PO<T>::one())}
