#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <limits>
#include <string.h>
using namespace std;
class convertor{
public:
    virtual void input() = 0;
    virtual void output() = 0;
};
class length : public convertor{
    map<string, double> conversionFactors;
    string inUnit, outUnit;
    double value;
public:
    length(){
        conversionFactors["meter"] = 1;
        conversionFactors["centimeter"] = 0.01;
        conversionFactors["millimeter"] = 0.001;
        conversionFactors["kilometer"] = 1000;
        conversionFactors["yard"] = 0.914399;
        conversionFactors["mile"] = 1609.269391;
        conversionFactors["foot"] = 0.304799;
        conversionFactors["inch"] = 0.0254;
    }
    void input(){
        cout<< "Enter input unit i.e from which unit you want to convert: ";
        cin>> inUnit;
        cout<< "Enter output unit i.e into which unit you want to convert: ";
        cin>> outUnit;
        // Convert units to lowercase
        for(char &c : inUnit) {
            c = tolower(c);
        }
        for(char &c : outUnit) {
            c = tolower(c);
        }
    }
    void output(){
        if (conversionFactors.find(inUnit) != conversionFactors.end() &&
            conversionFactors.find(outUnit) != conversionFactors.end()) {
            // Units are valid perform conversion
            cout<< "Enter the value that needs to convert: ";
            cin>> value;
            double result = value * conversionFactors[inUnit] / conversionFactors[outUnit];
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<< value << " " << inUnit << " is equal to " << result << " " << outUnit << endl;
        } else{
            cout<< "INVALID EXPRESSION" << endl;
        }
    }
};
class area : public convertor{
    map<string, double> conversionFactors;
    string inUnit, outUnit;
    long double value;
public:
    area(){
        conversionFactors["square meter"] = 1;
        conversionFactors["square centimeter"] = 0.0001;
        conversionFactors["square millimeter"] = 0.000001;
        conversionFactors["square kilometer"] = 1000000;
        conversionFactors["square yard"] = 0.83612739;
        conversionFactors["hectare"] = 10000;
        conversionFactors["square foot"] = 0.09290304;
        conversionFactors["square inch"] = 0.00064516;
        conversionFactors["acre"] = 4046.94455685;
    }
    void input(){
        cout<<"Enter input unit i.e from which unit you want to convert: ";
        getline(cin,inUnit);
        cout<<"Enter output unit i.e into which unit you want to convert: ";
        getline(cin,outUnit);
        for (char &c : inUnit) {
            c = tolower(c);
        }
        for (char &c : outUnit) {
            c = tolower(c);
        }
    }
    void output(){
        if(conversionFactors.find(inUnit) != conversionFactors.end() &&
            conversionFactors.find(outUnit) != conversionFactors.end()) {
            cout<<"Enter the value that needs to convert: ";
            cin>>value;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            double result = value * conversionFactors[inUnit] / conversionFactors[outUnit];
            cout<< value << " " << inUnit << " is equal to " << result << " " << outUnit << endl;
        } else{
            cout<< "INVALID EXPRESSION" << endl;
        }
    }
};
class volume : public convertor{
    map<string, double> conversionFactors;
    string inUnit, outUnit;
    double value;
public:
    volume(){
        conversionFactors["cubic centimeter"] = 1;
        conversionFactors["cubic meter"] = 1000000;
        conversionFactors["centiliter"] = 10;
        conversionFactors["liter"] = 1000;
        conversionFactors["cubic millimeter"] = 0.001;
        conversionFactors["milliliter"] = 1;
        conversionFactors["cubic foot"] = 28316.8;
    }
    void input(){
        cout << "Enter input unit i.e from which unit you want to convert: ";
        getline(cin,inUnit);
        cout << "Enter output unit i.e into which unit you want to convert: ";
        getline(cin,outUnit);
        for (char &c : inUnit) {
            c = tolower(c);
        }
        for (char &c : outUnit) {
            c = tolower(c);
        }
    }
    void output(){
        if (conversionFactors.find(inUnit) != conversionFactors.end() &&
            conversionFactors.find(outUnit) != conversionFactors.end()) {
            cout << "Enter the value that needs to convert: ";
            cin >> value;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            double result = value * conversionFactors[inUnit] / conversionFactors[outUnit];
            cout << value << " " << inUnit << " is equal to " << result << " " << outUnit << endl;
        } else {
            cout << "INVALID EXPRESSION" << endl;
        }
    }
};
class speed : public convertor {
    map<string, double> conversionFactors;
    string inUnit, outUnit;
    double value;
public:
    speed() {
        conversionFactors["meter per second"] = 1;
        conversionFactors["inch per second"] = 0.0254;
        conversionFactors["mile per hour"] = 0.44704;
        conversionFactors["kilometer per hour"] = 0.27778;
        conversionFactors["kilometer per second"] = 1000;
        conversionFactors["foot per second"] = 0.3048;
    }
    void input(){
        cout << "Enter input unit i.e from which unit you want to convert: ";
        getline(cin,inUnit);
        cout << "Enter output unit i.e into which unit you want to convert: ";
        getline(cin,outUnit);
        for (char &c : inUnit) {
            c = tolower(c);
        }
        for (char &c : outUnit) {
            c = tolower(c);
        }
    }
    void output(){
        if (conversionFactors.find(inUnit) != conversionFactors.end() &&
            conversionFactors.find(outUnit) != conversionFactors.end()) {
            cout << "Enter the value that needs to convert: ";
            cin >> value;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            double result = value * conversionFactors[inUnit] / conversionFactors[outUnit];
            cout << value << " " << inUnit << " is equal to " << result << " " << outUnit << endl;
        } else {
            cout << "INVALID EXPRESSION" << endl;
        }
    }
};
class weight : public convertor{
    map<string, double> conversionFactors;
    string inUnit, outUnit;
    double value;
public:
    weight(){
        conversionFactors["gram"] = 1;
        conversionFactors["kilogram"] = 1000;
        conversionFactors["milligram"] = 0.001;
        conversionFactors["ounce"] = 28.3495;
        conversionFactors["pound"] = 453.592;
        conversionFactors["tone"] = 1000000;
        conversionFactors["quintal"] = 100;
        conversionFactors["stone"] = 6.35;
        conversionFactors["carat"] = 0.2;
    }
    void input(){
        cout << "Enter input unit i.e from which unit you want to convert: ";
        cin >> inUnit;
        cout << "Enter output unit i.e into which unit you want to convert: ";
        cin >> outUnit;
        for (char &c : inUnit){
            c = tolower(c);
        }
        for (char &c : outUnit){
            c = tolower(c);
        }
    }
    void output(){
        if (conversionFactors.find(inUnit) != conversionFactors.end() &&
            conversionFactors.find(outUnit) != conversionFactors.end()) {
            cout << "Enter the value that needs to convert: ";
            cin >> value;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            double result = value * conversionFactors[inUnit] / conversionFactors[outUnit];
            cout << value << " " << inUnit << " is equal to " << result << " " << outUnit << endl;
        } else {
            cout << "INVALID EXPRESSION" << endl;
        }
    }
};
class temperature : public convertor{
      double t;
      char fromUnit[100], toUnit[100];  
      public:
      void input(){
        cout << "Enter input unit i.e from which unit you want to convert: ";
        cin >> fromUnit;
        cout << "Enter output unit i.e into which unit you want to convert: ";
        cin >> toUnit;
        cout << "Enter the value that needs to convert: ";
        cin >> t;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
      }
      void output(){
          double a = fun(t,fromUnit,toUnit);
          if(int(a)==-1){
              return;
          }
          else{
            cout << "Converted temperature: " << a << " " << toUnit << endl;
          }
      }
double fun(double value, char *f, char* t){
    if (strcmp(f,t) == 0){
        return value;
    }
    if(strcmp(f,"celsius") == 0){
         if(strcmp(t,"reaumur") == 0){
             return value * 0.8;
         }
         else if(strcmp(t,"kelvin") == 0){
             return value + 273.15;
         }
         else if(strcmp(t,"fahrenheit") == 0){
             return (value * 9/5) + 32;
         }
         else{
                    cout << "Invalid to unit\n";
                    return -1;
         }
    }
    else if(strcmp(f,"reaumur") == 0){
         if(strcmp(t,"celsius") == 0){
             return value * 1.25;
         }
         else if(strcmp(t,"kelvin") == 0){
             return (value * 5/4) + 273.15;
         }
         else if(strcmp(t,"fahrenheit") == 0){
             return (value * 9/4) + 32;
         }
         else{
                    cout << "Invalid to unit\n";
                    return -1;
         }
    }
    else if(strcmp(f,"fahrenheit") == 0){
             if(strcmp(t,"reaumur") == 0){
             return (value - 32) * 4/9;
         }
         else if(strcmp(t,"kelvin") == 0){
             return (value - 32) * 5/9 + 273.15;
         }
         else if(strcmp(t,"celsius") == 0){
             return (value - 32) * 5/9;
         }
         else{
                    cout << "Invalid to unit\n";
                    return -1;
         }
    }
    else if(strcmp(f,"kelvin") == 0){
         if(strcmp(t,"reaumur") == 0){
             return (value - 273.15) * 4/5;
         }
         else if(strcmp(t,"celsius") == 0){
              return value - 273.15;
         }
         else if(strcmp(t,"fahrenheit") == 0){
             return (value - 273.15) * 9/5 + 32;
         }
         else{
                    cout << "Invalid to unit\n";
                    return -1;
         }
    }
    else{
                    cout << "Invalid to unit\n";
                    return -1;
    }
}
};
class power : public convertor{
    map<string, double> conversionFactors;
    string inUnit, outUnit;
    double value;
public:
    power(){
        conversionFactors["watt"] = 1;
        conversionFactors["kilowatt"] = 1000;
        conversionFactors["metric horse power"] = 735.498;
        conversionFactors["joule per second"] = 1;
        conversionFactors["kilogram-meter per second"] = 9.806;
        conversionFactors["imperial horse power"] = 745.699;
        conversionFactors["newton-meter per second"] = 1;
    }
    void input(){
        cout << "Enter input unit i.e from which unit you want to convert: ";
        getline(cin,inUnit);
        cout << "Enter output unit i.e into which unit you want to convert: ";
        getline(cin,outUnit);
        for (char &c : inUnit){
            c = tolower(c);
        }
        for (char &c : outUnit){
            c = tolower(c);
        }
    }
    void output(){
        if (conversionFactors.find(inUnit) != conversionFactors.end() &&
            conversionFactors.find(outUnit) != conversionFactors.end()){
            cout << "Enter the value that needs to convert: ";
            cin >> value;
            double result = value * conversionFactors[inUnit] / conversionFactors[outUnit];
            cout << value << " " << inUnit << " is equal to " << result << " " << outUnit << endl;
        } else{
            cout << "INVALID EXPRESSION" << endl;
        }
    }
};
class pressure : public convertor{
    map<string, double> conversionFactors;
    string inUnit, outUnit;
    double value;
public:
    pressure(){
        conversionFactors["kilopascal"] = 0.009869;
        conversionFactors["pounds per square foot"] = 0.0004725;
        conversionFactors["pounds per square inch"] = 0.068045;
        conversionFactors["bar"] = 0.986923;
        conversionFactors["atmospheric pressure"] = 1;
    }
    void input(){
        cout << "Enter input unit i.e from which unit you want to convert: ";
        getline(cin,inUnit);
        cout << "Enter output unit i.e into which unit you want to convert: ";
        getline(cin,outUnit);
        for (char &c : inUnit){
            c = tolower(c);
        }
        for (char &c : outUnit){
            c = tolower(c);
        }
    }
    void output(){
        if (conversionFactors.find(inUnit) != conversionFactors.end() &&
            conversionFactors.find(outUnit) != conversionFactors.end()) {
            cout << "Enter the value that needs to convert: ";
            cin >> value;
            double result = value * conversionFactors[inUnit] / conversionFactors[outUnit];
            cout << value << " " << inUnit << " is equal to " << result << " " << outUnit << endl;
        } else {
            cout << "INVALID EXPRESSION" << endl;
        }
    }
};
void mainMenu();
void funLength();
void funArea();
void funVolume();
void funSpeed();
void funWeight();
void funTemp();
void funPower();
void funPressure();
int main(){
    cout<<"---------------------------------------- WELCOME TO CONVERTOR APPLICATION ------------------------------------------------------"<<endl;
    int n;
    convertor * c;
    cout<<"\n\t\t\t\tENTER RESPECTIVE NUMBER FOR SPECIFIC UNIT CONVERSION"<<endl;
    cout<<"\n------> ENTER 1 FOR LENGTH CONVERSION"<<endl;
    cout<<"------> ENTER 2 FOR AREA CONVERSION"<<endl;
    cout<<"------> ENTER 3 FOR VOLUME CONVERSION"<<endl;
    cout<<"------> ENTER 4 FOR SPEED CONVERSION"<<endl;
    cout<<"------> ENTER 5 FOR WEIGHT CONVERSION"<<endl;
    cout<<"------> ENTER 6 FOR TEMPERATURE CONVERSION"<<endl;
    cout<<"------> ENTER 7 FOR POWER CONVERSION"<<endl;
    cout<<"------> ENTER 8 FOR PRESSURE CONVERSION"<<endl;
    cout<<"------> ENTER 0 TO CLOSE THE APPLICATION"<<endl;
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------\n"<<endl;
    while(1){
        cout<<"CLICK APPROPRIATE NUMBER FOR SPECIFIC CONVERSION : ";
        cin>>n;
        cout<<endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(n == 1){
             c = new length();
             funLength();
             c->input();
             c->output();
             cout<<endl;
             char st[10];
             while(1){
                cout<<"Do you want to continue in this length conversion? If so enter (yes): ";
                cin>>st;
            for (char &c : st){
            c = tolower(c);
            }
                cout<<endl;
                if(strcmp(st,"yes") == 0){
                    c->input();
                    c->output();
                    cout<<endl;
                }
                else{
                    cout<<"----------------------------------GOING BACK TO MAIN MENU ----------------------------------"<<endl;
                    mainMenu();
                    break;
                }
             }
        }
        else if(n == 2){
            c = new area();
             funArea();
             c->input();
             c->output();
             cout<<endl;
             char st[10];
             while(1){
                cout<<"Do you want to continue in this area conevrsion? If so enter YES: ";
                cin>>st;
            for (char &c : st){
            c = tolower(c);
            }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<endl;
                if(strcmp(st,"yes") == 0){
                    c->input();
                    c->output();
                    cout<<endl;
                }
                else{
                    cout<<"---------------------------------- GOING BACK TO MAIN MENU ----------------------------------"<<endl;
                    mainMenu();
                    break;
                }
             }
        }
        else if(n == 3){
            c = new volume();
             funVolume();
             c->input();
             c->output();
             cout<<endl;
             char st[10];
             while(1){
                cout<<"Do you want to continue in this volume conversion? If so enter YES: ";
                cin>>st;
            for (char &c : st){
            c = tolower(c);
            }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<endl;
                if(strcmp(st,"yes") == 0){
                    c->input();
                    c->output();
                    cout<<endl;
                }
                else{
                    cout<<"---------------------------------- GOING BACK TO MAIN MENU ----------------------------------"<<endl;
                    mainMenu();
                    break;
                }
             }
        }
        else if(n == 4){
            c = new speed();
             funSpeed();
             c->input();
             c->output();
             cout<<endl;
             char st[10];
             while(1){
                cout<<"Do you want to continue in this volume conversion? If so enter YES: ";
                cin>>st;
            for (char &c : st){
            c = tolower(c);
            }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<endl;
                if(strcmp(st,"yes") == 0){
                    c->input();
                    c->output();
                    cout<<endl;
                }
                else{
                    cout<<"---------------------------------- GOING BACK TO MAIN MENU ----------------------------------"<<endl;
                    mainMenu();
                    break;
                }
             }
        }
        else if(n == 5){
             c = new weight();
             funWeight();
             c->input();
             c->output();
             cout<<endl;
             char st[10];
             while(1){
                cout<<"Do you want to continue in this Weight conversion? If so enter YES: ";
                cin>>st;
            for (char &c : st){
            c = tolower(c);
            }
                cout<<endl;
                if(strcmp(st,"yes") == 0){
                    c->input();
                    c->output();
                    cout<<endl;
                }
                else{
                    cout<<"---------------------------------- GOING BACK TO MAIN MENU ----------------------------------"<<endl;
                    mainMenu();
                    break;
                }
             }
        }
        else if(n == 6){
             c = new temperature();
             funTemp();
             c->input();
             c->output();
             cout<<endl;
             char st[10];
             while(1){
                cout<<"Do you want to continue in this temperature conversion? If so enter (yes): ";
                cin>>st;
            for (char &c : st){
            c = tolower(c);
            }
                cout<<endl;
                if(strcmp(st,"yes") == 0){
                    c->input();
                    c->output();
                    cout<<endl;
                }
                else{
                    cout<<"----------------------------------GOING BACK TO MAIN MENU ----------------------------------"<<endl;
                    mainMenu();
                    break;
                }
             }
        }
        else if(n == 7){
            c = new power();
             funPower();
             c->input();
             c->output();
             cout<<endl;
             char st[10];
             while(1){
                cout<<"Do you want to continue in this power conversion? If so enter YES: ";
                cin>>st;
            for (char &c : st){
            c = tolower(c);
            }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<endl;
                if(strcmp(st,"yes") == 0){
                    c->input();
                    c->output();
                    cout<<endl;
                }
                else{
                    cout<<"---------------------------------- GOING BACK TO MAIN MENU ----------------------------------"<<endl;
                    mainMenu();
                    break;
                }
             }
        }
        else if(n == 8){
            c = new pressure();
             funPressure();
             c->input();
             c->output();
             cout<<endl;
             char st[10];
             while(1){
                cout<<"Do you want to continue in this pressure conversion? If so enter YES: ";
                cin>>st;
            for (char &c : st){
            c = tolower(c);
            }
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<endl;
                if(strcmp(st,"yes") == 0){
                    c->input();
                    c->output();
                    cout<<endl;
                }
                else{
                    cout<<"---------------------------------- GOING BACK TO MAIN MENU ----------------------------------"<<endl;
                    mainMenu();
                    break;
                }
             }
        }
        else if(n == 0){
            cout<<"---------------- THANK YOU FOR USING APPLICATION ----------------";
            break;
        }
        else{
            cout<<"---------------- INVALID INPUT TRY AGAIN ---------------"<<endl;
        }
    }
}
void mainMenu(){
        cout<<"\n\t\t\t\tENTER RESPECTIVE NUMBER FOR SPECIFIC UNIT CONVERSION"<<endl;
    cout<<"\n------> ENTER 1 FOR LENGTH CONVERSION"<<endl;
    cout<<"------> ENTER 2 FOR AREA CONVERSION"<<endl;
    cout<<"------> ENTER 3 FOR VOLUME CONVERSION"<<endl;
    cout<<"------> ENTER 4 FOR SPEED CONVERSION"<<endl;
    cout<<"------> ENTER 5 FOR WEIGHT CONVERSION"<<endl;
    cout<<"------> ENTER 6 FOR TEMPERATURE CONVERSION"<<endl;
    cout<<"------> ENTER 7 FOR POWER CONVERSION"<<endl;
    cout<<"------> ENTER 8 FOR PRESSURE CONVERSION"<<endl;
    cout<<"------> ENTER 0 TO CLOSE THE APPLICATION\n"<<endl;
    cout<<"---------------------------------------------------------------------------------------------\n"<<endl;
}
void funLength(){
    cout<<"--------------------- UNITS AVAILABILE IN PHYSICAL QUANTITY LENGTH ---------------------"<<endl;
    cout<<"1. Meter"<<endl;
    cout<<"2. Centimeter"<<endl;
    cout<<"3. Millimeter"<<endl;
    cout<<"4. Kilometer"<<endl;
    cout<<"5. Yard"<<endl;
    cout<<"6. Mile"<<endl;
    cout<<"7. Foot"<<endl;
    cout<<"8. Inch"<<endl;
}
void funArea(){
    cout<<"--------------------- UNITS AVAILABILE IN PHYSICAL QUANTITY AREA   ---------------------"<<endl;
    cout<<"1. Square Meter"<<endl;
    cout<<"2. Square Centimeter"<<endl;
    cout<<"3. Square Millimeter"<<endl;
    cout<<"4. Square Kilometer"<<endl;
    cout<<"5. Square Yard"<<endl;
    cout<<"6. Hectare"<<endl;
    cout<<"7. Square Foot"<<endl;
    cout<<"8. Square Inch"<<endl;
    cout<<"9. Acre"<<endl;
}
void funVolume(){
    cout<<"--------------------- UNITS AVAILABILE IN PHYSICAL QUANTITY VOLUME ---------------------"<<endl;
    cout<<"1. Cubic Centimeter"<<endl;
    cout<<"2. Cubic Meter"<<endl;
    cout<<"3. Centiliter"<<endl;
    cout<<"4. Liter"<<endl;
    cout<<"5. Cubic Millimeter"<<endl;
    cout<<"6. Milliliter"<<endl;
    cout<<"7. Cubic Foot"<<endl;
}
void funSpeed(){
    cout<<"--------------------- UNITS AVAILABILE IN PHYSICAL QUANTITY SPEED  ---------------------"<<endl;
    cout<<"1. Meter per second"<<endl;
    cout<<"2. Inch per second"<<endl;
    cout<<"3. Mile per hour"<<endl;
    cout<<"4. Kilometer per hour"<<endl;
    cout<<"5. Kilometer per second"<<endl;
    cout<<"6. Foot per second"<<endl;
}
void funWeight(){
    cout<<"--------------------- UNITS AVAILABILE IN PHYSICAL QUANTITY WEIGHT ---------------------"<<endl;
    cout<<"1. Gram"<<endl;
    cout<<"2. Kilogram"<<endl;
    cout<<"3. Milligram"<<endl;
    cout<<"4. Ounce"<<endl;
    cout<<"5. Pound"<<endl;
    cout<<"6. Tone"<<endl;
    cout<<"7. Quintal"<<endl;
    cout<<"8. Stone"<<endl;
    cout<<"9. Carat"<<endl;
}
void funTemp(){
    cout<<"--------------------- UNITS AVAILABILE IN PHYSICAL QUANTITY TEMPERATURE ---------------------"<<endl;
    cout<<"1. Reaumur"<<endl;
    cout<<"2. Kelvin"<<endl;
    cout<<"3. Celsius"<<endl;
    cout<<"4. Fahrenheit"<<endl;
}
void funPower(){
    cout<<"--------------------- UNITS AVAILABILE IN PHYSICAL QUANTITY POWER ---------------------"<<endl;
    cout<<"1. Watt"<<endl;
    cout<<"2. Kilowatt"<<endl;
    cout<<"3. Metric horse power"<<endl;
    cout<<"4. Joule per second"<<endl;
    cout<<"5. Kilogram-meter per second"<<endl;
    cout<<"6. Imperial horse power"<<endl;
    cout<<"7. Newton-meter per second"<<endl;
}
void funPressure(){
    cout<<"--------------------- UNITS AVAILABILE IN PHYSICAL QUANTITY PRESSURE ---------------------"<<endl;
    cout<<"1. Kilopascal"<<endl;
    cout<<"2. Pounds per square foot"<<endl;
    cout<<"3. Pounds per square inch"<<endl;
    cout<<"4. Bar"<<endl;
    cout<<"5. Atmospheric pressure"<<endl;
}