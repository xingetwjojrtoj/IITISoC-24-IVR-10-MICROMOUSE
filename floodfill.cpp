#include <iostream>
#include <string>
#include <queue>
using namespace std;
string dir = "W";   // Initial direction
int array[16][16]= {{0}};   // Visit counts

int wall[17][17]={{0}};    // Wall information
class API {
public:
    static int mazeWidth();
    static int mazeHeight();
    static bool wallFront();
    static bool wallRight();
    static bool wallLeft();     
    static void moveForward(int distance = 1);
    static void turnRight();
    static void turnLeft();
    static void setWall(int x, int y, char direction);
    static void clearWall(int x, int y, char direction);
    static void setColor(int x, int y, char color);
    static void clearColor(int x, int y);
    static void clearAllColor();
    static void setText(int x, int y, const std::string& text);
    static void clearText(int x, int y);
    static void clearAllText();
    static bool wasReset();
    static void ackReset();
};


int API::mazeWidth() {
    std::cout << "mazeWidth" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

int API::mazeHeight() {
    std::cout << "mazeHeight" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

bool API::wallFront() {
    std::cout << "wallFront" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

bool API::wallRight() {
    std::cout << "wallRight" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

bool API::wallLeft() {
    std::cout << "wallLeft" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

void API::moveForward(int distance) {
    std::cout << "moveForward ";

    if (distance != 1) {
        std::cout << distance;
    }
    std::cout << std::endl;
    std::string response;
    std::cin >> response;
    if (response != "ack") {
        std::cerr << response << std::endl;
        throw;
    }
}

void API::turnRight() {
    std::cout << "turnRight" << std::endl;
    std::string ack;
    std::cin >> ack;
}

void API::turnLeft() {
    std::cout << "turnLeft" << std::endl;
    std::string ack;
    std::cin >> ack;
}

void API::setWall(int x, int y, char direction) {
    std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
}

void API::clearWall(int x, int y, char direction) {
    std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
}

void API::setColor(int x, int y, char color) {
    std::cout << "setColor " << x << " " << y << " " << color << std::endl;
}

void API::clearColor(int x, int y) {
    std::cout << "clearColor " << x << " " << y << std::endl;
}

void API::clearAllColor() {
    std::cout << "clearAllColor" << std::endl;
}


void API::setText(int x, int y, const std::string& text) {
    std::cout << "setText " << x << " " << y << " " << text << std::endl;
}

void API::clearText(int x, int y) {
    std::cout << "clearText " << x << " " << y << std::endl;
}

void API::clearAllText() {
    std::cout << "clearAllText" << std::endl;
}

bool API::wasReset() {
    std::cout << "wasReset" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

void API::ackReset() {
    std::cout << "ackReset" << std::endl;
    std::string ack;
    std::cin >> ack;
}


void floodfill();

int main() {
    floodfill();
    return 0;
}



string turnRight(string dir) {   // direrction update when turn right
    if (dir == "N") return "E";
    else if (dir == "E") return "S";
    else if (dir == "S") return "W";
    else return "N";
}

string turnLeft(string dir) {    // direrction update when turn left
    if (dir == "N") return "W";
    else if (dir == "W") return "S";
    else if (dir == "S") return "E";
    else return "N";
}

void updateCoordinates(string dir, int& x, int& y) {   //corrdinate update when mving in a particular cordinate
    if (dir == "N") x++;
    else if (dir == "S") x--;
    else if (dir == "E") y--;
    else if (dir == "W") y++;
}

void update(int lr, string& dir, int& x, int& y) {    // function changing direction and updating cordinates
    if (lr == 1) {
        dir = turnRight(dir);
    } else if (lr == 2) {
        dir = turnLeft(dir);
    }
    updateCoordinates(dir, x, y);
}

void floodfill() {

    int walls[16][16][4] = {{{0}}}; // 0: North, 1: South, 2: West, 3: East

    int xa = 0, ya = 0;
    const int directions[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int lr = 0;
    while (!((xa == 7 && ya == 7)||(xa == 7 && ya == 8)||(xa == 8 && ya == 7)||(xa == 8 && ya == 8))) {
       int maze[16][16] = {{0}};

       int vuv[16][16] = {{0}};   //storing value in form of 0 and 1 wether a cell is used earlier or not
        vuv[8][8] = 1;
    vuv[8][7] = 1;
    vuv[7][7] = 1;
    vuv[7][8] = 1;
       int x,y; 
       queue<pair<int, int>> ce;
    ce.push({7, 7});
    ce.push({7, 8});
    ce.push({8, 7});
    ce.push({8, 8});

    // Update wall information based on sensor readings
        if (API::wallFront()) {
            if (dir == "N"){ walls[xa][ya][0] = 1;
             }
            else if (dir == "E") walls[xa][ya][3] = 1;
            else if (dir == "S") walls[xa][ya][1] = 1;
            else if (dir == "W") walls[xa][ya][2] = 1;

        }
        if (API::wallRight()) {

            if (dir == "N") walls[xa][ya][3] = 1;
            else if (dir == "E") walls[xa][ya][1] = 1;
            else if (dir == "S") walls[xa][ya][2] = 1;
            else if (dir == "W") walls[xa][ya][0] = 1;

        }
        if (API::wallLeft()) {
            if (dir == "N") walls[xa][ya][2] = 1;
            else if (dir == "E") walls[xa][ya][0] = 1;
            else if (dir == "S") walls[xa][ya][3] = 1;
            else if (dir == "W") walls[xa][ya][1] = 1;

        }

            if((xa+1)>=0&&(xa+1)<16) walls[xa+1][ya][1]=walls[xa][ya][0];
            if((xa-1)>=0&&(xa-1)<16) walls[xa-1][ya][0]=walls[xa][ya][1];
            if((ya+1)>=0&&(ya+1)<16) walls[xa][ya+1][3]=walls[xa][ya][2];
            if((ya-1)>=0&&(ya-1)<16) walls[xa][ya-1][2]=walls[xa][ya][3];

       while(!(ce.empty())) {
            x = ce.front().first;
            y = ce.front().second;
            ce.pop();

            for (int i = 0; i < 4; ++i) {

                int new_x = x + directions[i][0];
                int new_y = y + directions[i][1];
                if (new_x >= 0 && new_x < 16 && new_y >= 0 && new_y < 16 && vuv[new_x][new_y] == 0) {
                    if (walls[x][y][i] == 0) { // If no wall in the current direction
                        maze[new_x][new_y] = maze[x][y] + 1;
                        ce.push({new_x, new_y});
                        vuv[new_x][new_y]=1;
                    }
            }
        } }


        //for write numbers on the maze in all cells incresing order from target to start position
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
        std::string z = std::to_string(maze[i][j])  ;
        API::setText(i, j,z);}}
        // applying green colour to the current cell
        API::setColor( xa, ya, 'g');
        int a[4] = {400, 400, 400, 400};
        for (int i = 0; i < 4; ++i) {
            int new_x = xa + directions[i][0];
            int new_y = ya + directions[i][1];
            if (new_x >= 0 && new_x < 16 && new_y >= 0 && new_y < 16) {
                if (walls[xa][ya][i] == 0) { // If no wall in the current direction
                    a[i] = maze[new_x][new_y];
                }
            }
        }
        // applying movement to micromouse based on current direction and maze number near to there cell so that it can reach the target
               if(dir=="N"){

        if(a[3]>a[0]&& a[2]>a[0]&&a[1]>a[0]  ){

        API::moveForward();
        lr=3; 
        }
        else if(a[3]>a[1]&& a[2]>a[1]&&a[0]>a[1]  ){
        API::turnRight();
       dir=turnRight(dir);
       API::turnRight();
       API::moveForward();
       lr=1;
        }
        else if(a[3]>a[2]&& a[0]>a[2]&&a[1]>a[2]  ){
        API::turnLeft();
        API::moveForward();
        lr=2;
        }
       else if(a[0]>a[3]&& a[2]>a[3]&&a[1]>a[3]  ){
       API::turnRight();
       API::moveForward();
        lr=1;
        } 
        else if(    a[0]==a[2]||a[0]==a[3]||a[0]==a[1]||a[2]==a[3]||a[1]==a[2]||a[1]==a[3]         ){
            if(a[0]<a[1]&&a[0]<a[3]){
            API::moveForward();
        lr=3;
            }
            else if((a[0]<a[1])&&(a[0]<a[2])){
            API::moveForward();
        lr=3;
            }
            else if((a[0]<a[2])&&(a[0]<a[3])){

            API::moveForward();
        lr=3;
            }
            else if((a[1]<a[0])&&(a[1]<a[3])){
            API::turnLeft();
            API::moveForward();
        lr=2;
            }
            else if((a[2]<a[0])&&(a[2]<a[1])){
            API::turnLeft();
            API::moveForward();
        lr=2;
            }else if((a[1]<a[0])&&(a[1]<a[2])){
            API::turnRight();
            API::moveForward();
        lr=1;
            }
        }

        else if((a[1]==a[2]==a[3])&&a[1]<a[0]){
            API::turnRight();
            API::moveForward();
        lr=1;
        }
        else {
         API::moveForward();
        lr=3;
        }
       }
       else if(dir=="S"){

        if(a[3]>a[0]&& a[2]>a[0]&&a[1]>a[0]  ){
        API::turnRight();
        dir=turnRight(dir);
       API::turnRight();
       API::moveForward();
       lr=1;
        }
        else if(a[3]>a[1]&& a[2]>a[1]&&a[0]>a[1]  ){
        API::moveForward();
       lr=3;
        }
        else if(a[3]>a[2]&& a[0]>a[2]&&a[1]>a[2]  ){
        API::turnRight();
        API::moveForward();
        lr=1;
        }
       else if(a[0]>a[3]&& a[2]>a[3]&&a[1]>a[3]  ){
       API::turnLeft();
        API::moveForward();
        lr=2;
        } 
         else if(    a[0]==a[2]||a[0]==a[3]||a[0]==a[1]||a[2]==a[3]||a[1]==a[2]||a[1]==a[3]         ){
            if(a[1]<a[2]&&a[1]<a[3]){
            API::moveForward();
        lr=3;
            }
            else if((a[1]<a[0])&&(a[1]<a[3])){
            API::moveForward();
        lr=3;
            }
            else if((a[1]<a[0])&&(a[1]<a[2])){

            API::moveForward();
        lr=3;
            }
            else if((a[0]<a[1])&&(a[0]<a[2])){
            API::turnLeft();
            API::moveForward();
        lr=2;
            }
            else if((a[2]<a[0])&&(a[2]<a[1])){
            API::turnLeft();
            API::moveForward();
        lr=2;
            }else if((a[0]<a[1])&&(a[0]<a[3])){
            API::turnRight();
            API::moveForward();
        lr=1;
            }
        }

    else if((a[0]==a[2]==a[3])&&a[0]<a[1]){
            API::turnRight();
            API::moveForward();
        lr=1;
        }
        else {
         API::moveForward();
        lr=3;
        }
       }
       else if(dir=="E"){
        if(a[3]>a[0]&& a[2]>a[0]&&a[1]>a[0]  ){
        API::turnLeft();
        API::moveForward();
        lr=2;
        }
        else if(a[3]>a[1]&& a[2]>a[1]&&a[0]>a[1]  ){
        API::turnRight();
        API::moveForward();
        lr=1;
        }
        else if(a[3]>a[2]&& a[0]>a[2]&&a[1]>a[2]  ){
        API::turnRight();
        dir=turnRight(dir);
       API::turnRight();
       API::moveForward();
       lr=1;
        }
       else if(a[0]>a[3]&& a[2]>a[3]&&a[1]>a[3]  ){
       API::moveForward();
       lr=3;
        } 
        else if(    a[0]==a[2]||a[0]==a[3]||a[0]==a[1]||a[2]==a[3]||a[1]==a[2]||a[1]==a[3]         ){
            if(a[3]<a[1]&&a[3]<a[2]){
            API::moveForward();
        lr=3;
            }
            else if((a[3]<a[1])&&(a[3]<a[0])){
            API::moveForward();
        lr=3;
            }
            else if((a[3]<a[2])&&(a[3]<a[0])){

            API::moveForward();
        lr=3;
            }
            else if((a[0]<a[1])&&(a[0]<a[3])){
            API::turnLeft();
            API::moveForward();
        lr=2;
            }
            else if((a[0]<a[2])&&(a[0]<a[3])){
            API::turnLeft();
            API::moveForward();
        lr=2;
            }else if((a[1]<a[0])&&(a[1]<a[3])){
            API::turnRight();
            API::moveForward();
        lr=1;
            }
        }

        else if((a[1]==a[0]==a[2])&&a[0]<a[3]){
            API::turnRight();
            API::moveForward();
        lr=1;
        }
        else {
         API::moveForward();
        lr=3;
        }
       }
       else if(dir=="W"){

        if(a[3]>a[0]&& a[2]>a[0]&&a[1]>a[0]  ){
        API::turnRight();
       API::moveForward();
       lr=1;
        }
        else if(a[3]>a[1]&& a[2]>a[1]&&a[0]>a[1]  ){
        API::turnLeft();
        API::moveForward();
        lr=2;
        }
        else if(a[3]>a[2]&& a[0]>a[2]&&a[1]>a[2]  ){
        API::moveForward();
        lr=3;
        }
       else if(a[0]>a[3]&& a[2]>a[3]&&a[1]>a[3]  ){
       API::turnRight();
        dir=turnRight(dir);
       API::turnRight();
       API::moveForward();
       lr=1;
        } 
        else if(    a[0]==a[2]||a[0]==a[3]||a[0]==a[1]||a[2]==a[3]||a[1]==a[2]||a[1]==a[3]         ){
            if(a[2]<a[1]&&a[2]<a[3]){
            API::moveForward();
        lr=3;
            }
            else if((a[2]<a[1])&&(a[2]<a[0])){
            API::moveForward();
        lr=3;
            }
            else if((a[2]<a[0])&&(a[2]<a[3])){

            API::moveForward();
        lr=3;
            }
            else if((a[1]<a[2])&&(a[1]<a[3])){
            API::turnLeft();
            API::moveForward();
        lr=2;
            }
            else if((a[1]<a[0])&&(a[1]<a[2])){
            API::turnLeft();
            API::moveForward();
        lr=2;
            }else if((a[0]<a[1])&&(a[0]<a[2])){
            API::turnRight();
            API::moveForward();
        lr=1;
            }
        }
    else if((a[1]==a[0]==a[3])&&a[0]<a[2]){
            API::turnRight();
            API::moveForward();
        lr=1;
        }
        else {
         API::moveForward();
        lr=3;
        }
       }
update(lr,dir,xa,ya);}   }
