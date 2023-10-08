#include <iostream>

using namespace std;

int main() {

    //navigate to appdata folder
    string path = getenv("APPDATA");
    cout << path << endl;
    //remove "roaming" from path
    path.erase(path.end()-8, path.end());
    cout << path << endl;
    //add "local" to path
    path.append("\\LocalLow\\DoctorShinobi\\Outcore\\save.me");
    cout << path << endl;
    char filename[] = "C:\\Users\\cohen\\AppData\\LocalLow\\DoctorShinobi\\Outcore\\save.me";

    remove(filename);

    return 0;
}
