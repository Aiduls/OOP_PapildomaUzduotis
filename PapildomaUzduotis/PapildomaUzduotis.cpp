#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <fstream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iomanip>

void isrinktiZodzius(std::string &tekstas);
void istrintiZenklus(std::string &zodis);
void suskaiciuotiZodzius(std::vector<std::string> sarasas);
void sukurtiLentele(int eiluciuKiekis);
bool arLinkas(std::string zodis);
void spausdintiLinkus();

const char simboliai[] = ",.;:\"!?–_\n\t*()@#=+„“";
std::map<std::string, int> zodziai;
std::multimap<std::string, int> eilutes;
std::vector<std::string> linkai;

int main()
{
    std::ifstream ifs("tekstas.txt");
    std::string tekstas((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    const int eiluciuKiekis = std::count(tekstas.begin(), tekstas.end(), '\n');

    isrinktiZodzius(tekstas);

    sukurtiLentele(eiluciuKiekis);

    spausdintiLinkus();
}

void isrinktiZodzius(std::string &tekstas)
{
    int eilute = 1;
    std::string zodis;
    std::string sakinys;

    std::istringstream ss(tekstas);
    std::ofstream ofs("rez.txt");
    std::vector<std::string> sarasas;
    
    do {   
        std::cout << eilute << std::endl;

        std::getline(ss, sakinys);

        std::istringstream ss2(sakinys);
        while (ss2) {
            ss2 >> zodis;
            std::cout << "antro while eilute: " << eilute << " ir zodis: " << zodis << std::endl;
            if (!arLinkas(zodis)) {
                istrintiZenklus(zodis);

                if (zodis.length() > 1) {
                    sarasas.push_back(zodis);
                    eilutes.insert({ zodis, eilute });
                }
            }
            if (ss2.eof()) break;
        } 

        eilute++;
    } while (ss);

    suskaiciuotiZodzius(sarasas);
}

void istrintiZenklus(std::string &zodis)
{
    for (int i = 0; i < sizeof(simboliai); i++) {
        zodis.erase(std::remove(zodis.begin(), zodis.end(), simboliai[i]), zodis.end());
    }
}

void suskaiciuotiZodzius(std::vector<std::string> sarasas)
{
    std::map<std::string, int>::iterator it;
    std::ofstream ofs("rez.txt");

    for (std::string zodis : sarasas) {
        it = zodziai.find(zodis);

        if (it != zodziai.end()) {
            zodziai[zodis]++;
        }
        else {
            zodziai.insert({ zodis, 1 });
        }
    }

    for (it = zodziai.begin(); it != zodziai.end(); ++it) {
        if (it->second > 1) {
            ofs << std::left << std::setw(3) << std::to_string(it->second) << it->first << std::endl;
        }
    }
}

void sukurtiLentele(int eiluciuKiekis)
{
    std::multimap<std::string, int>::iterator it;
    std::ofstream ofs("xref.txt");

    ofs << "|"; 
    for (int i = 1; i <= eiluciuKiekis; i++) {
        ofs << std::left<<std::setw(5) << std::to_string(i) << "|";
    }
    ofs << std::endl;

    for (auto x : zodziai) {
        if (x.second > 1) {
            ofs << "|";
            for (int i = 1; i <= eiluciuKiekis; i++) {
                if (eilutes.count(x.first) > 0 && x.second == i) {
                    ofs << "  x  |";
                }
                else ofs << "     |";
            }
            ofs << x.first << "\n";
        }
    }
    ofs << "\n"; 
}

bool arLinkas(std::string zodis)
{
    if (zodis.rfind("http", 0) == 0 || zodis.rfind("www", 0) == 0) {
        linkai.push_back(zodis);
        return true;
    }
    else
        return false;
}

void spausdintiLinkus()
{
    std::ofstream ofs("linkai.txt");

    if (linkai.size() == 0) {
        ofs << "Linku tekste nera." << std::endl;
    }
    else {
        for (auto x : linkai) {
            ofs << x << std::endl;
        }
    }
}