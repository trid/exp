//
// Created by TriD on 02.10.2021.
//

#ifndef EXP_MAIN_SCRIPT_CONTEXT_H
#define EXP_MAIN_SCRIPT_CONTEXT_H


#include "script_context.h"

class MainScriptContext: public ScriptContext {
public:
    MainScriptContext();

private:
    void registerFunctions();
};


#endif //EXP_MAIN_SCRIPT_CONTEXT_H
