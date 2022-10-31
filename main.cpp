//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include <string.h>
#include "slist.cpp"

using namespace std;

class Airport:public Node
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};



void simpleSortTotal(double distances[], LinkedList * list, int count);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
  ifstream infile;
  int i=0;
  char cNum[256] ;
  LinkedList * airportList = new LinkedList();
  int   airportCount;
  
  infile.open ("./USAirportCodes.csv", ifstream::in);
  int   c=0;
  if (infile.is_open())
  {
    while (infile.good())
    {
      Airport * newAirport = new Airport();
      if (i!=0){
        infile.getline(newAirport->code, 256, ',');
        infile.getline(cNum, 256, ',');
        newAirport->latitude = atof(cNum);
        infile.getline(cNum, 256, '\n');
        newAirport->longitude = atof(cNum);    
        
        if (!(c % 1000)){
          cout << c << endl;
          cout << newAirport->code << " long: " << newAirport->longitude << " lat: " << newAirport->latitude <<  endl;
        }

        airportList->add(newAirport);
        c++;
      }
     else{
        infile.getline(cNum, 256, '\n'); 
      }
        
      i++;
    }
    
    airportCount = c-1;
    double * distances = new double[airportCount];
    infile.close();
    cout << '\n'<< endl;
    int maxIndex=0;
    int count=0;
      
   for (int c=0; c < airportCount; c++){
    void * voidPointer;
    Airport * newAirport;
    Airport * newAirport2;
    newAirport = (Airport *) airportList->get(c);

    voidPointer = airportList->get(10642);
    Airport * austin = static_cast<Airport *>(voidPointer);

    distances[c]=distanceEarth(newAirport->latitude, newAirport->longitude, austin->latitude, austin->longitude);
    if (distances[c] >=distances[maxIndex]){
       maxIndex=c;
    }
    if (distances[c]<=100){
      count++;
      cout << ((Airport *)airportList->get(c))->code << endl; 
    }
   }
    //cout<<count<< endl;
    cout << distances[maxIndex] << endl;
    cout << maxIndex << endl;

    simpleSortTotal(distances, airportList, airportCount);
      

  }
  else
  {
      cout << "Error opening file";
  }


  cout << '\n' << endl;
    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * 0.621371 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/


void simpleSortTotal(double distances[], LinkedList * list, int count)
{
  LinkedList * newList = new LinkedList();
  int maxIndex=0;
  
  for (int k=0;k<count; k++){
    for (int i=0;i<count;i++){
      if (distances[maxIndex]<distances[i]){
        maxIndex=i;
      }
    }
    //cout << ((Airport*)list->get(maxIndex))->code << endl;
    //cout << maxIndex << endl;
    //cout << ((Airport*)list->get(maxIndex))->code<< endl;
    distances[maxIndex]=-100;
    Node * addingNode = list->get(maxIndex);
    newList->add(addingNode);
    //cout << ((Airport *) addingNode)->code << endl;
  }
  
  list = newList;
}
