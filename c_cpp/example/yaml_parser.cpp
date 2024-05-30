#include <iostream>
#include <yaml-cpp/yaml.h>

struct Control {
    std::string name;
    double value;
};

void process_node(const YAML::Node& node, int depth);

int main() {
    std::string file_path = "test.yaml";
    YAML::Node root = YAML::LoadFile(file_path);

    process_node(root, 0);

    return 0;
}

void process_node(const YAML::Node& node, int depth) {
    if (node.IsScalar()) {
        std::cout << std::string(depth * 2, ' ') << "- " << node.as<std::string>() << ": ";
    } else if (node.IsSequence()) {
        for (const auto& item : node) {
            process_node(item, depth + 1);
        }
        return;
    }

    if (node["value"]) {
        std::cout << node["value"].as<double>() << std::endl;
    }
}
