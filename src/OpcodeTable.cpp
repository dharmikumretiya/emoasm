#include "emoasm/OpcodeTable.hpp"

OpcodeTable::OpcodeTable()
{
    opTab["LDA"] = "00";
    opTab["LDX"] = "04";
    opTab["LDL"] = "08";

    opTab["STA"] = "0C";
    opTab["STX"] = "10";
    opTab["STL"] = "14";

    opTab["ADD"] = "18";
    opTab["SUB"] = "1C";
    opTab["MUL"] = "20";
    opTab["DIV"] = "24";

    opTab["COMP"] = "28";
    opTab["TIX"] = "2C";

    opTab["JEQ"] = "30";
    opTab["JGT"] = "34";
    opTab["JLT"] = "38";
    opTab["J"] = "3C";

    opTab["AND"] = "40";
    opTab["OR"] = "44";

    opTab["JSUB"] = "48";
    opTab["RSUB"] = "4C";
}

std::string OpcodeTable::getOpcode(const std::string &mnemonic) const
{
    auto it = opTab.find(mnemonic);

    if (it == opTab.end())
        return "";

    return it->second;
}