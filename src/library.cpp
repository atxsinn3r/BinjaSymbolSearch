#include <iostream>
#include <regex>
#include "binaryninjaapi.h"

using namespace BinaryNinja;
using namespace std;
using namespace regex_constants;

void run(BinaryView *view, uint64_t start, uint64_t length) {
    string input;
    BinaryNinja::GetTextLineInput(input, "Search pattern", "Symbol Search");
    if (input.empty()) {
        LogInfo("No search pattern given");
        return;
    }

    for (auto& function : view->GetAnalysisFunctionList()) {
        Ref<Symbol> symbol = function->GetSymbol();
        if (!symbol) {
            continue;
        }

        string shortName = symbol->GetShortName();
        regex pattern(input);
        smatch m;
        if (regex_search(shortName, m, pattern)) {
            stringstream message;
            message << "sub_";
            message << hex << symbol->GetAddress();
            message << " : ";
            message << shortName;
            LogInfo("%s", message.str().c_str());
        }
    }

    LogInfo("Done.");
}

extern "C" {
BINARYNINJAPLUGIN bool CorePluginInit() {
    PluginCommand::RegisterForRange("Symbol Search", "Symbol searching with regex", &run);
    return true;
}
}