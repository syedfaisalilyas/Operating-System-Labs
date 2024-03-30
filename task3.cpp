#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string folder;
    std::cout << "Enter the folder name: ";
    std::cin >> folder;

    if (fs::is_directory(folder)) 
    {
        for (const auto& entry : fs::directory_iterator(folder)) 
        {
            if (entry.is_regular_file()) 
            {
                if (entry.path().extension() == ".txt") 
                {
                    if (!fs::exists("Txt")) 
                    {
                        fs::create_directory("Txt");
                        std::cout << "Directory created: Txt" << std::endl;
                    }

                    std::string destinationFilePath = std::string("Txt") + "/example_file.txt";

                    fs::copy(entry.path(), destinationFilePath, fs::copy_options::overwrite_existing);
                    std::cout << "File copied to the directory: " << destinationFilePath << std::endl;
                }
                else if (entry.path().extension() == ".bmp") 
                {
                    if (!fs::exists("BMP")) 
                    {
                        fs::create_directory("BMP");
                        std::cout << "Directory created: BMP" << std::endl;
                    }

                    std::string destinationFilePath = std::string("BMP") + "/example_file.txt";

                    fs::copy(entry.path(), destinationFilePath, fs::copy_options::overwrite_existing);
                    std::cout << "File copied to the directory: " << destinationFilePath << std::endl;
                }
            }
        }
    } 
    else 
    {
        std::cerr << "Error: Not a valid directory." << std::endl;
    }

    return 0;
}

