#include <fstream>

template <typename T>
void genera_dot(const unidirected_graph<T>& grafo, const std::string& nome_file) {
    std::ofstream file(nome_file + ".dot");
    
    if (!file) {
        std::cerr << "Errore di apertura file!" << std::endl;
        return;
    }

    file << "digraph G {\n";

    for (const auto& u : grafo.all_nodes()) {
        for (const auto& v : grafo.neighbors(u)) {
            file << "    \"" << u << "\" -> \"" << v << "\";\n";
        }
    }

    file << "}\n";
    file.close();
    std::cout << "File " << nome_file << ".dot generato!" << std::endl;
}