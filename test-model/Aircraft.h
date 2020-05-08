//
// Created by sweethuman on 03.05.2020.
//

#ifndef TEST_MODEL_AIRCRAFT_H
#define TEST_MODEL_AIRCRAFT_H
#include <string>

class Aircraft {
protected:
    int id;
    std::string model;
    std::string suitable_activity;//military, transportation, medical, leisure
    int max_altitude;

public:
    Aircraft(){};
    Aircraft(const Aircraft &other);
    Aircraft(int id, std::string model, std::string suitable_activity, int max_altitude) : id(id), model(model), suitable_activity(suitable_activity), max_altitude(max_altitude){};
    Aircraft &operator=(const Aircraft &other);
    bool operator==(const Aircraft &other);
    int getId() const;
    std::string getModel();
    std::string getSuitableActivity();
    int getMaxAltitude();
    virtual std::string toString();
};

class Helicopter : public Aircraft {
private:
    bool isPrivate;

public:
    Helicopter(const Helicopter &other);
    Helicopter(int id, std::string model, std::string suitable_activity, int max_altitude, bool isPrivate) : Aircraft(id, model, suitable_activity, max_altitude), isPrivate(isPrivate){};
    bool getPrivate();
    std::string toString() override;

};

class Plane : public Aircraft {
private:
    bool isPrivate;
    std::string wings;//monoplane, biplane
public:
    Plane(const Plane &other);
    Plane(int id, std::string model, std::string suitable_activity, int max_altitude, bool isPrivate, std::string wings) : Aircraft(id, model, suitable_activity, max_altitude), isPrivate(isPrivate), wings(wings) {};\
    bool getPrivate();
    std::string getWings();
    std::string toString() override;
};

class Balloon : public Aircraft {
private:
    int weightLimit;
public:
    Balloon(const Balloon &other);
    Balloon(int id, std::string model, std::string suitable_activity, int max_altitude, int weightLimit) : Aircraft(id, model, suitable_activity, max_altitude), weightLimit(weightLimit) {};
    int getWeightLimit();
    std::string toString() override;
};
#endif//TEST_MODEL_AIRCRAFT_H
