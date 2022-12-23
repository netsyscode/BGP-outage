#include "init_info.hpp"

#include <fstream>
#include <iostream>
#include <string>

#include <jsoncons/json.hpp>

using namespace jsoncons;

JSONCONS_N_MEMBER_TRAITS(BGP_PLATFORM_NAMESPACE::AsInitInfo, 0, country,
                         aut_name, org_name, as_type)

BGP_PLATFORM_NAMESPACE_BEGIN

InitInfo::InitInfo(fs::path as_info_path, fs::path top_nx_path,
                   fs::path top_ip_path) {
  {
    std::ifstream as_info_file(as_info_path, std::ios::in);
    if (!as_info_file) {
      throw std::runtime_error("Cannot open as info file!");
    }

    std::cout << "Reading as info file..." << std::endl;
    auto as_info_json = jsoncons::json::parse(as_info_file);
    for (const auto& as_info : as_info_json.object_range()) {
      auto as_num       = static_cast<AsNum>(std::stoi(as_info.key()));
      auto as_info_data = as_info.value().as<AsInitInfo>();
      this->as_info_.emplace(as_num, as_info_data);
    }
    std::cout << "Done!" << std::endl;
  }
  {
    std::ifstream top_ip_file(top_ip_path, std::ios::in);
    if (!top_ip_file) {
      throw std::runtime_error("Cannot open top ip file!");
    }
    std::string buf;
    while (std::getline(top_ip_file, buf)) {
      // TODO: Read top ip
    }
  }
  {
    // TODO: Read top nx
    (void)top_nx_path;
  }
  std::cout << "Successfully to read init info!" << std::endl;
  return;
}

Country InitInfo::GetAsCountry(AsNum as_num) const {
  auto it = this->as_info_.find(as_num);
  if (it == this->as_info_.end()) {
    return {};
  }
  return it->second.country;
}

std::string InitInfo::GetAsAutName(AsNum as_num) const {
  auto it = this->as_info_.find(as_num);
  if (it == this->as_info_.end()) {
    return {};
  }
  return it->second.aut_name;
}

std::string InitInfo::GetAsOrgName(AsNum as_num) const {
  auto it = this->as_info_.find(as_num);
  if (it == this->as_info_.end()) {
    return {};
  }
  return it->second.org_name;
}

std::string InitInfo::GetAsType(AsNum as_num) const {
  auto it = this->as_info_.find(as_num);
  if (it == this->as_info_.end()) {
    return {};
  }
  return it->second.as_type;
}

BGP_PLATFORM_NAMESPACE_END
