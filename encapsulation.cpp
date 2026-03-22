#include<iostream>
using namespace std;

class SportsCar {
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentGear;
        int currentSpeed;
        string tyres;

    public:
        SportsCar(string brand, string model){ //ye constructor hota hai, jo derived class me hota hai
            this->brand = brand;
            this->model = model;
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            tyres = "MRF";
        }
        // getters for getting the tyres
        string getTyres(){
            return this->tyres;
        }
        // setters for the setting the value of the tyres
        // thhese are combined used with validation and error handling
        void setTyres(string tyres){
            cout<<" The tyres are changed from "<<this->tyres<<" to "<<tyres<<endl;
            this->tyres = tyres;
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

    SportsCar* myCar = new SportsCar("Ford" , "Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    //works only when the attributes are public
    //cout<<myCar->brand<<" of "<<myCar->model<<" :The current speed is "<<myCar->currentSpeed<<" kmph"<<endl;

    // we can access via getter and setters examples tyres.
    cout<<"The tyres my car has are of "<<myCar->getTyres()<<endl;

    //setters calling
    myCar->setTyres("Pirelli");
    cout<<"The tyres my car has are of "<<myCar->getTyres()<<endl;

    delete myCar;
    return 0;
}
