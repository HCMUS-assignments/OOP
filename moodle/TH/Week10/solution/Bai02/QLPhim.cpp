#include "QLPhim.h"

QLPhim::QLPhim() {
}

QLPhim::~QLPhim() {
}

void QLPhim::addPhim(Phim* phim) {
    int i = 0;
    while (i < _dsPhim.size() && _dsPhim[i]->getYear() <= phim->getYear()) {
        i++;
    }

    _dsPhim.insert(i, phim);
}

void QLPhim::writeToFile() {
    ofstream fout("ds_phim.dat", ios::binary);
    if (fout.fail()) {
        cout << "Failed to open file" << endl;
        return;
    }
    for (int i = 0; i < _dsPhim.size(); i++) {
        fout.write((char*)&(*_dsPhim[i]), sizeof(Phim));
    }
    cout << "Write to file successfully" << endl;
}

void QLPhim::readFromFile() {
    ifstream fin("ds_phim.dat", ios::binary);
    if (fin.fail()) {
        cout << "Failed to open file" << endl;
        return;
    }
    Phim* phim = new Phim();
    while (fin.read((char*) phim, sizeof(phim))) {
        _dsPhim.push(phim);
        phim = new Phim();
    }
    cout << "Read from file successfully" << endl;
}

void QLPhim::deleteHBO() {
    int j = 0;
    for (int i = 0; i < _dsPhim.size() ; i++) {
        if (strcmp(_dsPhim[i]->getProceducer(), "HBO") != 0) {
            _dsPhim[j++] = _dsPhim[i];
        }
    }
    _dsPhim.resize(j);
    writeToFile();
}