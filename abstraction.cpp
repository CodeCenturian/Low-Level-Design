#include<iostream>
#include<string>
using namespace std;

// Abstract class

//virtual function -> yeh ek aisa function hota hai jiska implementation derived class me hota hai.
class Car{
    public:
    virtual void startEngine() = 0; // Pure virtual function
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car(){}
};

class SportsCar : public Car {
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentGear;
        int currentSpeed;

        SportsCar(string brand, string model){ //ye constructor hota hai, jo derived class me hota hai
            this->brand = brand;
            this->model = model;
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout<<brand<<" of "<<model<<" :The Engine is started"<<endl;
        }

        void shiftGear(int gear){
            if(!isEngineOn){
                cout<<brand<<" of "<<model<<" : Engine is OFF"<<endl;
                return;
            }
            currentGear = gear;
            cout<<brand<<" of "<<model<<" :Shifted to gear"<<currentGear<<endl;
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

        void stopEngine(){
            isEngineOn = false;
            currentGear =0;
            currentSpeed = 0;
            cout<<brand<<" of "<<model<<" :The Engine is stopped"<<endl;
        }


};

int main(){

    Car* myCar = new SportsCar("Ford" , "Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;
    return 0;
}