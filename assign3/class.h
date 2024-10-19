#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>

class Station {
  public:
    Station();
    Station(int charge);
    void record(std::string input);
    void setStart(const std::string id, int st);
    void setCharge(int charge);
    int getCharge() const;
    ~Station();

  private:
    std::map<std::string, int> licenses;
    bool find(std::string id);
    int charge;
};
