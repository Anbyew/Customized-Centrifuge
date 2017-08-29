//
//  coutoa.cpp
//  
//
//  Created by 包雨薇 on 17/8/8.
//
//

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char **argv) {

    string filenm = argv[1];
    string outfnm = argv[2];
    
    
    ifstream infile;
    ofstream offile;
    infile.open(filenm.c_str());
    if (!infile.is_open()) {
        cout << "error opening infile" << endl;
        exit(1);
    }
    
    offile.open(outfnm.c_str(), std::ios_base::app);
    if (!offile.is_open()) {
        cout << "error opening outfile" << endl;
        exit(1);
    }
    
    string name;
    string seq;
    string trash;
    getline(infile, trash);
    
    while (infile >> name) {
        infile >> trash;//seqID
        infile >> trash;//taxID
        infile >> trash;//score
        infile >> trash;//2ndBestScore
        infile >> trash;//hitLength
        infile >> trash;//queryLength
        infile >> trash;//numMatches
        infile >> seq;
        offile << '>' << name << endl << seq << endl;
        getline(infile, trash);
    }
    
    
    infile.close();
    offile.close();
    
    return 0;
}