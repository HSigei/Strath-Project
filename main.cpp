#include <iostream>
#include <sstream>
#include <vectors>
#include <fstream>

using namespace std;


struct Fixtures {
    string hometeam;
    string awayteam;
    string hometown;
    string stadium;
    int leg;
    int weekend;
};

vector<string> team;
vector<string> town;
vector<string> stadium;
vector<Fixtures> fixtures;

int main(){
    //READING FROM CSV
    ifstream myFile("teams_file.csv");
    string line = "";

    while(getline(myFile, line)) {
        stringstream ss(line);
        string teamToPush, townToPush, stadiumToPush;

        getline(ss, teamToPush,',');
        getline(ss, townToPush,',');
        getline(ss, stadiumToPush,',');

        //to check if the file is being read

        cout<<teamToPush<<",";
        cout<<townToPush<<",";
        cout<<stadiumToPush<<endl;

        team.push_back(teamToPush);
        town.push_back(townToPush);
        stadium.push_back(stadiumToPush);

    }

    myFile.close();

    int weekend = 1;
    int match = 0;
    for(int i =0; i<team.size(); i++) {
        for(int j = i +1; j<team.size(); j++) {
            fixtures.push_back({team[i],team[j],town[i], stadium[i], 1, weekend });
            fixtures.push_back({team[j],team[i],town[i], stadium[i], 1, weekend });
            match += 2;

            if(match == 2) {
                weekend++;
                match = 0;
            }
        }
    }
//continue her


    return 0;
}
