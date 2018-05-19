#ifndef GRAM_HPP_DEF
#define GRAM_HPP_DEF
#include <stdio>
#include <vector>
#include <fstream>
#include <string>

struct gram_tag_elem{

};


struct gram_header_elem{

};

class GramRecord{
    

    bool compare(const GramRecord& other);
    void write_to_stream(ostream& os);
    string to_string();
    string to_SAM(string ref_path);
};

class GramCollection{
    public:
        std::string get_header();
        void parse_gram(const char* gram_file);
        void parse_gram(string gram_file);
        void parse_gram(ifstream gram_file);

    private:
        vector<gram_header_elem> header;

};


#endif
