#ifndef GRAM_HPP_DEF
#define GRAM_HPP_DEF
#include <stdio>
#include <vector>
#include <bitset>
#include <fstream>
#include <string>

struct gram_tag_elem{
    char* key;
    char* type;
    void* value;
};


struct gram_header_elem{
    char* id;
    char* type;
    void* val;
};



struct GramRecord{
    
    char* contig;
    uint32_t start;
    uint32_t end;
    char* identifier;
    char* sequence;
    uint32_t length;
    char* qualities;
    std::vector<char*> path;
    std::vector<char*> mappings;
    std::vector<gram_tag_elem> tags;
    uint64_t boolean flags = 0;
    bool isMapped(){
        
    };
    void isMapped(bool m){

    };

    bool isSoftclipped(){
        
    };
    void isSoftclipped(bool s){

    };
    bool isPaired(){

    };
    void isPaired(bool p){

    };
    bool properOrientation(){

    };
    void properOrientation(bool p){

    };
    bool largeDeletion(){

    };
    void largeDeletion(bool d){

    };

    
    GramRecord();
    GramRecord(string line);

    bool compare(const GramRecord& other);
    void write_to_stream(ostream& os);
    string collapsed_cigar();
    string to_string();
    string to_SAM(string ref_path);
    string to_BED();
};


inline void parseLine(char* line, GramRecord& g){

};

inline void parseLine(string line, GramRecord& g){

};

inline void parseFromGAM(char* line, GramRecord& g){

};

inline void parseFromGAM(string line, GramRecord& g){

};

#endif
