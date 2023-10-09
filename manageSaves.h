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


bool createSave(string appPath, string savesPath, string name);

bool deleteSave(string savesPath, string name);

bool listSaves(string savesPath);

bool loadSave(string appPath, string savesPath, string name);


#endif //OUTCORESS_MANAGESAVES_H