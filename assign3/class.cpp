#include "class.h"

Station::Station() : charge(5), licenses() {}

Station::Station(int charge) : licenses() { this->charge = charge; }

void Station::setStart(const std::string id, int st) {
    if (this->licenses.count(id)) {
        this->licenses[id] = st;
    }
}

void Station::setCharge(int charge) { this->charge = charge; }

// ENTER license_id xx:xx
// LEAVE license_id xx:xx
void Station::record(std::string input) {
    std::string op, id, hour, mi;
    std::istringstream is(input);
    is >> op >> id;

    getline(is, hour, ':');
    getline(is, mi);
    int h = stoi(hour), m = stoi(mi);
    if (m != 0) {
        h++;
    }

    if (op == "ENTER") {
        if (!this->licenses.count(id)) {
            this->licenses.insert({id, h});
        } else {
            this->licenses[id] = h;
        }
    } else if (op == "LEAVE") {
        if (this->licenses.count(id)) {
            std::cout << (h - this->licenses[id]) * this->charge << '\n';
            this->licenses.erase(id);
        }
    }
}

int Station::getCharge() const { return this->charge; }

bool Station::find(std::string id) { return this->licenses[id]; }

Station::~Station() {}
