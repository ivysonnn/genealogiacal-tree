#include <algorithm>
#include <iostream>

#include <union/tui/Tui.h>

int main() {
    Tui tui;
    std::cout << "Gerencia de Redes Familiares TUI. Digite HELP para comandos.\n";
    std::string line;

    while (true) {
        std::cout << "\n> ";
        if (!std::getline(std::cin, line) || line.empty()) continue;

        std::vector<std::string> tokens = tui.tokenize_input(line);
        if (tokens.empty()) continue;

        std::string command = tokens[0];
        std::transform(command.begin(), command.end(), command.begin(), ::toupper); 

        if (command == "ADD") tui.handle_add(tokens);
        else if (command == "BOND") tui.handle_bond(tokens);
        else if (command == "ARECONNECTED") tui.handle_are_connected(tokens);
        else if (command == "SHOW") tui.handle_show(tokens);
        else if (command == "HELP") tui.display_help();
        else if (command == "QUIT" || command == "EXIT") { tui.clean(); break; }
        else std::cout << "Comando desconhecido. Digite HELP.\n";
    }
    return 0;
}