#include <iostream>
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
int array[16][16]= {{0}};

int wall[17][17]={{0}};
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

void alg();   // tremaux algorithm declaration

int main() {
    alg();
    return 0;
}
char dir='N'; //Initial direction
char turnRight(char dir) {  // direrction update when turn right
    if (dir == 'N') return 'E';
    else if (dir == 'E') return 'S';
    else if (dir == 'S') return 'W';
    else return 'N';
}
char turnLeft(char dir) {  // direrction update when turn left
    if (dir == 'N') return 'W';
    else if (dir == 'W') return 'S';
    else if (dir == 'S') return 'E';
    else return 'N';
}
void updateCoordinates(char dir, int& x, int& y) {    //corrdinate update when mving in a particular cordinate
    if (dir == 'N') y++;
    else if (dir == 'S') y--;
    else if (dir == 'E') x++;
    else if (dir == 'W') x--;
}
void update(int lr,char &dir, int &x,int &y){   // function changing direction and updating cordinates
if (lr ==1){
   dir=turnRight( dir);}
   else if(lr ==2){
  dir= turnLeft( dir);}
   updateCoordinates( dir, x,y);}
void alg() {



          int x=0,y=0,lr=0;
          // movement based on direction and number of times the path is travelled
    while(!((x==7 && y==7)||(x==7 && y==8)||(x==8 && y==7)||(x==8 && y==8))) {
        API::setColor( x, y, 'g'); // helighting the path followed by micromouse using green colour


        if (dir=='N'){

         if(!API::wallRight() &&API::wallFront()&&API::wallLeft()) {
            API::turnRight();

            API::moveForward();
            lr =1;
        }

        else if (API::wallRight() &&API::wallFront()&&!API::wallLeft())
        {
            API::turnLeft();
            API::moveForward();
            lr=2;

        }

        else if(API::wallRight() &&!API::wallFront()&&API::wallLeft()) {
            API::moveForward(); 
            lr=3;
        }
        else if(API::wallRight() &&API::wallFront()&&API::wallLeft()){
             API::turnRight();
             dir=turnRight(dir);
             API::turnRight();
             API::moveForward();
             lr=1;
        }
        else if(!API::wallRight() &&!API::wallFront()&&!API::wallLeft()){
             API::turnRight();
             API::moveForward();
             lr=1;
        }

       else if(!API::wallRight() &&!API::wallFront()&&API::wallLeft()){

        if(array[x+1][y]>array[x][y+1]){
        API::moveForward();
        lr=3;
        }
        else{
        API::turnRight();
        API::moveForward();
        lr=1;
        }
        }
        else if(API::wallRight() &&!API::wallFront()&&!API::wallLeft()){

        if(array[x-1][y]>array[x][y+1]){
        API::moveForward();
        lr=3;
        }
        else{
        API::turnLeft();
        API::moveForward();
        lr=2;
        }
        }
        else if(!API::wallRight() &&API::wallFront()&&!API::wallLeft()){

        if(array[x-1][y]>array[x+1][y]){
        API::turnRight();
        API::moveForward();
        lr=1;
        }

        else{
        API::turnLeft();
        API::moveForward();
        lr=2;
        }
        }
    }
    else if (dir=='S'){
       if(!API::wallRight() &&API::wallFront()&&API::wallLeft()) {
            API::turnRight();

            API::moveForward();
            lr=1;
        }
        else if (API::wallRight() &&API::wallFront()&&!API::wallLeft())
        {
            API::turnLeft();
          API::moveForward();  
          lr=2;
        }
        else if(API::wallRight() &&!API::wallFront()&&API::wallLeft()) {
            API::moveForward();
            lr=3;
        }
        else if(API::wallRight() &&API::wallFront()&&API::wallLeft()){
             API::turnRight();
            dir=turnRight(dir);
             API::turnRight();
             API::moveForward();
             lr=1;
        }
        else if(!API::wallRight() &&!API::wallFront()&&!API::wallLeft()){
             API::turnRight();
             API::moveForward();
             lr=1;
        }
       else if(API::wallRight() &&!API::wallFront()&&!API::wallLeft()){

        if(array[x+1][y]>array[x][y-1]){
        API::moveForward();
        lr=3;
        }
        else{
        API::turnLeft();
        API::moveForward();
        lr=2;
        }
        }
        else if(!API::wallRight() &&!API::wallFront()&&API::wallLeft()){

        if(array[x-1][y]>array[x][y-1]){
        API::moveForward();
        lr=3;
        }
        else{
        API::turnRight();
        API::moveForward();
        lr=1;
        }
        }
        else if(!API::wallRight() &&API::wallFront()&&!API::wallLeft()){

        if(array[x-1][y]<array[x+1][y]){
        API::turnRight();
       API::moveForward(); 
       lr=1;
        }
        else{
        API::turnLeft();
        API::moveForward();
        lr=2;
        }
        }}
        else if (dir=='E'){
       if(!API::wallRight() &&API::wallFront()&&API::wallLeft()) {
            API::turnRight();

            API::moveForward();
            lr=1; 
        }
        else if (API::wallRight() &&API::wallFront()&&!API::wallLeft())
        {
            API::turnLeft();
           API::moveForward(); 
           lr=2;
        }
        else if(API::wallRight() &&!API::wallFront()&&API::wallLeft()) {
            API::moveForward();
            lr=3;
        }
        else if(API::wallRight() &&API::wallFront()&&API::wallLeft()){
             API::turnRight();
           dir= turnRight(dir);
             API::turnRight();
             API::moveForward();
             lr=1;
        } 
        else if(!API::wallRight() &&!API::wallFront()&&!API::wallLeft()){
             API::turnRight();
             API::moveForward();
             lr=1;
        }
       else if(!API::wallRight() &&!API::wallFront()&&API::wallLeft()){

        if(array[x+1][y]<array[x][y-1]){
        API::moveForward();
        lr=3;
        }
        else{
        API::turnRight();
        API::moveForward();
        lr=1;
        }
        }
        else if(API::wallRight() &&!API::wallFront()&&!API::wallLeft()){

        if(array[x+1][y]<array[x][y+1]){
        API::moveForward();
        lr=3;
        }
        else{
        API::turnLeft();
        API::moveForward();
        lr=2;
        }
        }
        else if(!API::wallRight() &&API::wallFront()&&!API::wallLeft()){

        if(array[x][y-1]<array[x][y+1]){
        API::turnRight();
        API::moveForward();
        lr=1;
        }
        else{
        API::turnLeft();
        API::moveForward();
        lr=2;
        }
        }}
        else if (dir=='W'){
        if(!API::wallRight() &&API::wallFront()&&API::wallLeft()) {
            API::turnRight();

            API::moveForward();
            lr=1;
        }
        else if (API::wallRight() &&API::wallFront()&&!API::wallLeft())
        {
            API::turnLeft();
            API::moveForward();
            lr=2;
        }
        else if(API::wallRight() &&!API::wallFront()&&API::wallLeft()) {
            API::moveForward();
            lr=3;
        }
        else if(API::wallRight() &&API::wallFront()&&API::wallLeft()){
             API::turnRight();
           dir= turnRight(dir);
             API::turnRight();
             API::moveForward();
             lr=1;
        }
        else if(!API::wallRight() &&!API::wallFront()&&!API::wallLeft()){
             API::turnRight();
             API::moveForward();
             lr=1;
        }
       else if(!API::wallRight() &&!API::wallFront()&&API::wallLeft()){

        if(array[x-1][y]<array[x][y+1]){
        API::moveForward();
        lr=3;
        }
        else{
        API::turnRight();
        API::moveForward();
        lr=1;} }
        else if(API::wallRight() &&!API::wallFront()&&!API::wallLeft()){

        if(array[x-1][y]>array[x][y-1]){
        API::moveForward();
        lr=3; }
        else{
        API::turnLeft();
       API::moveForward(); 
       lr=2;}}
        else if(!API::wallRight() &&API::wallFront()&&!API::wallLeft()){

        if(array[x][y-1]>array[x][y+1]){
        API::turnRight();
        API::moveForward();
        lr=1;}
        else {
        API::turnLeft();
        API::moveForward();
        lr=2;
        }}}
        update(lr,dir,x,y);
        ++array[x][y];
        }}
