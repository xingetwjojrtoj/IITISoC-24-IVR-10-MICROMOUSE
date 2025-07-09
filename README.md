# IITISoC-24-IVR-10-MICROMOUSE

## GOAL
To develop a maze solving micromouse with hardware integration using stimulation

People Involved : 

Mentors:
- [Ampady B R](https://github.com/ampady06)
- [Bhawna Chaudhary](https://github.com/WebWizard104)

Members:
- [Gulshan Choudhary](https://github.com/xingetwjojrtoj)
- [Aarushi Singh](https://github.com/Amberss-Log)
<br>

# MICROMOUSE
 Micromouse is a small autonomous robot capable of navigating a maze to find the shortest path from the starting position to the goal. 
 - Firstly, we had to investigate and assess various maze scanning algorithms. These algorithms help navigate and find way out of the maze.These algorithms can be used to *analyze* the structure of a maze and answer questions about it.There are different algorithms suited for different scenarios.

   ## MAZE SCANNING ALGORITHMS
   ### 1. Wall Following
   The wall following algorithm is based on simple logic of movement through the maze by either following the left hand side or the right hand side of the enclosure wall. In simple words, If the maze is simply connected(a perfect maze), then by keeping one hand in contact with one wall of the maze the solver is guaranteed not to get lost and will reach the goal.
   <br>
  ### *ADVANTAGES*
   - This algorithm has simple logic and is easy to understand and implement.
   - Requires minimal coding and simple sensor data.
   - Garunteed to solve and find the goal in Perfect Mazes.

  ### *DISADVANTAGES*
 
<br>

   - IF the maze is not simply connected, like it has loops, dead ends or multiple solutions, the the mouse is likely to get stuck or move endlessly on loops.
   - Does not guarantee shortest path from start to finish.
   - It does not create map of the maze while it navigates. It simply reacts to immidiate responses from the sensors and navigates.

   This is the video depicting the problem faced while using a wall following algorithm:[right_wall_follower]([LINK]([url](https://drive.google.com/file/d/1i9GHAzxoJ6IoAXuxypmXep02S_17EAth/view?usp=sharing)))
   <br>
   The mouse simply loops back to the start as the maze is not simply connected.
<br>
[In this case](https://drive.google.com/file/d/1BO-K_sEmUj3vDzHHRxPZWSjLFI5veKmK/view?usp=sharing) the wall following algorithm worked.
<br>
<br>
### 2. Mix of wall follower algorithm and tremaux algorithm
Tremaux algorithm keeps a track of each path that it travels through so that it does not get stuck into a particular loop , it gives more priority to the path which is less traveled . 
<br>
### *ADVANTAGES*
- It does not get stuck in an infinite loop.
- It can be used for a variety of mazes.

### *DISADVANTAGES*
- It requires much more space than a wall follower algorithm since it keeps track of all paths which and  how many times they are taken.
<br>
This simulation video shows Treumax algorithm in action:(https://drive.google.com/file/d/1XR3U5SL-y9s6uoXrzSg8DsjEyO8DL3OW/view?usp=sharing)
<br>
<br>

### 3. Floodfill Algorithm

<br>
Flood Fill is popular algorithm used in Micromouse competitions to determine the shortest path through a maze. It works by simulating the filling of a maze with water from the goal point.
The maze is represented as a 2D grid, with each cell containing information about walls and distance to the goal.The water flow starts at the goal, so algorithm assigns value of 0 to the goal. Next, iteratively, it gives neighboring accessible cells progressively greater distance values. Until each reachable cell has a distance value assigned to it, this procedure keeps going.Once the entire maze is filled with distance values, the shortest path from the start to the goal can be determined by following the cells with decreasing distance values. Whenever the mouse identifies any wall in it's path, it makes a layout of the maze and runs floodfill again to assign new distance values to each cell as per the maze layout and it continues until we reach the goal.
<br> 
<br>
This video shows how a floodfill algorithm works:(https://drive.google.com/file/d/1i9GHAzxoJ6IoAXuxypmXep02S_17EAth/view?usp=sharing)
<br>
<br>
Since we found floodfill to be most efficient among others, we choose to continue with floodfill algorithm.
<br>
<br>
After the initial exploration of the maze, once complete layout of the maze is known, the algorithm finds the shortest route by applying floodfill over the maze having data of all wall.

### *ADVANTAGES*

- This algorithm guarantees the shortest path from start to goal and is relatively fast.

### *DISADVANTAGES*
- The algorithm requires complete layout of the maze before it can find shortest path from start to goal.
- Computationally costly for lagre mazes.
  <br>

  This video shows flood fill algorithm scanning maze as well as finding shortest path from start to goal: [Floodfill_final](https://drive.google.com/file/d/1clfPy3I-suyK9Hdtrby9k95kz-t7QTri/view?usp=sharing)
  <br>
  <br>
  ## Overview of the code

  The floodfill and path finding code outlines a flood fill algorithm for navigating a maze. The API class simulates the micromouse interface functions, while the floodfill function uses the flood fill algorithm to navigate through the maze.

  The overview of the key components and functionality:
1. Library: Two extra library are there one is queue to handle data for floodfill and another is string to use an API function setText() for printing direction while verifying.
2. API Class: This class simulates interactions with the maze environment, including movement, turning, wall detection, and setting visual elements (like walls, colors, and text) on the maze.

3. Direction Handling: Updating direction after every turn and updating coordinate after every move of the micro-mouse.

4. Flood Fill Algorithm:
   - Initialization: Initializes various arrays to track visited cells, wall information, and maze distances.
   - Wall Detection and Updating: Updates walls after every move in a array.
   - Flood Fill Logic: Uses a queue to calculate distances from the target cells (center of the maze).
   - Movement Logic: The mouse moves to a nearby cell having value less than it's own value and there is no wall in between them.
5. Main Loop:
   - The main loop continues until the robot reaches one of the center of the maze , keeping track of cells and marking them with green colour.
   - After reaching the center, the robot turns around and continues exploring until all cells are visited, marking it with yellow colour.

<br>
<br>


## HARDWARE INSTRUCTIONS


Device firmware is a software embedded within hardware that provides low-level control and communication with hardware components to enable device functionality.
<br>
For our micromouse hardware parts are Arduino nano 
MPU6050
N-20 micro metal gear motor
Ultrasonic sensor.
<br>
Code for the same has been provided. We were unable to write code for interfacing N20 MICRO metal gear motor and MPU6050

# *CONTRIBUTORS*
- Gulshan Choudhary [ Mechanical Engineering,IIT INDORE]
- Aarushi Singh [Engineering Physics,IIT INDORE]
