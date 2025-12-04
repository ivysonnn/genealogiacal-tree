#include <union/tui/Tui.h>

#include <sstream>
#include <iostream>

std::vector<std::string> Tui::tokenize_input(const std::string& line) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

void Tui::display_help() {
    std::cout << "\n--- COMANDOS DISPONIVEIS ---\n";
    std::cout << "ADD [Nome]\n";
    std::cout << "BOND [Filho] [Pai] [Mae] (Use NULL para desconhecido)\n";
    std::cout << "ARECONNECTED [P1] [P2]\n";
    std::cout << "SHOW [Pessoa] (Mostra pais e representante)\n";
    std::cout << "QUIT/EXIT\n";
    std::cout << "---------------------------\n";
}

void Tui::handle_add(const std::vector<std::string>& tokens) {
    if (tokens.size() != 2) {
        std::cout << "Uso: ADD [Nome]\n";
        return;
    }
    if (manager.registerPerson(tokens[1])) {
        std::cout << "[SUCESSO] Pessoa '" << tokens[1] << "' adicionada.\n";
    } else {
        std::cout << "[ERRO] Pessoa '" << tokens[1] << "' ja existe.\n";
    }
}

void Tui::handle_bond(const std::vector<std::string>& tokens) {
    if (tokens.size() != 4) {
        std::cout << "Uso: BOND [Filho] [Pai] [Mae] (Use NULL)\n";
        return;
    }
    if (manager.bond(tokens[1], tokens[2], tokens[3])) {
        std::cout << "[SUCESSO] Ligacao estabelecida.\n";
    } else {
        std::cout << "[ERRO] Falha ao ligar. Verifique nomes, existencia ou relacao ja existe.\n";
    }
}

void Tui::handle_are_connected(const std::vector<std::string>& tokens) {
    if (tokens.size() != 3) {
        std::cout << "Uso: ARECONNECTED [P1] [P2]\n";
        return;
    }
    if (manager.areConnected(tokens[1], tokens[2])) {
        std::cout << "[CONEXAO] " << tokens[1] << " e " << tokens[2] << " pertencem ao mesmo tronco familiar.\n";
    } else {
        std::cout << "[DESCONEXAO] " << tokens[1] << " e " << tokens[2] << " estao em troncos separados.\n";
    }
}

void Tui::handle_show(const std::vector<std::string>& tokens) {
    if (tokens.size() != 2) {
        std::cout << "Uso: SHOW [Pessoa]\n";
        return;
    }
    Person* p = manager.getPerson(tokens[1]);
    if (!p) {
        std::cout << "[ERRO] Pessoa nao encontrada.\n";
        return;
    }
    Person* rep = p->findSet();
    std::cout << "\n--- DADOS DE " << p->getName() << " ---\n";
    std::cout << "Pai: " << (p->getFather() ? p->getFather()->getName() : "NULL") << "\n";
    std::cout << "Mae: " << (p->getMother() ? p->getMother()->getName() : "NULL") << "\n";
    std::cout << "REPRESENTANTE FAMILIAR: " << rep->getName() << "\n";
    std::cout << "---------------------------\n";
}

void Tui::clean() {
    manager.cleanup();
}