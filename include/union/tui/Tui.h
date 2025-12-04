#include <union/core/FamilyManager.h>
#include <vector>

class Tui {
    private:
        FamilyManager manager;
    public:
        std::vector<std::string> tokenize_input(const std::string& line);

        void display_help();
        void handle_add(const std::vector<std::string>& tokens);
        void handle_bond(const std::vector<std::string>& tokens);
        void handle_are_connected(const std::vector<std::string>& tokens);
        void handle_show(const std::vector<std::string>& tokens);
        void handle_ancestors(const std::vector<std::string>& tokens);

        void clean();
};