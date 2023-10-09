#include <string>
#include <algorithm>

using namespace std;

void formatName(string* input) {
    input->erase(remove(input->begin(), input->end(), ' '), input->end());
    input->erase(remove(input->begin(), input->end(), '\\'), input->end());
    input->erase(remove(input->begin(), input->end(), '/'), input->end());
}