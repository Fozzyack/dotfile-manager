#pragma once
#include <vector>
#include <string>
#include <filesystem>

std::vector<std::string> get_configs(std::filesystem::path &path);
std::vector<std::string> get_install_locations(std::vector<std::string> &configs);
void install_all_dots(std::vector<std::string> &configs, std::vector<std::string> &config_paths);
