/*
given 4 numbers a,b,c,d
find the maximum possible time that can be represented in a digital clock. If no such time found, return 
NOT POSSIBLE

Eg, 1,8,3,2 -> 23:18
Eg, 6,3,8,2 -> Not Possible
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(int A, int B, int C, int D) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> hour; // vector to store possible hour values that can be made
    
    //manually find all possible hour values and push in hour vector
    if((A*10 + B) <= 23)
        hour.push_back((A*10 + B));
    if((A*10 + C) <= 23)
        hour.push_back((A*10 + C));
    if((A*10 + D) <= 23)
        hour.push_back((A*10 + D));
    if((B*10 + A) <= 23)
        hour.push_back((B*10 + A));
    if((B*10 + C) <= 23)
        hour.push_back((B*10 + C));
    if((B*10 + D) <= 23)
        hour.push_back((B*10 + D));
    if((C*10 + A) <= 23)
        hour.push_back((C*10 + A));
    if((C*10 + B) <= 23)
        hour.push_back((C*10 + B));
    if((C*10 + D) <= 23)
        hour.push_back((C*10 + D));
    if((D*10 + A) <= 23)
        hour.push_back((D*10 + A));
    if((D*10 + B) <= 23)
        hour.push_back((D*10 + B));
    if((D*10 + C) <= 23)
        hour.push_back((D*10 + C));
    
    sort(hour.begin(),hour.end()); // sort the hour vector
    
    //loop over all values in the hour vector from the end
    for(int i=hour.size()-1; i>=0; i--){
        if((A*10 + B) == hour[i]){
            //find possible minute values from remaining 2 numbers
            int min1 = C*10 + D;
            int min2 = D*10 + C;
            string h;
            string m;
            if(hour[i] < 10) // if hour values is less than 10, append 0 in the string representation
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        
        //repeat the above process for all values in vector hour until correct value of time found
        else if((A*10 + C) == hour[i]){
            int min1 = B*10 + D;
            int min2 = D*10 + B;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((A*10 + D) == hour[i]){
            int min1 = B*10 + C;
            int min2 = C*10 + B;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((B*10 + A) == hour[i]){
            int min1 = C*10 + D;
            int min2 = D*10 + C;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((B*10 + C) == hour[i]){
            int min1 = A*10 + D;
            int min2 = D*10 + A;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((B*10 + D) == hour[i]){
            int min1 = A*10 + C;
            int min2 = C*10 + A;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((C*10 + A) == hour[i]){
            int min1 = B*10 + D;
            int min2 = D*10 + B;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((C*10 + B) == hour[i]){
            int min1 = A*10 + D;
            int min2 = D*10 + A;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((C*10 + D) == hour[i]){
            int min1 = B*10 + A;
            int min2 = A*10 + B;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((D*10 + A) == hour[i]){
            int min1 = B*10 + C;
            int min2 = C*10 + B;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((D*10 + B) == hour[i]){
            int min1 = A*10 + C;
            int min2 = C*10 + A;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
        else if((D*10 + C) == hour[i]){
            int min1 = B*10 + A;
            int min2 = A*10 + B;
            string h;
            string m;
            if(hour[i] < 10)
                h = "0" + to_string(hour[i]);
            else
                h = to_string(hour[i]);
            int max = -1;
            //if both min1 and min2 are less than 60 then max of both will be the required inute value
            if(min1 < 60 && min2 < 60){
                if(min1 <= min2)
                    max = min2;
                else
                    max = min1;
            }
            
            //else if one of them is less than 60 then that is the required minute value
            else if(min1 < 60)
                max = min1;
            else if(min2 < 60)
                max = min2;
            
            //if minute value found, get the string representation and return time 
            if(max > -1){
                if(max < 10)
                    m = "0" + to_string(max);
                else
                    m = to_string(max);
            }
            if(max > -1){
                string time = h + ":" + m;
                return time;
            }
        }
    }
    
    //if not combination fo time found for all values in hour vector then return not possible
    return "NOT POSSIBLE";    
}

int main(){
    int a = 1;
    int b = 8;
    int c = 3;
    int d = 2;
    string time = solution(a,b,c,d);
    cout<<time;
    return 0;
}

                      
