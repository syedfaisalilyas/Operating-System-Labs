#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

void displayDirectoryContents(const fs::path& directory) {
    for (const auto& entry : fs::directory_iterator(directory)) {
        cout << entry.path();
        if (fs::is_directory(entry)) {
            cout << " [Directory]";
        } else if (fs::is_regular_file(entry)) {
            cout << " [Regular File]";
        } else if (fs::is_symlink(entry)) {
            cout << " [Symbolic Link]";
        } else if (fs::is_socket(entry)) {
            cout << " [Socket]";
        } else if (fs::is_fifo(entry)) {
            cout << " [FIFO]";
        } else if (fs::is_character_file(entry)) {
            cout << " [Character Device]";
        } else if (fs::is_block_file(entry)) {
            cout << " [Block Device]";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <directory_path>" << endl;
        return 1;
    }

    fs::path directory(argv[1]);

    if (!fs::exists(directory)) {
        cerr << "Error: Directory does not exist." << endl;
        return 1;
    }

    if (!fs::is_directory(directory)) {
        cerr << "Error: Not a valid directory." << endl;
        return 1;
    }

    cout << "Contents of directory '" << directory << "':" << endl;
    displayDirectoryContents(directory);

    return 0;
}

