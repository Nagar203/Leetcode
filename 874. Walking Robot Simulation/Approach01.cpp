#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    // Simulates the movement of a robot according to given commands and obstacles.
    // Returns the maximum squared Euclidean distance from the origin that the robot reaches.
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
        // Direction vectors for north, east, south, west.
        int directionOffsets[5] = {0, 1, 0, -1, 0}; // The last '0' is to allow easy access to 'y' direction with directionOffsets[k+1]

        // Function to encode a pair of coordinates into a single integer.
        auto encodePosition = [](int x, int y) {
            return x * 60010 + y;
        };
      
        // Set to hold the encoded locations of the obstacles.
        std::unordered_set<int> obstaclePositions;
        for (const auto& obstacle : obstacles) {
            obstaclePositions.insert(encodePosition(obstacle[0], obstacle[1]));
        }
      
        // Initialize variables to track the maximum Euclidean distance squared
        // and the current direction index and coordinates of the robot.
        int maxDistanceSquared = 0;
        int currentDirectionIndex = 0;
        int currentX = 0, currentY = 0; // Robot starts at the origin (0,0)

        // Iterate through each command to move the robot.
        for (int command : commands) {
            if (command == -2) { // -2 means turn left 90 degrees
                currentDirectionIndex = (currentDirectionIndex + 3) % 4; // rotate left in the directionOffsets array
            } else if (command == -1) { // -1 means turn right 90 degrees
                currentDirectionIndex = (currentDirectionIndex + 1) % 4; // rotate right in the directionOffsets array
            } else {
                // Move forward by 'command' steps.
                while (command--) { // Loop over each step.
                    // Calculate the next x and y after moving a step in the current direction.
                    int nextX = currentX + directionOffsets[currentDirectionIndex];
                    int nextY = currentY + directionOffsets[currentDirectionIndex + 1];

                    // Check if the next position is an obstacle.
                    if (obstaclePositions.count(encodePosition(nextX, nextY))) {
                        break; // An obstacle blocks further movement in this direction.
                    }

                    // Update the robot's current position.
                    currentX = nextX;
                    currentY = nextY;

                    // Update the maximum distance squared if necessary.
                    maxDistanceSquared = std::max(maxDistanceSquared, currentX * currentX + currentY * currentY);
                }
            }
        }
      
        // Return the maximum Euclidean distance squared that the robot has been from the origin.
        return maxDistanceSquared;
    }
};