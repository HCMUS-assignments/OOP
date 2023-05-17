#include "QLPhim.h"

QLPhim::QLPhim() {
}

QLPhim::~QLPhim() {
}

void QLPhim::addPhim(Phim phim) {
    // cout << "start to add phim" << endl;
    int i = 0;
    while (i < _dsPhim.size() && _dsPhim[i].getYear() <= phim.getYear()) {
        i++;
    }

    _dsPhim.insert(i, phim);
    // cout << "add phim successfully" << endl;
}

void QLPhim::writeToFile() {
    ofstream fout("ds_phim.dat");
    if (fout.fail()) {
        cout << "Failed to open file" << endl;
        return;
    }
    for (int i = 0; i < _dsPhim.size(); i++) {
        fout << _dsPhim[i];
    }
    cout << "Write to file successfully" << endl;
    fout.close();
}

void QLPhim::readFromFile() {
    ifstream fin("ds_phim.dat");
    if (fin.fail()) {
        cout << "Failed to open file" << endl;
        return;
    }
    
    if (_dsPhim.size() > 0) _dsPhim.clear();
    cout << "Reading from file..." << endl;
    Phim phim;
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        phim.setId((char *)token.c_str());
        getline(ss, token, ',');
        phim.setName((char *)token.c_str());
        getline(ss, token, ',');
        phim.setType((char *)token.c_str());
        getline(ss, token, ',');
        phim.setProceducer((char *)token.c_str());
        getline(ss, token, ',');
        phim.setYear(atoi(token.c_str()));
        getline(ss, token, ',');
        phim.setRank(atoi(token.c_str()));
        addPhim(phim);

    }
    cout << "Read from file successfully" << endl;
    fin.close();
}

void QLPhim::deleteHBO() {
    int j = 0;
    for (int i = 0; i < _dsPhim.size() ; i++) {
        if (strcmp(_dsPhim[i].getProceducer(), "HBO") != 0) {
            _dsPhim[j++] = _dsPhim[i];
        }
    }
    _dsPhim.resize(j);
    writeToFile();
}