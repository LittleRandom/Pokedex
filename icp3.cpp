// ECE 309 -- Spring 2020
// ICP3: Containers

#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cout;
using std::cin;
using std::endl;

#include <list>
#include "Pokedex.h"

int main() {
    Pokedex dex("pokemon.txt");

    cout << "At each prompt, enter a command:" << endl;
    cout << "   i <integer> -- get Pokemon with specified id" << endl;
    cout << "   n <string> -- get Pokemon with specified name" << endl;
    cout << "   t <string> -- get all Pokemon with specified type" << endl;
    cout << "   q -- quit " << endl;
    cout << "   a -- prints all pokemon data" << endl;

    while (true) {
        cout << ">> " << std::flush;
        string command;
        cin >> command;
        if ((command == "i")||(command =="I")) {
            int index;
            cin >> index;
            if((index>151)||(index<1)) {
                cout << "Pokemon does not exist!"<< endl;
            } else {
                Pokemon *p = dex.findByIndex(index);
                dex.printPokemonData(p);
            }
        }
        else if ((command == "n")||(command =="N")) {
            string name;
            cin >> name;
            if(dex.findName(name)) {
                Pokemon *p = dex.findByName(name);
                dex.printPokemonData(p);
            } else {
                cout << "Pokemon doesn't exist!"<< endl;
            }
        }
        else if ((command == "t")||(command =="T")) {
            string type;
            cin >> type;
            if(dex.findName(type)) {
                std::list<const Pokemon*> plist = dex.findByType(type);
                dex.printPokemonList(plist);
            } else {
                cout << "Type doesn't exist!"<< endl;
            }

        }
        else if ((command == "q")||(command =="Q")) {
            break;
        }
        else if ((command == "a")||(command =="A")){
            dex.printAllPokemonData();
        }
        else if (command == "sing"){
            dex.easteregg();
        }
    }
    return 0;
}