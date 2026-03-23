// polymorhism is the ability of an object to take on many forms
// it has 2 types static(Method overloading) and dynamic polymorphism (Method overriding)
// static polymorphism is the ability of an object to take on many forms at compile time
// dynamic polymorphism is the ability of an object to take on many forms at runtime


#include<iostream>
using namespace std;

class Car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;

    public:
        Car(string a,string b){
            this->brand = a;
            this->model = b;
            isEngineOn = false;
            currentSpeed = 0;
        }

        void startEngine(){
            if(this->isEngineOn){
                cout<<this->brand<<" of "<<this->model<<" :The Engine is already started"<<endl;
                return;
            }
            this->isEngineOn = true;
            cout<<this->brand<<" of "<<this->model<<" :The Engine is started"<<endl;
        }

        void stopEngine(){
            if(!this->isEngineOn){
                cout<<this->brand<<" of "<<this->model<<" :The Engine is already stopped"<<endl;
                return;
            }
            this->isEngineOn = false;
            this->currentSpeed = 0;
            cout<<this->brand<<" of "<<this->model<<" :The Engine is stopped"<<endl;
        }

        virtual void accelerate() = 0; // this is a pure virtual function -> yeh ek aisa function hota hai jiska implementation derived class me hota hai aur ye
        virtual void brake() = 0;
        virtual ~Car(){};
};

class ManualCar : public Car{
    int currentGear;

    public:
        ManualCar(string a,string b):Car(a,b){
            this->currentGear = 0;
        }

        void shiftGear(int gear){
            if(!this->isEngineOn){
                cout<<this->brand<<" of "<<this->model<<" : Engine is OFF"<<endl;
                return;
            }
            this->currentGear = gear;
            cout<<this->brand<<" of "<<this->model<<" :Shifted to gear"<<this->currentGear<<endl;
        }

        //overriding accelerate

        void accelerate() override{
            if(!this->isEngineOn){
                cout<<this->brand<<" of "<<this->model<<" : Engine is OFF"<<endl;
                return;
            }
            this->currentSpeed += 20;
            cout<<this->brand<<" of "<<this->model<<" :Accelerated to "<<this->currentSpeed<<" kmph"<<endl;
        }

        void brake() override{
            if(!this->isEngineOn){
                cout<<this->brand<<" of "<<this->model<<" : Engine is OFF"<<endl;
                return;
            }
            this->currentSpeed -= 20;
            if(currentSpeed < 0){
                this->currentSpeed = 0;
            }
            cout<<this->brand<<" of "<<this->model<<" :Braked to "<<this->currentSpeed<<" kmph"<<endl;
        }
};

class ElectricCar : public Car{
    int battery;

    public:
        ElectricCar(string a, string b) : Car(a,b){
            this->battery = 100;
        }

        void chargeBattery(){
            this->battery=100;
            cout<<this->brand<<" of "<<this->model<<" :Battery is fully charged"<<endl;
        }

        void accelerate() override{
            if(!this->isEngineOn){
                cout<<this->brand<<" of "<<this->model<<" : Engine is OFF"<<endl;
                return;
            }
            this->currentSpeed += 15;
            cout<<this->brand<<" of "<<this->model<<" :Accelerated to "<<this->currentSpeed<<" kmph"<<endl;
        }

        void brake() override{
            if(!this->isEngineOn){
                cout<<this->brand<<" of "<<this->model<<" : Engine is OFF"<<endl;
                return;
            }
            this->currentSpeed -= 15;
            if(currentSpeed < 0){
                this->currentSpeed = 0;
            }
            cout<<this->brand<<" of "<<this->model<<" :Braked to "<<this->currentSpeed<<" kmph"<<endl;
        }
};

int main(){

    Car* myManualCar = new ManualCar("Suzuki" , "WagonR");

    myManualCar->startEngine();
    //myManualCar->shiftGear(1);
    myManualCar->accelerate();
    //myManualCar->shiftGear(2); shift gear is not present in car
    myManualCar->accelerate();
    myManualCar->brake();

    cout<<endl;

    Car* myElectricCar = new ElectricCar("Tesla" , "Model S");

    myElectricCar->startEngine();
    // myElectricCar->chargeBattery();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myManualCar;
    delete myElectricCar;

    return 0;
}