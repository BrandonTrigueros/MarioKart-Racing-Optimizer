#include <gtest/gtest.h>
#include "Driver/Driver.hpp"
#include "Driver/KartDriver.hpp"
#include "Driver/ATVDriver.hpp"
#include "Driver/MotorcycleDriver.hpp"
#include "Parts/Vehicle.hpp"
#include "Parts/PartS.hpp"


using namespace testing;

TEST(TestingMario, CeroToCero)
{
    EXPECT_EQ (0, 0);
}

TEST(TestingMario, Testrueda)
{
    partS rueda("Rueda1", 15, 16, 17);
    EXPECT_EQ (rueda.getLand(), 15);
}

TEST(TestingMario, Testglider)
{
    partS glider("Glider1", 15, 17);
    EXPECT_EQ (glider.getAir(), 17);
}

TEST(TestingMario, Testvehicle)
{
    Vehicle vehicle("vehicle1", 15, 17);
    EXPECT_EQ (vehicle.getBaseSpeed(), 17);
}

// TEST(TestingMario, TestValidDriver)
// {
//     partS* rueda = new partS("Rueda1", 15, 16, 17);
//     partS* glider = new partS("Glider1", 15, 17);
//     Vehicle* vehicle= new Vehicle("vehicle1", 15, 17);
//     KartDriver driver ("Driver1", "PersonajePrueba", rueda, glider, vehicle);
//     EXPECT_EQ (driver.getTag(), "Driver1");
// }

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
//TEST_F (testingMario, calculaKartTimeAir){
//    Driver* kartDriver = garage->getDriversT()->searchPerNumber(12);
//    double time = 233.1;
//    ASSERT_EQ(kartDriver->get_time_air(200), time);
//}
//TEST_F (testingMario, calculabikeTimeAir){
//    Driver* bikeDriver = garage->getDriversT()->searchPerNumber(8);
//    double time = 512.7892;
//    ASSERT_EQ(bikeDriver->get_time_air(200), time);
//}

//TEST_F (testingMario, calculaATVTimeland){
//    Driver* atvDriver = garage->getDriversT()->searchPerNumber(1);
//    double time = 451.1;
//    ASSERT_EQ(atvDriver->get_time_land(200), time);
//}

//TEST_F (testingMario, calculaKartTimeland){
//    Driver* kartDriver = garage->getDriversT()->searchPerNumber(12);
//    double time = 233.1;
//    ASSERT_EQ(kartDriver->get_time_land(200), time);
//}
//TEST_F (testingMario, calculabikeTimeland){
//    Driver* bikeDriver = garage->getDriversT()->searchPerNumber(8);
//    double time = 112.5;
//    ASSERT_EQ(bikeDriver->get_time_land(200), time);
//}
//TEST_F (testingMario, calculaATVTimewater){
//    Driver* atvDriver = garage->getDriversT()->searchPerNumber(1);
//    double time = 751.1;
//    ASSERT_EQ(atvDriver->get_time_water(200), time);
//}

//TEST_F (testingMario, calculaKartTimewater){
//    Driver* kartDriver = garage->getDriversT()->searchPerNumber(12);
//    double time = 833.1;
//    ASSERT_EQ(kartDriver->get_time_water(200), time);
//}
//TEST_F (testingMario, calculabikeTimewater){
//    Driver* bikeDriver = garage->getDriversT()->searchPerNumber(8);
//    double time = 1112.5;
//    ASSERT_EQ(bikeDriver->get_time_water(200), time);
//}


//TEST_F (testingMario, testSearchVehicleT){
//    ASSERT_NE (garage->getVehiclesT(), nullptr);
//}

//TEST_F (testingMario, testSearchTiresT){
//    ASSERT_NE (garage->getTiresT(), nullptr);
//}

//TEST_F (testingMario, testSearchGlidersT){
//    ASSERT_NE (garage->getGlidersT(), nullptr);
//}



