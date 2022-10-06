/**
 * Joe Vassallo
 * CS 124
 * OL1
*/
#ifndef PROJECT_1_DIVE_H
#define PROJECT_1_DIVE_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <set>

/**
 * Class representing logged foraging dives of Gentoo penguins.
 * 
 * tagNumber: Tag # of the diving penguin
 * seaFloorDepth: Sea floor depth at the latitude and longitude the dive was recorded
 * latitude: Latitude at the time the dive is recorded
 * longitude: Longitude at the time the dive is recorded
 * distanceToLand: Distance from the point the dive is recorded to land
 * seaSurfaceTemp: Temperature of the surface of the sea when/where the dive is recorded
 * seaIceConcentration: Concentration of sea ice when/where the dive is recorded.
 * dateTimeOfDive: Time the dive is recorded
 * lifeStage: If the penguin is an adult or juvenile (juv)
 * colony: Colony identifier of the penguin
 * locationAccuracy: Accuracy code of the location
*/

class Dive {
private:
    int tagNumber, seaFloorDepth;
    double latitude, longitude, distanceToLand, seaSurfaceTemp, seaIceConcentration;
    std::string dateTimeOfDive, lifeStage, colony;
    char locationAccuracy;

public:
    Dive() {
        tagNumber = 000000;
        dateTimeOfDive = "1/1/2017 00:00";
        locationAccuracy = 'B';
        latitude = -62;
        longitude = -60;
        lifeStage = "adult";
        colony = "CAS";
        distanceToLand = 1;
        seaSurfaceTemp = 2;
        seaIceConcentration = 0;
        seaFloorDepth = -100;
    }

    Dive(int tagNumber, std::string dateTimeOfDive, char locationAccuracy, double latitude, double longitude, std::string lifeStage, std::string colony, double distanceToLand, double seaSurfaceTemp, double seaIceConcentration, int seaFloorDepth) {
        this->tagNumber = tagNumber;
        this->dateTimeOfDive = dateTimeOfDive;
        this->locationAccuracy = locationAccuracy;
        this->latitude = latitude;
        this->longitude = longitude;
        this->lifeStage = lifeStage;
        this->colony = colony;
        this->distanceToLand = distanceToLand;
        this->seaSurfaceTemp = seaSurfaceTemp;
        this->seaIceConcentration = seaIceConcentration;
        this->seaFloorDepth = seaFloorDepth;
    }

    // Setters

    void setTagNumber(int tagNumber) {
        this->tagNumber = tagNumber;
    }

    void setDateTimeOfDive(std::string dateTimeOfDive) {
        this->dateTimeOfDive = dateTimeOfDive;
    }

    void setLocationAccuracy(char locationAccuracy) {
        this->locationAccuracy = locationAccuracy;
    }

    void setLatitude(double latitude) {
        this->latitude = latitude;
    }

    void setLongitude(double longitude) {
        this->longitude = longitude;
    }

    void setLifeStage(std::string lifeStage) {
        this->lifeStage = lifeStage;
    }

    void setColony(std::string colony) {
        this->colony = colony;
    }

    void setDistanceToLand(double distanceToLand) {
        this->distanceToLand = distanceToLand;
    }

    void setSeaSurfaceTemp(double seaSurfaceTemp) {
        this->seaSurfaceTemp = seaSurfaceTemp;
    }

    void setSeaIceConcentration(double seaIceConcentration) {
        this->seaIceConcentration = seaIceConcentration;
    }

    void setSeaFloorDepth(int seaFloorDepth) {
        this->seaFloorDepth = seaFloorDepth;
    }

    // Getters

    int getTagNumber() const {
        return tagNumber;
    }

    std::string getDateTimeOfDive() const {
        return dateTimeOfDive;
    }

    char getLocationAccuracy() const {
        return locationAccuracy;
    }

    double getLatitude() const {
        return latitude;
    }

    double getLongitude() const {
        return longitude;
    }

    std::string getLifeStage() const {
        return lifeStage;
    }

    std::string getColony() const {
        return colony;
    }

    double getDistanceToLand() const {
        return distanceToLand;
    }

    double getSeaSurfaceTemp() const {
        return seaSurfaceTemp;
    }

    double getSeaIceConcentration() const {
        return seaIceConcentration;
    }

    int getSeaFloorDepth() const {
        return seaFloorDepth;
    }

    /**
         * Overload insertion operator
        */
    friend std::ostream &operator<<(std::ostream &outs, const Dive &dive) {
        outs << std::setw(6) << dive.getTagNumber()
             << std::setw(17) << dive.getDateTimeOfDive()
             << std::setw(4) << dive.getLocationAccuracy()
             << std::setw(9) << dive.getLatitude()
             << std::setw(10) << dive.getLongitude()
             << std::setw(6) << dive.getLifeStage()
             << std::setw(7) << dive.getColony()
             << std::setw(11) << dive.getDistanceToLand();

             if (dive.getSeaSurfaceTemp() == 12345) outs << std::setw(11) << "N/A";
             else outs << std::setw(11) << dive.getSeaSurfaceTemp();

             outs << std::setw(10) << dive.getSeaIceConcentration();

             if (dive.getSeaFloorDepth() == 12345) outs << std::setw(12) << "N/A";
             else outs << std::setw(12) << dive.getSeaFloorDepth();
        return outs;
    }

    friend bool operator < (const Dive& lhs, const Dive& rhs) {
        return lhs.getDistanceToLand() < rhs.getDistanceToLand();
    }

    /**
     * Overload > operator for object comparison
     */
    friend bool operator > (const Dive& lhs, const Dive& rhs) {
        return lhs.getDistanceToLand() > rhs.getDistanceToLand();
    }

    /**
     * Overload <= operator for object comparison
     */
    friend bool operator <= (const Dive& lhs, const Dive& rhs) {
        return lhs.getDistanceToLand() <= rhs.getDistanceToLand();
    }

    /**
     * Overload >= operator for object comparison
     */
    friend bool operator >= (const Dive& lhs, const Dive& rhs) {
        return lhs.getDistanceToLand() >= rhs.getDistanceToLand();
    }

    /**
     * Overload == operator for object comparison
     */
    friend bool operator == (const Dive& lhs, const Dive& rhs) {
        return lhs.getDistanceToLand() == rhs.getDistanceToLand();
    }

    /**
     * Overload != operator for object comparison
     */
    friend bool operator != (const Dive& lhs, const Dive& rhs) {
        return lhs.getDistanceToLand() != rhs.getDistanceToLand();
    }
};

/**
 * Reads a list of dives into a vector of dives.
*/

void readDivesFromFile(std::string fileName, std::vector<Dive> &dives) {
    std::ifstream fIn;
    bool isFirstLine = true;
    fIn.open(fileName);
    std::string garbage = "";
    if (fIn) {
        std::string header;
        getline(fIn, header);
    }

    while (fIn && fIn.peek() != EOF) {
        int tagNumber = 0, seaFloorDepth = 0;
        std::string dateTimeOfDive = "", lifeStage = "", colony = "";
        char locationAccuracy = ' ', comma = ',', na = 'N';
        double latitude = 0, longitude = 0, distanceToLand = 0, seaSurfaceTemp = 0, seaIceConcentration = 0;

        if (!isFirstLine) getline(fIn, garbage);
        isFirstLine = false;

        fIn >> tagNumber;
        fIn >> comma;
        getline(fIn, dateTimeOfDive, comma);

        fIn >> locationAccuracy;
        fIn >> comma;

        fIn >> latitude;
        fIn >> comma;

        fIn >> longitude;
        fIn >> comma;

        getline(fIn, lifeStage, comma);

        getline(fIn, colony, comma);

        fIn >> distanceToLand;
        fIn >> comma;

        // 12345 is a number that should never come up in the data with N/A values, so I'm using it as a flag that the number isn't there.

        if (fIn.peek() == na) {
            seaSurfaceTemp = 12345;
            getline(fIn, garbage, comma);
        }
        else {
            fIn >> seaSurfaceTemp;
            fIn >> comma;
        }

        // N/A = No sea ice worth measuring
        if (fIn.peek() == na) {
            seaIceConcentration = 0;
            getline(fIn, garbage, comma);
        }
        else {
            fIn >> seaIceConcentration;
            fIn >> comma;
        }

        if (fIn.peek() == na) {
            seaFloorDepth = 12345;
        }
        else {
            fIn >> seaFloorDepth;
        }

        Dive dive(tagNumber, dateTimeOfDive, locationAccuracy, latitude, longitude, lifeStage, colony, distanceToLand, seaSurfaceTemp, seaIceConcentration, seaFloorDepth);
        dives.push_back(dive);
    }
    fIn.close();
}

// Tests all getters, setters, and the dive constructor.

void diveTest() {
    Dive diveObj = Dive();

    diveObj.setTagNumber(12345);
    assert(diveObj.getTagNumber() == 12345);

    diveObj.setDateTimeOfDive("1/1/2020 00:00");
    assert(diveObj.getDateTimeOfDive() == "1/1/2020 00:00");

    diveObj.setLocationAccuracy('2');
    assert(diveObj.getLocationAccuracy() == '2');

    diveObj.setLatitude(-64);
    assert(diveObj.getLatitude() == -64);

    diveObj.setLongitude(-60);
    assert(diveObj.getLongitude() == -60);

    diveObj.setLifeStage("juv");
    assert(diveObj.getLifeStage() == "juv");

    diveObj.setColony("CVA");
    assert(diveObj.getColony() == "CVA");

    diveObj.setDistanceToLand(9500);
    assert(diveObj.getDistanceToLand() == 9500);

    diveObj.setSeaSurfaceTemp(2.5);
    assert(diveObj.getSeaSurfaceTemp() == 2.5);

    diveObj.setSeaIceConcentration(0.57352);
    assert(diveObj.getSeaIceConcentration() == 0.57352);

    diveObj.setSeaFloorDepth(-100);
    assert(diveObj.getSeaFloorDepth() == -100);

    Dive diveObj2 = Dive(12345, "1/1/2020 00:00", '2', -64, -60, "juv", "CVA", 9500, 2.5, 0.57352, -100);

    assert(diveObj2.getTagNumber() == 12345);

    assert(diveObj2.getDateTimeOfDive() == "1/1/2020 00:00");

    assert(diveObj2.getLocationAccuracy() == '2');

    assert(diveObj2.getLatitude() == -64);

    assert(diveObj2.getLongitude() == -60);

    assert(diveObj2.getLifeStage() == "juv");

    assert(diveObj2.getColony() == "CVA");

    assert(diveObj2.getDistanceToLand() == 9500);

    assert(diveObj2.getSeaSurfaceTemp() == 2.5);

    assert(diveObj2.getSeaIceConcentration() == 0.57352);

    assert(diveObj2.getSeaFloorDepth() == -100);
}

// Counts number of unique tagged birds.
int countPenguins(std::vector<Dive> &dives) {
    int runningTotal = 0;
    std::set<int> seenPengs;

    for (Dive &dive : dives) {
        if (!seenPengs.count(dive.getTagNumber())) {
            runningTotal++;
            seenPengs.insert(dive.getTagNumber());
        }
    }

    return runningTotal;
}

/**
 * Displays a table of the accuracy results.
 * Z results were removed from the database by the researchers who made it. 
*/
void displayLocationAccuracyStats(std::vector<Dive> &dives)
{
    int a = 0, b = 0, z = 0, zero = 0, one = 0, two = 0, three = 0, total;
    for (Dive &dive : dives) {
        switch (dive.getLocationAccuracy()) {
        case '3':
            three++;
            break;
        case '2':
            two++;
            break;
        case '1':
            one++;
            break;
        case '0':
            zero++;
            break;
        case 'A':
            a++;
            break;
        case 'B':
            b++;
            break;
        case 'Z':
            z++;
            break;
        default:
            std::cout << "help" << std::endl;
        }
    }

    total = a + b + z + zero + one + two + three;

    std::cout << std::endl;
    std::cout << "Accuracy stats" << std::endl;
    std::cout << "A" << std::right << std::setw(15)
              << a << std::endl
              << "B" << std::right << std::setw(15)
              << b << std::endl
              << "Z" << std::right << std::setw(15)
              << z << std::endl
              << "0" << std::right << std::setw(15)
              << zero << std::endl
              << "1" << std::right << std::setw(15)
              << one << std::endl
              << "2" << std::right << std::setw(15)
              << two << std::endl
              << "3" << std::right << std::setw(15)
              << three << std::endl
              << std::endl
              << "Total:" << std::right << std::setw(10)
              << total << std::endl;
}

/**
 * Opens and counts the number of lines in the file, and compares it to the 
*/
bool verifyCount(std::string fileName, std::vector<Dive> &dives)
{
    std::ifstream fIn;
    int i = 0;
    std::string line;
    fIn.open(fileName);
    if (fIn)
    {
        std::string header;
        getline(fIn, header);
        // Content of line doesn't matter, only a line's existence matters.
        while (std::getline(fIn, line))
        {
            i++;
        }
    }

    fIn.close();
    return i == dives.size();
}

#endif //PROJECT_1_DIVE_H