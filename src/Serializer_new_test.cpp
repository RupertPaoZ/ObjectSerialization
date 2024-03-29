#include "Serializer_new.h"
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int i, i0                   = 3;
    pair<string, int> psi, psi0 = make_pair("Good", 123);
    vector<int> vi, vi0         = {1, 3, 5, 7};
    list<int> li, li0           = {2, 4, 6, 8};
    set<int> si, si0            = {6, 7, 33, 9, 81, 31, 54};
    map<string, int> msi, msi0  = {pair<string, int>("SC", 666), pair<string, int>("cx", 999)};
    int *pi, *pi0               = &i0;
    int *pai;
    int pai0[] = {1, 45, 6, 3, 2};
    unique_ptr<int> upi, upi0     = unique_ptr<int>(new int(19));
    unique_ptr<int[]> upai, upai0 = unique_ptr<int[]>(new int[5]);
    shared_ptr<int> spi, spi0     = shared_ptr<int>(new int(89));

    for (auto i = 0; i < 5; i++)
        upai0[i] = (i + 1) * (i + 1);

    ofstream ofile;
    ifstream ifile;
    const string path = "/Users/Ulysses/Desktop/Terminal Saved Output.txt";

    vector<int> _vi1 = {2, 3, 4}, _vi2 = {5, 6, 7};
    map<string, int> _msi = {pair<string, int>("SC", 2), pair<string, int>("cx", 3)};
    set<string> _ss       = {"Hello", "World", "I", "Am"};
    pair<map<string, int>, set<string>> pmsiss, pmsiss0 = make_pair(_msi, _ss);

    ofile.open(path);
    ifile.open(path);
    enum typelist { ari, pair, vec, list, ptr, ptra, uptr, uptra, sptr, set, map, rr };

    switch (typelist(rr)) {
        case typelist(ari):
            ser::Serializer(i0, ofile);
            ofile.close();
            des::Deserializer(i, ifile);
            break;

        case typelist(pair):
            ser::Serializer(psi0, ofile);
            ofile.close();
            des::Deserializer(psi, ifile);
            break;

        case typelist(vec):
            ser::Serializer(vi0, ofile);
            ofile.close();
            des::Deserializer(vi, ifile);
            break;

        case typelist(list):
            ser::Serializer(li0, ofile);
            ofile.close();
            des::Deserializer(li, ifile);
            break;

        case typelist(ptr):
            ser::Serializer(pi0, ofile);
            ofile.close();
            des::Deserializer(pi, ifile);
            break;

        case typelist(ptra):
            ser::Serializer(pai0, ofile, 5);
            ofile.close();
            des::Deserializer(pai, ifile);
            for (auto i = 0; i < 5; i++)
                cerr << pai[i] << " ";
            break;

        case typelist(uptr):
            ser::Serializer(upi0, ofile);
            ofile.close();
            des::Deserializer(upi, ifile);
            break;

        case typelist(uptra):
            ser::Serializer(upai0, ofile, 5);
            ofile.close();
            des::Deserializer(upai, ifile);
            for (auto i = 0; i < 5; i++)
                cerr << upai[i] << " ";
            break;

        case typelist(sptr):
            ser::Serializer(spi0, ofile);
            ofile.close();
            des::Deserializer(spi, ifile);
            break;

        case typelist(set):
            ser::Serializer(si0, ofile);
            ofile.close();
            des::Deserializer(si, ifile);
            break;

        case typelist(map):
            ser::Serializer(msi0, ofile);
            ofile.close();
            des::Deserializer(msi, ifile);
            break;
        case typelist(rr):
            ser::Serializer(pmsiss0, ofile);
            ofile.close();
            des::Deserializer(pmsiss, ifile);
            break;
    }

    return 0;
}
