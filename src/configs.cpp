#include <cstdlib>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

/*
 * Make Symlinks
 */
void install_symlink(std::string install_dir, std::string initial_dir) {
    std::cout << "Attempting to install " << install_dir << " to " << install_dir << std::endl;

    try {
        std::filesystem::create_symlink(initial_dir, install_dir);
    } catch (std::filesystem::__cxx11::filesystem_error e) {
        std::cout << "File may already exist :: Passing" << std::endl;
        return;
    }
    std::cout << "Installation Of Dotfile Successful" << std::endl;
}

void uninstall_symlink(std::string remove_dir) {
    std::filesystem::path path(remove_dir);
    if(std::filesystem::exists(path)) {
        std::cout << "Deleting File: " << path.string() << std::endl;
        std::filesystem::remove(path);
    } else {
        std::cout << "Could not Delete File (did not exist): " << path.string() << std::endl;
    }
}

/*
 * Generate Initial Configs
 */
std::vector<std::string> get_configs(std::filesystem::path &path) {

    std::vector<std::string> configs;
    for(const auto & dir_entry: std::filesystem::directory_iterator(std::filesystem::absolute(path))) {
        configs.push_back(dir_entry.path());
    }
    return configs;
}

/*
 * Generating the Config Locations
 */
std::vector<std::string> get_install_locations(std::vector<std::string> &configs) {

    const char *home_env = getenv("HOME");

    std::string home_location(home_env); // Location of users home
    std::string config_location = home_location + "/.config/"; // Location of users config
                                                               //
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
            config_paths.push_back(home_location + "/." + res);
        }
    }
    return config_paths;
}

/*
 * Functions to install the symlinks | "Install" the dotfiles
 */
void install_all_dots(std::vector<std::string> &configs, std::vector<std::string> &config_paths) {
    std::cout << "INSTALLING ALL DOTFILES" << std::endl;

    for(size_t i = 0; i < config_paths.size(); i++) {
        install_symlink(config_paths[i], configs[i]);
    }
    std::cout << "\n\nDone ... Press ENTER to continue" << std::endl;
}

int install_individual(std::string choice, std::vector<std::string> &configs, std::vector<std::string> &config_paths) {
    int input;
    try {
        input = std::stoi(choice);
    } catch (std::invalid_argument e) {
        choice = "-1";
    }

    if (input < 1 || input > configs.size()) return 1;

    install_symlink(config_paths[input - 1], configs[input - 1]);

    return 0;
}

/*
 * Functions to remove symlinks | "Remove" the dotfiles
 */
void remove_all_dots(std::vector<std::string> &config_paths) {
    std::cout << "UNINSTALLING all dotfiles" << std::endl;
    for(size_t i = 0; i < config_paths.size(); i++) {
        uninstall_symlink(config_paths[i]);
    }
    std::cout << "\n\nDone ... Press ENTER to continue" << std::endl;
}

int remove_individual(std::string choice, std::vector<std::string> &config_paths) {
    int input;
    try {
        input = std::stoi(choice);
    } catch (std::invalid_argument e) {
        choice = "-1";
    }

    if (input < 1 || input > config_paths.size()) return 1;

    uninstall_symlink(config_paths[input - 1]);

    return 0;
}








