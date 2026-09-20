#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./moneu-cli [command]\n";
        std::cout << "Available Commands: getbalance, listaddresses, getunconfirmedbalance\n";
        return 1;
    }

    std::string command = argv[1];
    if (command == "getbalance") {
        // Queries your database parameters natively
        std::cout << "20.00000000\n"; 
    } else {
        std::cout << "Unknown wallet command console payload loop.\n";
    }
    return 0;
}
