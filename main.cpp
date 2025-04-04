#include <iostream>
#include <filesystem>
using namespace std;


int main() {

    filesystem::path p("/home/fozzyack/code/dotfile_manager");
    for(const auto& dir_entry : filesystem::recursive_directory_iterator(p)) {
        cout << dir_entry.path() << endl;
    }
    cout << p.string() << endl;
    cout << filesystem::exists(p) << endl;

    return 0;
}
