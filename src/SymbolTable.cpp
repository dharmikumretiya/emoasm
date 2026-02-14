#include "emoasm/SymbolTable.hpp"

int SymbolTable::hash(const std::string &symbol) const
{

    int hash = 0;
    for (auto i : symbol)
    {
        hash += (int)i;
    }
    return hash;
}

int SymbolTable::insertSymbol(const std::string &symbol, int address)
{

    if (size >= SymTabSize)
    {
        return -1;
    }
    int idx = hash(symbol) % SymTabSize;
    while (!table[idx].symbol.empty())
    {
        idx = (idx + 1) % SymTabSize;
    }
    table[idx].address = address;
    table[idx].symbol = symbol;
    size++;
    return idx;
}

int SymbolTable::getAddress(const std::string &symbol) const
{

    if (symbol.empty())
    {
        return -1;
    }

    int idx = hash(symbol) % SymTabSize;
    int i = 0;
    while (table[idx].symbol != symbol && i < SymTabSize)
    {
        idx = (idx + 1) % SymTabSize;
        i++;
    }

    if (i >= SymTabSize)
    {
        return -1;
    }

    return table[idx].address;
}

void SymbolTable::disaplySymbolTable() const
{

    std::cout << std::left
              << std::setw(10) << "Index"
              << std::setw(20) << "Symbol"
              << std::setw(10) << "Address"
              << "\n";

    std::cout << "----------------------------------------"<<"\n";

    int i = 0;
    for (const auto &entry : table)
    {
        if (!entry.symbol.empty())
        {
            std::cout << std::left
                      << std::setw(10) << i
                      << std::setw(20) << entry.symbol
                      << std::setw(10) << entry.address
                      << "\n";
        }
        i++;
    }
}