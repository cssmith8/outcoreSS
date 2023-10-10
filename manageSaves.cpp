#include "manageSaves.h"

bool createSave(const string& appPath, const string& savesPath, string name) {
    formatName(&name);
    CopyFile((appPath + "\\Outcore\\save.me").c_str(), (savesPath + "\\" + name + ".s.me").c_str(), FALSE);
    CopyFile((appPath + "\\Idle Game\\free.me").c_str(), (savesPath + "\\" + name + ".f.me").c_str(), FALSE);
    return true;
}

bool deleteSave(const string& savesPath, string name) {
    formatName(&name);
    if (remove((savesPath + "\\" + name + ".s.me").c_str()) == -1) {
        return false;
    }
    if (remove((savesPath + "\\" + name + ".f.me").c_str()) == -1) {
        return false;
    }
    return true;
}

pair<bool, vector<string>> getSaves(const string& savesPath) {
    struct dirent *entry = nullptr;
    DIR *dp = nullptr;

    dp = opendir(savesPath.c_str());
    vector<string> folderNames;
    if (dp != nullptr) {
        int i = 0;
        while ((entry = readdir(dp))){
            folderNames.emplace_back(entry->d_name);
            i++;
        }
        if (i > 0) {
            cout << "Successfully read " << i << " files." << endl;
            for (auto & folderName : folderNames) {
                cout << folderName << endl;
            }
        } else {
            vector<string> error;
            error.emplace_back("No files detected in directory.");
            return make_pair(false, error);
        }
    } else {
        vector<string> error;
        error.emplace_back("Error opening directory.");
        return make_pair(false, error);
    }
    closedir(dp);

    //remove all entries not ending in .s.me or .f.me
    for (int i = 0; i < folderNames.size(); i++) {
        if (folderNames[i].size() < 6) {
            folderNames.erase(folderNames.begin() + i);
            i--;
        } else if (folderNames[i].substr(folderNames[i].size() - 6, 6) != ".s.me" && folderNames[i].substr(folderNames[i].size() - 6, 6) != ".f.me") {
            folderNames.erase(folderNames.begin() + i);
            i--;
        }
    }

    vector<pair<string, bool>> saveNames;
    for (auto& folderName : folderNames) {
        string name = folderName.substr(0, folderName.size() - 6);
        bool found = false;
        for (auto& saveName : saveNames) {
            if (saveName.first == name) {
                saveName.second = true;
                found = true;
                break;
            }
        }
        if (!found) {
            saveNames.emplace_back(name, false);
        }
    }

    vector<string> names;
    for (auto & saveName : saveNames) {
        if (saveName.second) {
            names.push_back(saveName.first);
        }
    }

    return make_pair(true, names);
}

bool loadSave(const string& appPath, const string& savesPath, string name) {
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

void listSaves(const string& savesPath, bool header) {
pair<bool, vector<string>> saves = getSaves(savesPath);
    if (!saves.first) {
        cout << saves.second[0] << endl;
        return;
    }
    if (header) {
        cout << "Saves:" << endl;
    }
    for (auto& save : saves.second) {
        cout << save << endl;
    }
}