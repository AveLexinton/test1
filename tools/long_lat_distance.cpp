//use this file to calculate the actual distance between two gps points

#include <cmath>
#include <iostream>
using namespace std;


const double EARTH_RADIUS = 6371.004;   //km
double rad(double d)
{
   return d * acos(-1) / 180.0;
}

double GetDistance(double lat1, double lng1, double lat2, double lng2)
{
   double radLat1 = rad(lat1);
   double radLat2 = rad(lat2);
   double a = radLat1 - radLat2;
   double b = rad(lng1) - rad(lng2);
   double s = 2 * asin(sqrt(pow(sin(a/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
   s = s * EARTH_RADIUS;
   s = round(s * 10000) / 10000;
   return s;
}

int main() {
    double long1=116.21191;
    double lat1=39.90263;
    double long2=116.21475;
    double lat2=39.90265;
    cout << GetDistance(lat1,long1,lat2,long2) << endl;
    return 0;
}
