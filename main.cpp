#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    //navigate to appdata folder
    string path = getenv("APPDATA");
    path.erase(path.end()-8, path.end());
    path.append("\\LocalLow\\DoctorShinobi\\Outcore\\save.me");

    //convert path to char array
    char *cpath = new char[path.length() + 1];
    strcpy(cpath, path.c_str());
    remove(cpath);

    return 0;
}
