#include <iostream>
#include <map>
#include <string>
#include <fstream>

class Dictionary {
    size_t index = 0;

public: 
    Dictionary(std::string = "");

    std::map<std::string, size_t> dictionary{};

    bool contains(std::string);
    size_t add(std::string);
    size_t get(std::string);
};

Dictionary::Dictionary(std::string alphabet) {
    for(const char letter: alphabet) {
        add(std::string{letter});
    }
}

bool Dictionary::contains(std::string key) {
    return dictionary.find(key) != dictionary.end();
}

size_t Dictionary::add(std::string key) {
    if(contains(key)) return get(key);
    dictionary[key] = index;
    return index++;
}

size_t Dictionary::get(std::string key) {
    return dictionary[key];
}

std::string encode(const std::string& input, Dictionary* dictionary) {
    std::string out{};

    std::string c{input[0]};
    std::string s;

    for(size_t i = 1; i < input.size(); i++) {
        s = std::string{input[i]};

        if(dictionary->contains(c + s)) {
            c += s;
            continue;
        }

        out += std::to_string(dictionary->get(c)) + " ";
        dictionary->add(c + s);
        c = s;
    }

    out += std::to_string(dictionary->get(c)) + " ";
    return out;
}

int main() {
    std::ifstream file_in("input.txt");
    std::string input{};
    std::string line;

    while(file_in.good()) {
        if(input.size()) input += '\n';
        std::getline(file_in, line);
        input += line;
    }

    file_in.close();

    std::string alphabet{};
    alphabet.reserve(255);

    for(int i = 1; i < 256; i++) {
        alphabet += i;
    }

    Dictionary* dictionary = new Dictionary(alphabet);
    std::string encoded = encode(input, dictionary);

    std::ofstream file_out("output.txt");
    file_out << encoded;

    file_out.close();
}
