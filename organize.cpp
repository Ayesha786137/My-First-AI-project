#include <iostream>
#include <filesystem>
#include <string>
#include <map>
#include <vector>
#include <cctype>

namespace fs = std::filesystem;

int main() {
    // Categories define karo
    std::map<std::string, std::vector<std::string>> categories = {
        {"Images", {".jpg", ".jpeg", ".png", ".gif", ".bmp"}},
        {"Documents", {".pdf", ".docx", ".txt", ".xlsx", ".pptx"}},
        {"Videos", {".mp4", ".mkv", ".flv", ".avi"}},
        {"Music", {".mp3", ".wav", ".aac"}},
        {"Archives", {".zip", ".rar", ".7z"}},
        {"Programs", {".exe", ".msi", ".sh", ".bat"}}
    };

    std::string folderPath;
    std::cout << "Enter folder path (example: C:\\Users\\YourName\\Downloads): ";
    std::getline(std::cin, folderPath);

    fs::path dir(folderPath);
    if (!fs::exists(dir) || !fs::is_directory(dir)) {
        std::cerr << "Invalid folder path! Please check and try again." << std::endl;
        return 1;
    }

    // Har file ko process karo
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (fs::is_regular_file(entry.path())) {
            std::string ext = entry.path().extension().string();
            // Extension ko lowercase mein convert karo
            for (char& c : ext) c = std::tolower(c);

            // Category find karo
            std::string category = "Others";
            for (const auto& pair : categories) {
                for (const auto& e : pair.second) {
                    if (e == ext) {
                        category = pair.first;
                        break;
                    }
                }
                if (category != "Others") break;
            }

            // Destination folder banao
            fs::path destFolder = dir / category;
            if (!fs::exists(destFolder)) {
                fs::create_directory(destFolder);
            }

            // File move karo
            fs::path destPath = destFolder / entry.path().filename();
            try {
                fs::rename(entry.path(), destPath);
                std::cout << "Moved: " << entry.path().filename().string() << " -> " << category << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error moving " << entry.path().filename().string() << ": " << e.what() << std::endl;
            }
        }
    }

    std::cout << "\nDone! Folder organized successfully." << std::endl;
    return 0;
}
