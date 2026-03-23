#include<iostream>
using namespace std;

class Car{ // base class
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;

    public:
        Car(string a , string b){
            this->brand = a;
            this->model = b;
            isEngineOn = false;
            currentSpeed = 0;
        }

        // common methods for all cars
        void startEngine(){
            isEngineOn = true;
            cout<<brand<<" of "<<model<<" :The Engine is started"<<endl;
        }
        void stopEngine(){
            isEngineOn = false;
            currentSpeed = 0;
            cout<<brand<<" of "<<model<<" :The Engine is stopped"<<endl;
        }
        void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" of "<<model<<" : Engine is OFF"<<endl;
                return;
            }
            currentSpeed += 20;
            cout<<brand<<" of "<<model<<" :Accelerated to "<<currentSpeed<<" kmph"<<endl;
        }

        void brake(){
            if(!isEngineOn){
                cout<<brand<<" of "<<model<<" : Engine is OFF"<<endl;
                return;
            }
            currentSpeed -= 20;
            cout<<brand<<" of "<<model<<" :Braked to "<<currentSpeed<<" kmph"<<endl;
        }

        virtual ~Car(){};
};

class ManualCar : public Car{
    private:
        int currentGear = 0;

    public:
    // this is the constructor
        ManualCar(string a , string b) : Car(a , b){
            currentGear = 0;
        };

        // specialized methods for manual cars
        void shiftGear(int gear){
            if(!isEngineOn){
                cout<<brand<<" of "<<model<<" : Engine is OFF"<<endl;
                return;
            }
            currentGear = gear;
            cout<<brand<<" of "<<model<<" :Shifted to gear"<<currentGear<<endl;
        }

};

class ElectricCar : public Car{
    private:
        int battery = 100;

    public:
    // this is the constructor
        ElectricCar(string a, string b) :Car(a,b){
            battery = 100;
        }

        void chargeBattery(){
            battery = 100;
            cout<<brand<<" of "<<model<<" :Battery is fully charged"<<endl;
        }
};

int main(){

    ManualCar* myManualCar = new ManualCar("Suzuki" , "WagonR");

    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->shiftGear(2);
    myManualCar->accelerate();
    myManualCar->brake();
    
    cout<<endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla" , "Model S");

    myElectricCar->startEngine();
    myElectricCar->chargeBattery();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myManualCar;
    delete myElectricCar;

    return 0;
}