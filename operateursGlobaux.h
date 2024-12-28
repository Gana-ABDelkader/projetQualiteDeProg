#ifndef OPERATEURSGLOBAUX_H
#define OPERATEURSGLOBAUX_H

#include <iostream>

namespace fichiers
{

class caractereLabyrintheAmeliore1;
class caractereLabyrintheAmeliore2;

std::ostream& operator<<(std::ostream& ost, const caractereLabyrintheAmeliore1& labyr);
std::ostream& operator<<(std::ostream& ost, const caractereLabyrintheAmeliore2& labyr);

}

#endif // OPERATEURSGLOBAUX_H
