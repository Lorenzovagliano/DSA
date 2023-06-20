#include <cstdio>
#include <cstdlib>
#include <string>

#define ll unsigned long long int

namespace Huffman {

std::string HuffmanValue[256] = {""};

struct Node {
    char character;
    ll count;
    Node *left, *right;

    Node(ll count) {
        this->character = 0;
        this->count = count;
        this->left = this->right = nullptr;
    }

    Node(char character, ll count) {
        this->character = character;
        this->count = count;
        this->left = this->right = nullptr;
    }
};

namespace Utility {
    ll get_file_size(const char *filename) {
        FILE *p_file = fopen(filename, "rb");
        fseek(p_file, 0, SEEK_END);
        ll size = ftello64(p_file);
        fclose(p_file);
        return size;
    }

    void Inorder(Node *root, std::string &value) {
        if (root) {
            value.push_back('0');
            Inorder(root->left, value);
            value.pop_back();

            if (root->left == nullptr && root->right == nullptr) {
                printf("Character: %c, Count: %lld, ", root->character, root->count);
                std::cout << "Huffman Value: " << value << std::endl;
            }

            value.push_back('1');
            Inorder(root->right, value);
            value.pop_back();
        }
    }
};

namespace CompressUtility {
    Node *combine(Node *a, Node *b) {
        Node *parent = new Node((a ? a->count : 0) + (b ? b->count : 0));
        parent->left = b;
        parent->right = a;
        return parent;
    }

    bool sortbysec(const Node *a, const Node *b) {
        return (a->count > b->count);
    }

    std::map<char, ll> parse_file(const char *filename, const ll Filesize) {
        FILE *ptr = fopen(filename, "rb");
        if (ptr == NULL) {
            perror("Error: File not found:");
            exit(-1);
        }
        unsigned char ch;
        ll size = 0, filesize = Filesize;
        std::vector<ll> Store(256, 0);

        while (size != filesize) {
            ch = fgetc(ptr);
            ++Store[ch];
            ++size;
        }

        std::map<char, ll> store;
        for (int i = 0; i < 256; ++i) {
            if (Store[i]) {
                store[i] = Store[i];
            }
        }
        fclose(ptr);
        return store;
    }

    void sort_by_character_count(const std::map<char, ll>& value, std::vector<Node*>& store) {
        for (auto& x : value) {
            store.push_back(new Node(x.first, x.second));
        }

        for (size_t i = 0; i < store.size(); ++i) {
            for (size_t j = i + 1; j < store.size(); ++j) {
                if (store[i]->count < store[j]->count) {
                    Node* temp = store[i];
                    store[i] = store[j];
                    store[j] = temp;
                }
            }
        }
    }

    std::string generate_header(const char padding) {
        std::string header = "";
        unsigned char UniqueCharacter = 255;

        for (const auto& value : Huffman::HuffmanValue) {
            if (value != "") {
                header += (unsigned char)UniqueCharacter;
                header += (unsigned char)value.length();
                header += value;
                UniqueCharacter--;
            }
        }

        header += (unsigned char)padding;
        return header;
    }

        std::string compress(const char *filename, const ll Filesize) {
        std::map<char, ll> store = parse_file(filename, Filesize);
        std::vector<Node*> sorted_store;
        sort_by_character_count(store, sorted_store);

        while (sorted_store.size() != 1) {
            std::sort(sorted_store.begin(), sorted_store.end(), sortbysec);
            Node *left = sorted_store.back();
            sorted_store.pop_back();
            Node *right = sorted_store.back();
            sorted_store.pop_back();
            Node *parent = combine(left, right);
            sorted_store.push_back(parent);
        }

        Node *root = sorted_store.front();
        std::string value = "";
        Utility::Inorder(root, value);

        for (int i = 0; i < 256; ++i) {
            Huffman::HuffmanValue[i] = "";
        }

        std::string header = generate_header(value.length() % 8);
        std::string compressed_file = header;

        FILE *inptr = fopen(filename, "rb");
        if (inptr == NULL) {
            perror("Error: File not found:");
            exit(-1);
        }
        unsigned char ch;
        ll size = 0;

        while (size != Filesize) {
            ch = fgetc(inptr);
            compressed_file += Huffman::HuffmanValue[ch];
            ++size;
        }
        fclose(inptr);
        return compressed_file;
    }
};

int main() {
    const char *filename = "file.txt";
    ll Filesize = Huffman::Utility::get_file_size(filename);
    std::string compressed_file = Huffman::CompressUtility::compress(filename, Filesize);

    FILE *outptr = fopen("compressed.bin", "wb");
    if (outptr == NULL) {
        perror("Error: Unable to create compressed file:");
        exit(-1);
    }
    fwrite(compressed_file.c_str(), sizeof(char), compressed_file.length(), outptr);
    fclose(outptr);

    return 0;
}