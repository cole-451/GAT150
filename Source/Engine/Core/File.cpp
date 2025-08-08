#include "File.h"
#include "Core/Logger.h"
#include <iostream>
#include <istream>
#include <fstream>

using namespace parabellum;

std::string parabellum::File::GetCurrentDirectory() {
    std::error_code ec;
    auto path = std::filesystem::current_path();
    return ec ? std::string{} : path.string();
}

bool parabellum::File::SetCurrentDirectory(const std::string& path) {
    std::error_code ec;
    std::filesystem::current_path(path);

    return !ec;
}

std::string parabellum::File::GetExtension(const std::string& path) {
    std::filesystem::path p(path);
    return p.extension().string();
}

std::string parabellum::File::GetFilename(const std::string& path) {
    std::filesystem::path p(path);
    return p.filename().string();
}

bool parabellum::File::Exists(const std::string& path) {
    std::error_code ec;
    bool result = std::filesystem::exists (path, ec);

    return !ec && result;
}

std::vector<std::string> parabellum::File::GetFilesInDirectory(const std::string& path) {
    std::vector<std::string> files;
    std::error_code ec;

    auto iter = std::filesystem::directory_iterator(path, ec);
    if (ec) return files; // return empty vector on error

    for (const auto& entry : iter) {
        if (entry.is_regular_file(ec) && !ec) {
            files.push_back(entry.path().string());
        }
    }

    return files;
}

std::vector<std::string> parabellum::File::GetDirectoriesIn(const std::string& path) {
    std::vector<std::string> directories;
    std::error_code ec;

    auto iter = std::filesystem::directory_iterator(path, ec);
    if (ec) return directories; // return empty vector on error

    for (const auto& entry : iter) {
        if (entry.is_directory(ec) && !ec) {
            directories.push_back(entry.path().string());
        }
    }

    return directories;
}

bool parabellum::File::ReadTextFile(const std::string& path, std::string& content) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return false;
    }

    // read entire file into string
    // look at link on how-to read entire file into stringstream and convert buffer to string 
    if (file) {
    std::stringstream buffer;
    //read whole ass file
    buffer << file.rdbuf();
    //convert to string
    content = buffer.str();


    }
    else {
        Logger::Error("Cannot open file: ", path);
    }

        return true;
}

bool parabellum::File::WriteTextFile(const std::string& path, const std::string& content, bool append) {
    std::ios::openmode mode = append ? std::ios::app : std::ios::out;
    std::ofstream file(path, mode);
    if (!file.is_open()) {
        return false;
    }

    // read content string into file <https://www.geeksforgeeks.org/cpp/file-handling-c-classes/
    file << content;
    //is that it? I assume you just wanted me to write it to the file.

        return true;
}