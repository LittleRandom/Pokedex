#ifndef ECE309_EXAMPLES_SPR20_POKEDEX_H
#define ECE309_EXAMPLES_SPR20_POKEDEX_H

#include "Pokemon.h"
#include <list>
#include <vector>
#include <cstdlib>
#include <list>

using namespace std;

class Pokedex {
private:
    list<Pokemon *> PokemonList;
    vector<Pokemon*> TypeList;

    bool type_sort_criteria(const Pokemon &a,const Pokemon& b);
public:
    explicit Pokedex(const char *filename);
    Pokemon * findByName(std::string name) const;
    std::list<const Pokemon*> findByType(std::string type) const;
    Pokemon* findByIndex(int index) const;
    void printPokemonData(const Pokemon *p)const;
    void printAllPokemonData(void);
    void printPokemonList(list<const Pokemon *> typeList);
    void easteregg();
    bool findName(string str) const;
    bool findType(string str) const;
};


#endif //ECE309_EXAMPLES_SPR20_POKEDEX_H
