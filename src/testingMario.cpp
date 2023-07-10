#include <gtest/gtest.h>
#include "Garage.hpp"
#include "IOHandler.hpp"
#include "Driver/Driver.hpp"
#include "Driver/KartDriver.hpp"
#include "Driver/ATVDriver.hpp"
#include "Driver/MotorcycleDriver.hpp"
using namespace testing;


TEST(TestInvalidDrivers, GetTimeTest)
{
    KartDriver kartDriver("Prueba1", "PersonajePrueba");
    EXPECT_EQ (kartDriver.getTime(100 , 100 , 100), 0);
    ATVDriver kartDriver("Prueba1", "PersonajePrueba");
    EXPECT_EQ (kartDriver.getTime(100 , 100 , 100), 0);
    KartDriver kartDriver("Prueba1", "PersonajePrueba");
    EXPECT_EQ (kartDriver.getTime(100 , 100 , 100), 0);
}

class testingMario : public ::testing::Test
{
protected:
    Garage garage;
//    IOHandler IOHandler;

protected:
    void SetUp() override {
        garage.loadFiles(false, "input/players.csv", "input/parts.csv");
    }
};

TEST_F (testingMario, calculaATVTimeAir){
    Driver* atvDriver = testingMario.garage.getDriversT()->searchPerNumber(1);
    double time = 451.1;
    ASSERT_TRUE(atvDriver->get_time_air(200), time);
}

TEST_F (testingMario, calculaKartTimeAir){
    Driver* kartDriver = testingMario->garage.getDriversT()->searchPerNumber(12);
    double time = 233.1;
    ASSERT_TRUE(kartDriver->get_time_air(200), time);
}
TEST_F (testingMario, calculabikeTimeAir){
    Driver* bikeDriver = testingMario->garage.getDriversT()->searchPerNumber(8);
    double time = 512.7892;
    ASSERT_TRUE(bikeDriver->get_time_air(200), time);
}

TEST_F (testingMario, calculaATVTimeland){
    Driver* atvDriver = testingMario->garage.getDriversT()->searchPerNumber(1);
    double time = 451.1;
    ASSERT_TRUE(atvDriver->get_time_land(200), time);
}

TEST_F (testingMario, calculaKartTimeland){
    Driver* kartDriver = testingMario->garage.getDriversT()->searchPerNumber(12);
    double time = 233.1;
    ASSERT_TRUE(kartDriver->get_time_land(200), time);
}
TEST_F (testingMario, calculabikeTimeland){
    Driver* bikeDriver = testingMario->garage.getDriversT()->searchPerNumber(8);
    double time = 112.5;
    ASSERT_TRUE(bikeDriver->get_time_land(200), time);
}
TEST_F (testingMario, calculaATVTimewater){
    Driver* atvDriver = testingMario->garage.getDriversT()->searchPerNumber(1);
    double time = 751.1;
    ASSERT_TRUE(atvDriver->get_time_water(200), time);
}

TEST_F (testingMario, calculaKartTimewater){
    Driver* kartDriver = testingMario->garage.getDriversT()->searchPerNumber(12);
    double time = 833.1;
    ASSERT_TRUE(kartDriver->get_time_water(200), time);
}
TEST_F (testingMario, calculabikeTimewater){
    Driver* bikeDriver = testingMario.garage.getDriversT()->searchPerNumber(8);
    double time = 1112.5;
    ASSERT_TRUE(bikeDriver->get_time_water(200), time);
}


TEST_F (testingMario, testSearchVehicleT){
    ASSERT_FALSE (testingMario->garage.getVehiclesT(), nullptr);
}

TEST_F (testingMario, testSearchTiresT){
    ASSERT_FALSE (testingMario->garage.getTiresT(), nullptr);
}

TEST_F (testingMario, testSearchGlidersT){
    ASSERT_FALSE (testingMario->garage.getGlidersT(), nullptr);
}



