   
// C++ Program to implement 
// Subnet Calculator 
#include <bitset> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector>

using namespace std;

void subnet(const string& ipAddress, const string& subnetMask) 
{ 
    // Parse IP address and subnet mask 
    vector<int> ipParts; 
    vector<int> maskParts; 
  
    istringstream ipStream(ipAddress); 
    istringstream maskStream(subnetMask); 
    string ipPart; 
  
    while (getline(ipStream, ipPart, '.')) { 
        ipParts.push_back(stoi(ipPart)); 
    } 
  
    string maskPart; 
    while (getline(maskStream, maskPart, '.')) { 
        maskParts.push_back(stoi(maskPart)); 
    } 
  
    // Calculate network address 
    vector<int> networkAddress; 
    for (size_t i = 0; i < ipParts.size(); i++) { 
        networkAddress.push_back(ipParts[i] & maskParts[i]); 
    } 
    vector<int> broadcastAddress; 
    for (size_t i = 0; i < ipParts.size(); i++) { 
        broadcastAddress.push_back( 
            ipParts[i] | (~maskParts[i] & 0xFF)); 
    } 
  
    // Calculate usable IP range 
    networkAddress[3]++; 
    broadcastAddress[3]--; 
  
    // Display subnet details 
    cout << "Subnet Details:" << endl; 
  
    cout << "Network Address: "; 
    for (int i = 0; i < 4; i++) { 
        cout << networkAddress[i]; 
        if (i < 3) { 
            cout << "."; 
        } 
    } 
    cout << endl; 
  
    cout << "Broadcast Address: "; 
    for (int i = 0; i < 4; i++) { 
        cout << broadcastAddress[i]; 
        if (i < 3) { 
            cout << "."; 
        } 
    } 
    cout << endl; 
  
    cout << "Subnet Mask: " << subnetMask << endl; 
    cout << "Usable IP Range: "; 
    for (int i = 0; i < 4; i++) { 
        cout << networkAddress[i]; 
        if (i < 3) { 
            cout << "."; 
        } 
    } 
    cout << " - "; 
    for (int i = 0; i < 4; i++) { 
        cout << broadcastAddress[i]; 
        if (i < 3) { 
            cout << "."; 
        } 
    } 
    cout << endl; 
}

int main() 
{ 
    string ipAddress = "