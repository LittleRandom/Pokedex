#include "Pokedex.h"
#include "Pokemon.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

Pokedex::Pokedex(const char *filename) {
    std::ifstream Pokedex_lib;
    Pokedex_lib.open(filename);


    int idnum, maxCP, maxHP;
    string name, type1, type2;

    while(!Pokedex_lib.eof()){
        Pokedex_lib >> idnum;
        Pokedex_lib >> name;
        Pokedex_lib >> type1;
        Pokedex_lib >> type2;
        Pokedex_lib >> maxCP;
        Pokedex_lib >> maxHP;
        auto *newPokemon = new Pokemon(idnum,name,type1,type2,maxCP,maxHP);
        if(PokemonList.empty()){
            PokemonList.push_back(newPokemon);
        }
        else {
            for (auto iter = begin(PokemonList); iter != end(PokemonList); iter++) {
                if(PokemonList.back()->name < newPokemon->name) {
                    PokemonList.push_back(newPokemon);
                    break;
                }
                else if ((*iter)->name > newPokemon->name) {
                    PokemonList.insert(iter, newPokemon);
                    break;
                }
            }
        }
    }
    Pokedex_lib.close();
}


Pokemon* Pokedex::findByName(std::string name) const {
    string newName = name;
    if(name[0] > 90){
        newName[0] = name[0] - 32;
    }
    for(auto iter = begin(PokemonList); iter != end(PokemonList); ++ iter ){
        if((*iter)->name == newName){
            return *(iter);
        }
    }
    return nullptr;
}

std::list<const Pokemon *> Pokedex::findByType(std::string type) const {
    list<const Pokemon *> PokemonType;
    if(type == "NONE") return std::list<const Pokemon*>(PokemonType);
    for(auto iter = begin(PokemonList); iter != end(PokemonList); iter ++){
        if(((*iter)->type == type)||((*iter)->type2 == type)){
            PokemonType.push_back(*iter);
        }
    }
    return std::list<const Pokemon *>(PokemonType);
}

Pokemon* Pokedex::findByIndex(int index) const {
    for(auto iter = begin(PokemonList); iter!= end(PokemonList); ++ iter) {
        if((*iter)->id==index){
            return (*iter);
        }
    }
    return nullptr;
}

void Pokedex::printPokemonData(const Pokemon *p) const {
    cout << "ID: " << int(p->id) << endl;
    cout << "Name: " << p->name << endl;
    cout << "Type: " << p->type << endl;
    if(p->type2 != "NONE") cout << "Type2: " << p->type2 << endl;
    cout << "maxCP: " << p->maxCP << endl;
    cout << "maxHP: " << p->maxHP << endl;
}

void Pokedex::printAllPokemonData(void){
    for(auto iter = begin(PokemonList); iter != end(PokemonList); iter++){
        printPokemonData(*iter);
    }
}

void Pokedex:: printPokemonList(list<const Pokemon *> typeList){
    for(auto iter = begin(typeList); iter !=  end(typeList); iter++){
        printPokemonData(*iter);
    }
}

void Pokedex::easteregg() {

    cout << "I wanna be the very best" << endl;
    cout << "Like no one ever was" << endl;
    cout << "Catch them is my real test" << endl;
    cout << " train them is my cause" << endl;
    cout << "I will travel across the land" << endl;
    cout << " far and wide" << endl;
    cout << " Pokemon to understand" << endl;
    cout << " power that's inside" << endl;
    cout << "Pokemon!" << endl;
    cout << "Gotta catch 'em all (It's you and me)" << endl;
    cout << "I know its my destiny" << endl;
    cout << "Pokemon" << endl;
    cout << "Oh, you're my best friend" << endl;
    cout << "In a world we must defend" << endl;
    cout << "Pokemon!" << endl;
    cout << "Gotta catch 'em all (A heart so true)" << endl;
    cout << "Our courage will pull us through" << endl;
    cout << "You teach me and I'll teach you" << endl;
    cout << "Pokemon" << endl;
    cout << "Gotta catch 'em all" << endl;
    cout << "Gotta catch 'em all" << endl;
    cout << "Yeah" << endl;
    cout << "Every challenge along the way" << endl;
    cout << "With courage I will face" << endl;
    cout << "I will battle every day" << endl;
    cout << "To claim my rightful place" << endl;
    cout << "Come with me the time is right" << endl;
    cout << "There's no better team" << endl;
    cout << "Arm in arm we'll win the fight" << endl;
    cout << "It's always been our dream" << endl;
    cout << "Pokemon!" << endl;
    cout << "Gotta catch 'em all (It's you and me)" << endl;
    cout << "I know its my destiny" << endl;
    cout << "Pokemon" << endl;
    cout << "Oh, you're my best friend" << endl;
    cout << "In a worl we must defend" << endl;
    cout << "Pokemon!" << endl;
    cout << "Gotta catch 'em all (A heart so true)" << endl;
    cout << "Our courage will pull us through" << endl;
    cout << " teach me and I'll teach you" << endl;
    cout << "Pokemon" << endl;
    cout << "Gotta catch 'em all" << endl;
    cout << "Gotta catch 'em all" << endl;
    cout << "Pokemon!" << endl;

}

bool Pokedex::findName(string str) const {
    for(auto iter = begin(PokemonList); iter != end(PokemonList); iter ++){
        if((*iter)->name == str) return true;
    }
    return false;
}

bool Pokedex::findType(string str) const {
    for(auto iter = begin(PokemonList); iter != end(PokemonList); iter ++){
        if((*iter)->type == str) return true;
        if((*iter)->type2 == str) return true;
    }
    return false;
}