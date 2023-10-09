#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool createSave(string appPath, string savesPath, string name) {
    CopyFile((appPath + "\\Outcore\\save.me").c_str(), (savesPath + "\\" + name + ".s.me").c_str(), FALSE);
    CopyFile((appPath + "\\Idle Game\\free.me").c_str(), (savesPath + "\\" + name + ".f.me").c_str(), FALSE);
    return true;
}

bool deleteSave(string savesPath, string name) {
    if (remove((savesPath + "\\" + name + ".s.me").c_str()) == -1) {
        return false;
    }
    if (remove((savesPath + "\\" + name + ".f.me").c_str()) == -1) {
        return false;
    }
    return true;
}

bool listSaves(string savesPath) {
    struct dirent *entry = nullptr;
    DIR *dp = nullptr;

    dp = opendir(savesPath.c_str());
    vector<string> folderNames;
    if (dp != nullptr) {
        int i = 0;
        while ((entry = readdir(dp))){
            folderNames.push_back(entry->d_name);
            i++;
        }
        if (i > 0) {
            cout << "Successfully read " << i << " files." << endl;
            for (int j = 0; j < folderNames.size(); j++) {
                cout << folderNames[j] << endl;
            }
        } else {
            cout << "No files detected in directory." << endl;
            int exit;
            cin >> exit;
            return false;
        }
    } else {
        cout << "Error opening directory." << endl;
        return false;
    }
    closedir(dp);
}

//function that removes all spaces from a string
string formatName(string input) {
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    input.erase(remove(input.begin(), input.end(), '\\'), input.end());
    input.erase(remove(input.begin(), input.end(), '/'), input.end());
    return input;
}

int main() {

    //navigate to appdata folder
    string appPath = getenv("APPDATA");
    appPath.erase(appPath.end()-8, appPath.end());
    appPath.append("\\LocalLow\\DoctorShinobi");

    //save path to saves folder
    string savesPath = "..\\saves";



    //createSave(appPath, savesPath, "test");
    //deleteSave(savesPath, "test");

    listSaves(savesPath);

    deleteSave(savesPath, "test");

    return 0;
}
