#include "manageSaves.h"

bool createSave(string appPath, string savesPath, string name) {
    formatName(&name);
    CopyFile((appPath + "\\Outcore\\save.me").c_str(), (savesPath + "\\" + name + ".s.me").c_str(), FALSE);
    CopyFile((appPath + "\\Idle Game\\free.me").c_str(), (savesPath + "\\" + name + ".f.me").c_str(), FALSE);
    return true;
}

bool deleteSave(string savesPath, string name) {
    formatName(&name);
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

bool loadSave(string appPath, string savesPath, string name) {
    formatName(&name);
    //check that the file exists
    int errorCode = 0;
    if (GetFileAttributes((savesPath + "\\" + name + ".s.me").c_str()) == INVALID_FILE_ATTRIBUTES) {
        errorCode += 1;
    }
    if (GetFileAttributes((savesPath + "\\" + name + ".f.me").c_str()) == INVALID_FILE_ATTRIBUTES) {
        errorCode += 2;
    }
    if (errorCode > 0) {
        if (errorCode == 3) {
            cout << "Error loading save file: Invalid name." << endl;
        } else {
            cout << "Error loading save file: Incomplete save data." << endl;
        }
        return false;
    }
    CopyFile((savesPath + "\\" + name + ".s.me").c_str(), (appPath + "\\Outcore\\save.me").c_str(), FALSE);
    CopyFile((savesPath + "\\" + name + ".f.me").c_str(), (appPath + "\\Idle Game\\free.me").c_str(), FALSE);
    return true;
}