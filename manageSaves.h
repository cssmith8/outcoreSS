#ifndef OUTCORESS_MANAGESAVES_H
#define OUTCORESS_MANAGESAVES_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <dirent.h>
#include <vector>
#include <algorithm>

#include "format.cpp"


bool createSave(const string& appPath, const string& savesPath, string name);

bool deleteSave(const string& savesPath, string name);

pair<bool, vector<string>> getSaves(const string& savesPath);

bool loadSave(const string& appPath, const string& savesPath, string name);

void listSaves(const string& savesPath, bool header = true);


#endif //OUTCORESS_MANAGESAVES_H