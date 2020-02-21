#ifndef ECE309_EXAMPLES_SPR20_POKEMON_H
#define ECE309_EXAMPLES_SPR20_POKEMON_H

#include <string>
#include <fstream>
#include <iostream>
using std::ostream;
using std::istream;

class Pokemon {
public:
    int id;   // unique id for each Pokemon
    std::string name;  // name of Pokemon class
    std::string type;  // type of Pokemon (e.g., Ground)
    std::string type2;  // secondary type (could be "NONE")
    int maxCP;    // max amount of damage inflicted by this Pokemon class
    int maxHP;    // max amount of damage suffered by this Pokemon class
    // construct using data
    Pokemon(int idnum, std::string& n, std::string& t, std::string& t2, int cp, int hp) :
        id(idnum), name(n), type(t), type2(t2), maxCP(cp), maxHP(hp) {}
    // construct by reading from file
    explicit Pokemon(std::ifstream& in) {
        in >> *this;
    }
    friend ostream& operator<<(ostream& out, const Pokemon& p);
    friend istream& operator>>(istream& in, Pokemon& p);
};


#endif //ECE309_EXAMPLES_SPR20_POKEMON_H
