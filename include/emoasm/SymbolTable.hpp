#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

const int SymTabSize = 10;

struct entry
{
    std::string symbol;
    int address = -1;
};

class SymbolTable{

    private:
        std :: vector<entry> table = std::vector<entry>(SymTabSize);
    public:
        int size;

        SymbolTable(){
            size = 0;
        }

        int insertSymbol(const std::string &symbol, int address);
        int getAddress(const std::string& symbol) const;
        void disaplySymbolTable() const;
        int hash(const std::string &symbol) const;
};
