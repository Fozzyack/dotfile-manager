#include <vector>
#include <string>
#include <filesystem>

std::vector<std::string> get_configs(std::filesystem::path &path) {
    std::vector<std::string> configs;
    for(const auto & dir_entry: std::filesystem::directory_iterator(std::filesystem::absolute(path))) {
        configs.push_back(dir_entry.path());
    }
    return configs;
}
