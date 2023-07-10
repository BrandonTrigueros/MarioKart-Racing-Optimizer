// #include <gtest/gtest.h>
// #include "Driver/Driver.hpp"
// #include "Driver/KartDriver.hpp"
// #include "Driver/MotorcycleDriver.hpp"
// #include "Driver/ATVDriver.hpp"
// #include "Parts/Vehicle.hpp"
// #include "Parts/PartS.hpp"
// #include "RBTree.hpp"
// #include "Garage.hpp"


// using namespace testing;

// TEST(TestingGetters, TestTire)
// {
//     partS rueda("Rueda1", 15, 16, 17);
//     EXPECT_EQ (rueda.getLand(), 15);
// }

// TEST(TestingGetters, TestGlider)
// {
//     partS glider("Glider1", 15, 17);
//     EXPECT_EQ (glider.getAir(), 17);
// }

// TEST(TestingGetters, TestVehicle)
// {
//     Vehicle vehicle("vehicle1", 15, 17);
//     EXPECT_EQ (vehicle.getBaseSpeed(), 17);
// }

// TEST(TestingGetters, TestValidDriver)
// {
//     partS* rueda = new partS("Rueda1", 15, 16, 17);
//     partS* glider = new partS("Glider1", 15, 17);
//     Vehicle* vehicle= new Vehicle("vehicle1", 15, 17);
//     KartDriver driver ("Driver1", "PersonajePrueba", rueda, glider, vehicle);
//     EXPECT_EQ (driver.getTag(), "Driver1");
//     delete rueda;
//     delete glider;
//     delete vehicle;
// }

// TEST(TestingKartDriver, TestGetTimeLand) {
//     partS* rueda = new partS("Wood", 50, 20, 10);
//     partS* glider = new partS("Cloud Glidr", 58, 6);
//     Vehicle* vehicle = new Vehicle("B Dasher", 3.1, 20);
//     KartDriver driver ("Pepe", "Goku", rueda, glider, vehicle);
    
//     double esperado = (17351);
//     double actual = driver.get_time_land(1500);
    
//     EXPECT_DOUBLE_EQ(esperado, actual);
//     delete rueda;
//     delete glider;
//     delete vehicle;
// }

// TEST(TestingKartDriver, TestGetTimeAir) {
//     partS* rueda = new partS("Wood", 50, 20, 10);
//     partS* glider = new partS("Cloud Glidr", 58, 6);
//     Vehicle* vehicle = new Vehicle("B Dasher", 3.1, 20);
//     KartDriver driver ("Pepe", "Goku", rueda, glider, vehicle);
    
//     double esperado = (2305.2);
//     double actual = driver.get_time_air(200);
    
//     EXPECT_NEAR(esperado, actual, 0.1);
//     delete rueda;
//     delete glider;
//     delete vehicle;
// }

// TEST(TestingKartDriver, TestGetTimeWater) {
//     partS* rueda = new partS("Rueda1", 15, 16, 17);
//     partS* glider = new partS("Glider1", 15, 17);
//     Vehicle* vehicle = new Vehicle("vehicle1", 15, 17);
//     KartDriver driver("Driver1", "PersonajePrueba", rueda, glider, vehicle);

//     double esperado = (0);
//     double actual = driver.get_time_water(0);

//     EXPECT_DOUBLE_EQ(esperado, actual);

//     delete rueda;
//     delete glider;
//     delete vehicle;
// }

// TEST(TestingKartDriver, TestGetTime) {
//     partS* rueda = new partS("Wood", 50, 20, 10);
//     partS* glider = new partS("Cloud Glidr", 58, 6);
//     Vehicle* vehicle = new Vehicle("B Dasher", 3.1, 20);
//     KartDriver driver("Brandon", "Vegeta777", rueda, glider, vehicle);

//     double esperado_land = (17351);
//     double esperado_water = (0);
//     double esperado_air = (2305.2);

//     double actual = driver.getTime(1500, 0, 200);

//     EXPECT_NEAR(esperado_land + esperado_water + esperado_air, actual, 0.1);

//     delete rueda;
//     delete glider;
//     delete vehicle;
// }

// TEST (TestingTree, TestSearch) {
//     Garage *garage = new Garage("input/pieces.csc", "input/players.csv");
//     garage->loadFiles(false);
//     partS* glider = new partS("Cloud Glidr", 58, 6);
//     partS* found = garage->getGlidersT()->search(garage->getGlidersT()->getRoot(), "Cloud Glider");
//     EXPECT_EQ(glider, found);
//     delete glider;
//     delete garage;
//     delete found;
// }

// TEST (TestingTree, TestSearchInvalid) {
//     Garage *garage = new Garage("input/pieces.csc", "input/players.csv");
//     garage->loadFiles(false);
//     partS* notFound = garage->getGlidersT()->search(garage->getGlidersT()->getRoot(), "GG");
//     EXPECT_EQ(nullptr, notFound);
//     delete garage;
//     delete notFound;
// }

// int main(int argc, char *argv[])
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

