#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <ctime>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

struct Residents {
    string lastName;
    string firstName;
    string dateOfBirth;
    string address;
    string phone;
};

int main() {
    locale::global(locale{ ".UTF-8" });
    string path = "residents.json";
    vector<Residents> resident;

    fstream file(path, ios::in);

    if (file.is_open()) {
        json residents{ json::parse(file) };

        for (size_t i = 0; i < residents["Residents"].size(); i++) {
            resident.push_back(Residents{ residents["Residents"][i]["Last_name"], residents["Residents"][i]["First_name"], residents["Residents"][i]["Date_of_birth"], residents["Residents"][i]["Address"], residents["Residents"][i]["Phone"] });
        }
    }

    for (Residents R : resident) {
        cout << R.lastName << " " << R.firstName << " " << R.dateOfBirth << " " << R.address << " " << R.phone << endl;
    }

    cout << endl;

    cout << resident[0].address << ":" << endl;
    for (size_t i = 0; i < resident.size(); i++) {
        if (resident[i].address == resident[0].address) {
            cout << resident[i].lastName << " " << resident[i].firstName << endl;
        }
    }
    cout << endl;

    cout << resident[1].address << ":" << endl;
    for (size_t i = 0; i < resident.size(); i++) {
        if (resident[i].address == resident[1].address) {
            cout << resident[i].lastName << " " << resident[i].firstName << endl;
        }
    }
    cout << endl;

    cout << resident[2].address << ":" << endl;
    for (size_t i = 0; i < resident.size(); i++) {
        if (resident[i].address == resident[2].address) {
            cout << resident[i].lastName << " " << resident[i].firstName << endl;
        }
    }
}