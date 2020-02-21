#include <iostream>
using std::ostream;
using std::istream;
#include "Pokemon.h"

ostream& operator<<(ostream& out, const Pokemon& p) {
    out << '[' << p.id << "] ";
    out << p.name << " ";
    out << '(' << p.type;
    if (p.type2 != "NONE") out << "," << p.type2;
    out << ") ";
    out << "CP = " << p.maxCP << " HP = " << p.maxHP;
    return out;
}

istream& operator>>(istream& in, Pokemon& p) {
    in >> p.id >> p.name >> p.type >> p.type2 >> p.maxCP >> p.maxHP;
    return in;
}

