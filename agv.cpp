#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
using namespace std ;
struct GARBAGE {
    double gx;
    double gy;
    double gz;
    double D;  // Distance from AGV
    
    bool operator<(const GARBAGE& other) const {
        return D < other.D;  // Sort by distance in ascending order
    }
};
struct DOF {
            double x ;
            double y ;
            double z ;
        
        };
class AGV_ARM {
    public :
    double cx , cy, cz ;
    
    AGV_ARM( double ci , double cj , double ck){
        cx = ci ;
        cy = cj ;
        cz = ck ;

        
     }
        
     };
class AGV {
    public :
    double x ;
    double y ; 
    double z ;
    int battery_level ;
    string garbage_type;
    AGV_ARM arm ;
    DOF joints[6];
    vector<GARBAGE> garbage_list; 
    AGV(AGV_ARM a,DOF j_init[6],  double i , double j , double k , int b , string g):arm(a){
        x = i ;
        y = j ;
        z = k ;
        battery_level = b ;
        garbage_type = g ;
        for(int i = 0;i<6 ;i++){
            joints[i] = j_init[i] ;
        }
    }
    void garbage_locations(){
        int n;
        GARBAGE g;
    cout<<"enter number of garbage list";
    cin>>n;
    for(int i = 0; i < n ; i++ ){
        cout<<" enter garbage list"<<" "<<i<<" ";
        cin>> g.gx>>g.gy>>g.gz;
        garbage_list.push_back(g);
        }
        for(int i = 0 ; i< garbage_list.size();i++){
            cout<<"location of garbage"<<i<<":"<<" ";
            cout<< garbage_list[i].gx<<" " << garbage_list[i].gy<<" " <<garbage_list[i].gz<<endl;
        }
    }
    void move_arm_to_garbage(GARBAGE g ){
        double move = 1;
        if( joints[5].x < g.gx){
            joints[5].x += move;
            cout<<joints[5].x <<endl;
        }
        else if(joints[5].x > g.gx){
            joints[5].x -= move;
            cout<<joints[5].x <<endl;
        }
        if( joints[5].y < g.gy){
            joints[5].y += move;
            cout<<joints[5].y <<endl;
        }
        else if(joints[5].y > g.gy){
            joints[5].y -= move;
            cout<<joints[5].y <<endl;
        }
        if( joints[5].z < g.gz){
            joints[5].z += move;
            cout<<joints[5].z <<endl;
        }
        else if(joints[5].z > g.gz){
            joints[5].z -= move;
            cout<<joints[5].z <<endl;


    } 
}
    
void throw_garbage_to_collector(){
    double rotate = 1;
    if(joints[5].x < arm.cx){
        joints[5].x += rotate ;
        cout<<joints[5].x<<endl;
    }
         else if ( joints[5].x>arm.cx){
            joints[5].x -= rotate;
            cout<< joints[5].x<<endl;
         }
         if(joints[5].y < arm.cy){
        joints[5].y += rotate ;
        cout<<joints[5].y<<endl;
    }
         else if ( joints[5].y>arm.cy){
            joints[5].y -= rotate;
            cout<<joints[5].y<<endl;
         }
         if(joints[5].z < arm.cz){
        joints[5].z += rotate ;
        cout<<joints[5].z<<endl;
    }
         else if ( joints[5].z > arm.cz){
            joints[5].z -= rotate;
            cout<<joints[5].z<<endl;
         }   
    
}
    void moveTo(GARBAGE target)  {
        
        double step_size = 1.00 ;
         if(target.gx > x){
            x+=step_size ;
            cout<<x<<endl;
         }
         else if(target.gx<x) {
            x-=step_size;
            cout<<x<<endl;
         }
         if(target.gy > y){
            y+=step_size ;
            cout<<y<<endl;
         }
         else if(target.gy<y){
            y-=step_size;
            cout<<y<<endl;
         }
         if(target.gz > z){
            z+=step_size ;
            cout<<z<<endl;
         }
         else if(target.gz<z) {
            z-=step_size;
            cout<<z<<endl;
         }
        
    }  
    void check_battery(){
        if(battery_level < 20){
            cout<<"plug in the agv";
        }
            else{
                cout<< "battery is fine"<<endl;
        }
    }
    void report_status(){
        cout <<"\n"<<"battery level is :"<<" "<< battery_level<<"\n"<<"x = "<<" "<< x <<" "<<"y ="<<" "<<y<<" "<<"z = "<<" "<< z <<"\n"<<"garbage type is :"<<" "<<garbage_type<<endl;
    }
    void report_full_status(){

        check_battery();

    
        report_status();
    }
    void sorting_distance(GARBAGE &sort ){
       sort. D =  sqrt( (x- sort.gx)*(x- sort.gx) + (y-sort.gy)*(y-sort.gy) + (z-sort.gz)*(z-sort.gz));
    }
    void print_distance(){
        
        for(int i =0 ; i<garbage_list.size();i++){
        cout<<"The distance agv from garbage at location "<<" "<<i<<" "<<"is"<<" "<<garbage_list[i].D<<endl;
    }
    }
    
    void sorting_location(){
    
    for(int i = 0; i < garbage_list.size(); i++){
        sorting_distance(garbage_list[i]);
    }

    sort(garbage_list.begin(), garbage_list.end(), [](const GARBAGE &a, const GARBAGE &other){
        return a.D < other.D;
    });
}
    };
 int main(){ 

    DOF joints[6];
        for(int i = 0 ; i<6 ; i ++){
            cout<<"Enter the X coordinate of joint"<<" "<<i;
             cin>> joints[i].x;
             cout<<"Enter the Y coordinate of joint"<<" "<<i;
            cin>> joints[i].y;
             cout<<"Enter the Z coordinate of joint"<<" "<<i;
             cin>> joints[i].z;
        }
        for(int i = 0 ; i<6 ; i++){
            cout<< "The coordiantes of joint"<<i<<" "<<"x ="<<" "<<joints[i].x<<" "<<" y ="<<" "<<joints[i].y<<" "<<"z ="<<" "<<joints[i].z<<endl;
        } 
    AGV_ARM arm1(7,5,2);
    AGV model1( arm1 ,joints,2 , 4 , 6 , 10, "Biodegradable");
    model1.report_full_status();
    
    for(int i = model1.battery_level  ; i >= 20;i--){
        
        if (model1.battery_level >= 20){
            model1.garbage_locations();
    for(int i = 0 ; i<model1.garbage_list.size();i++){
    model1.sorting_distance(model1.garbage_list[i]);
    }
    model1.print_distance();
    for(int i = 0 ; i<model1.garbage_list.size();i++){
        model1.sorting_location();
        cout<< " The"<<" " <<i<<" "<<"nearest garbage location"<<"  "<<"is"<<" "<< model1.garbage_list[i].gx<<" "<<model1.garbage_list[i].gy<<" "<<model1.garbage_list[i].gz<<"\n";

        }    
        for(int i = 0 ; i < model1.garbage_list.size(); i++){
    while(!(model1.x == model1.garbage_list[i].gx && model1.y == model1.garbage_list[i].gy && model1.z == model1.garbage_list[i].gz )) {
        model1.moveTo(model1.garbage_list[i]);
    }
        if(model1.x == model1.garbage_list[i].gx && model1.y == model1.garbage_list[i].gy && model1.z == model1.garbage_list[i].gz ){
        cout << "AGV reached garbage position!"<<" "<<i<<"\n" ;
        
    }

    while(!(model1.joints[5].x == model1.garbage_list[i].gx && model1.joints[5].y == model1.garbage_list[i].gy && model1.joints[5].z == model1.garbage_list[i].gz)){
        model1.move_arm_to_garbage(model1.garbage_list[i]);
    }
    if(model1.joints[5].x == model1.garbage_list[i].gx && model1.joints[5].y == model1.garbage_list[i].gy && model1.joints[5].z == model1.garbage_list[i].gz){
    
    cout<<"garbage is picked up at location"<<i<<" \n";
    
}
    
    while(!(model1.joints[5].x == model1.arm.cx && model1.joints[5].y == model1.arm.cy && model1.joints[5].z == model1.arm.cz)){
        model1.throw_garbage_to_collector();
    }

    if(model1.joints[5].x == model1.arm.cx && model1.joints[5].y == model1.arm.cy && model1.joints[5].z == model1.arm.cz){
     cout<<"garbage is collected in box at location"<<i<<"\n";
}
        }
        } 
         
}
        if(model1.battery_level<20){
            cout << "Battery is low, Robot operations terminated" << endl;
        }
    
    return 0 ;

}
 