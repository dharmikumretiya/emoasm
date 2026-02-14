#pragma once

#include <string>
#include <unordered_map>

class OpcodeTable
{
private:
    std::unordered_map<std::string, std::string> opTab;

public:
    OpcodeTable();
    std::string getOpcode(const std::string &mnemonic) const;
};