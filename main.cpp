// Name: Serhan Emre
// Surname: Telatar
// ID: 29034

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Loc{
    int locX;
    int locY;
    char type;
};

bool columAndRowSizeChecker(vector<Loc> &temp){  //checks the matrix if its proper
    vector<int> amounts;
    int counter;
    for (int i = 0; i < temp.size(); ++i) {
        counter = 0;
        for (int j = 0; j < temp.size(); ++j) {
            if(temp[i].locX == temp[j].locX){
                counter++;
            }
        }
        amounts.push_back(counter);
    }
    for (int a = 0; a < amounts.size(); a++) {
        if((amounts[a] != amounts[a+1]) && a != amounts.size()-1){
            return false;
        }
    }
    return true;
}

vector<Loc> placement(string & queryStr){ //put the elements into vector
    int seqLine = 0;
    Loc temp;
    vector<Loc> tempVec;
    int yAxes = 0;
    for(int i = 0 ; i < queryStr.size(); i++){
        if(queryStr[i] == 'b' || queryStr[i] == 's'){
            continue;
        }else if(queryStr[i] == '/'){
            seqLine++;
            yAxes = 0;
        }else if(queryStr[i] == '1' || queryStr[i] == '2' || queryStr[i] == '3' || queryStr[i] == '4' ||queryStr[i] == '5' ||queryStr[i] == '6' ||queryStr[i] == '7' ||queryStr[i] == '8' ||queryStr[i] == '9' ){
            int amount = (int)queryStr[i] - 48;
            char type = queryStr[i+1];
            for(int j = 0; j < amount;j++){
                if(type == 'b'){
                    temp.locX = seqLine;
                    temp.locY = yAxes;
                    temp.type = 'b';
                    tempVec.push_back(temp);
                    yAxes++;
                }else if(type == 's'){
                    temp.locX = seqLine;
                    temp.locY = yAxes;
                    temp.type = 's';
                    tempVec.push_back(temp);
                    yAxes++;
                }else{
                    cout<<"Wrong letter"<<endl;
                    break;
                }

            }
        }else{
            cout<<"Something wrong"<<endl;
        }
    }
    return tempVec;
}

vector<vector<char>> converterTo2DVector(vector<Loc> & locVec){  // convert the vector into 2D vector
    int row = 0;
    int column = 0;
    for (int i = 0; i < locVec.size(); i++) {
        if(locVec[i].locX > row){
            row = locVec[i].locX;
        }
        if(locVec[i].locY > column){
            column = locVec[i].locY;
        }
    }
    row++;
    column++;
    vector<vector<char>> tempVec(row, vector<char>(column, '-'));
    for (int i = 0; i < locVec.size(); i++){
        if(locVec[i].type == 's'){
            tempVec[locVec[i].locX][locVec[i].locY] = '#';
        }
        if(locVec[i].type == 'b'){
            tempVec[locVec[i].locX][locVec[i].locY] = '-';
        }
    }
    return tempVec;
}

void system(vector<vector<char>> bannedPlaces, vector<vector<char>> requiredPlaces){ //system
    int smallVecX = requiredPlaces.size();
    int smallVecY = requiredPlaces[0].size();

    int bigVecX = bannedPlaces.size();
    int bigVecY = bannedPlaces[0].size();

    int amountXChecker = bigVecX - smallVecX + 1;
    int amountYChecker = bigVecY - smallVecY + 1;
    vector<vector<Loc>> multipleLoc;
    for(int i = 0; i < amountXChecker; i++){
        for (int j = 0; j < amountYChecker; j++){
            bool properToPut = true;
            int sX = smallVecX-1;
            int sY = smallVecY-1;
            for (int k = 0; k <= sX; k++){
                for (int l = 0; l <= sY; l++) {
                    if((bannedPlaces[k+i][l+j] == '-') && (requiredPlaces[k][l] == '-')){
                        continue;
                    }else if((bannedPlaces[k+i][l+j] == '#') && (requiredPlaces[k][l] == '#')){
                        properToPut = false;
                    }else if((bannedPlaces[k+i][l+j] == '#') && (requiredPlaces[k][l] == '-')){
                        continue;
                    }else if((bannedPlaces[k+i][l+j] == '-') && (requiredPlaces[k][l] == '#')){
                        continue;
                    }
                }
            }
            vector<Loc> tempVec;
            Loc temp;
            if(properToPut){
                for (int a = 0; a < smallVecX; a++) {
                    for (int b = 0; b < smallVecY; b++) {
                        if(requiredPlaces[a][b] == '#'){
                            temp.locX = i + a;
                            temp.locY = j + b;
                            temp.type = '#';
                            tempVec.push_back(temp);
                        }
                    }
                }
                multipleLoc.push_back(tempVec);
            }
        }
    }
    if((multipleLoc.size() == 0 || smallVecX > bigVecX) || smallVecY > bigVecY){
        cout<<"No placements found."<<endl;
    }else{
        for (int i = 0; i < multipleLoc.size(); i++) {
            int seq = i+1;
            cout<<"Placement number "<<seq<<":"<<endl;
            for (int j = 0; j < multipleLoc[0].size(); j++) {
                cout<<"("<<multipleLoc[i][j].locX<<","<<multipleLoc[i][j].locY<<") ";
            }
            cout<<endl;
        }
    }
}

int main() {

    string filename;
    ifstream input;

    cout<<"Please enter the file name:"<<endl;
    cin>>filename;
    while(!input.is_open()){
        input.open(filename.c_str());
        if (!input.is_open()){
            cout << "Could not open the file. Please enter a valid file name:" << endl;
            cin >> filename;
        }
    }
    string line;
    vector<Loc> banned ;
    int counter = 0;
    Loc locationPlace;
    bool checker = true;
    vector<string> lines;

    while(getline(input, line)){
        lines.push_back(line);
        for(int i = 0; i< line.length();i++){
            if(line[i] == '#'){
                locationPlace.locX = counter;
                locationPlace.locY = i;
                locationPlace.type = 's';
                banned.push_back(locationPlace);
            }else if(line[i] == '-'){
                locationPlace.locX = counter;
                locationPlace.locY = i;
                locationPlace.type = 'b';
                banned.push_back(locationPlace);
            }else{
                checker = false;
            }
        }
        counter++;
    }
    input.close();

    if(checker && columAndRowSizeChecker(banned)){
        cout<<"The matrix file contains:"<<endl;
        for (int i = 0; i < lines.size(); ++i) {
            cout<<lines[i]<<endl;
        }
        string query;
        cout<<"Enter the string query for a shape, or \"Quit\" to terminate the program: "<<endl;
        cin>>query;
        while(query != "Quit"){
            vector<Loc> req = placement(query);
            system(converterTo2DVector(banned), converterTo2DVector(req));
            cout<<"Enter the string query for a shape, or \"Quit\" to terminate the program: "<<endl;
            cin>>query;
        }
    }else{
        cout<<"Erroneous file content. Program terminates.";
    }
    return 0;
}
