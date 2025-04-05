#include <cstdlib>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

void install_symlink(std::string initial_dir, std::string install_dir) {
    std::filesystem::create_directory_symlink(install_dir, initial_dir);
}

std::vector<std::string> get_configs(std::filesystem::path &path) {

    std::vector<std::string> configs;
    for(const auto & dir_entry: std::filesystem::directory_iterator(std::filesystem::absolute(path))) {
        configs.push_back(dir_entry.path());
    }

    return configs;
}

void install_all_dots(std::vector<std::string> &configs) {
    const char *home_env = getenv("HOME");

    std::string home_location(home_env); // Location of users home
    std::string config_location = home_location + "/.config/"; // Location of users config
    std::cout << config_location << std::endl;
    std::vector<std::string> config_paths;

    for(int i = 0; i < configs.size(); i++) {
        size_t con = configs[i].rfind('/');
        std::string res;
        if (con != std::string::npos) {
            res = configs[i].substr(con + 1);
        } else {
            res = configs[i];  // No slash found, return the whole string
        }
        std::filesystem::file_status status = std::filesystem::status(std::filesystem::path(configs[i]));
        if (std::filesystem::is_directory(status)) {
            config_paths.push_back(config_location + res);
        } else {
            config_paths.push_back(home_location + "/" + res);
        }
    }
    for(size_t i = 0; i < config_paths.size(); i++) {
        std::cout << config_paths[i] << std::endl;
    }
    
}
