#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <windows.h>

using namespace std;

bool createSave(string appPath, string savesPath, string name) {
    CopyFile((appPath + "\\Outcore\\save.me").c_str(), (savesPath + "\\" + name + ".s.me").c_str(), FALSE);
    CopyFile((appPath + "\\Idle Game\\free.me").c_str(), (savesPath + "\\" + name + ".f.me").c_str(), FALSE);
    return true;
}

bool deleteSave(string savesPath, string name) {
    remove((savesPath + "\\" + name + ".s.me").c_str());
    remove((savesPath + "\\" + name + ".f.me").c_str());
    return true;
}

int main() {

    //navigate to appdata folder
    string appPath = getenv("APPDATA");
    appPath.erase(appPath.end()-8, appPath.end());
    appPath.append("\\LocalLow\\DoctorShinobi");

    //save path to saves folder
    string savesPath = "..\\saves";


    //remove(appPath.c_str());

    createSave(appPath, savesPath, "test");
    deleteSave(savesPath, "test");

    return 0;
}
