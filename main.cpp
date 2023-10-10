#include <string>
#include <cstdlib>

#include "manageSaves.h"

using namespace std;

int main() {

    //navigate to appdata folder
    string appPath = getenv("APPDATA");
    appPath.erase(appPath.end()-8, appPath.end());
    appPath.append("\\LocalLow\\DoctorShinobi");

    //save path to saves folder
    string savesPath = "..\\saves";

    createSave(appPath, savesPath, "test");
    //deleteSave(savesPath, "test");

    listSaves(savesPath);

    //deleteSave(savesPath, "test");

    return 0;
}
