from typing import List, Set

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # Direction vectors for north, east, south, west.
        directionOffsets = [0, 1, 0, -1, 0]  # The last '0' allows easy access to 'y' direction with directionOffsets[k+1]

        # Function to encode a pair of coordinates into a single integer.
        def encodePosition(x: int, y: int) -> int:
            return x * 60010 + y

        # Set to hold the encoded locations of the obstacles.
        obstaclePositions: Set[int] = {encodePosition(obstacle[0], obstacle[1]) for obstacle in obstacles}

        # Initialize variables to track the maximum Euclidean distance squared
        # and the current direction index and coordinates of the robot.
        maxDistanceSquared = 0
        currentDirectionIndex = 0
        currentX, currentY = 0, 0  # Robot starts at the origin (0, 0)

        # Iterate through each command to move the robot.
        for command in commands:
            if command == -2:  # -2 means turn left 90 degrees
                currentDirectionIndex = (currentDirectionIndex + 3) % 4  # Rotate left in the directionOffsets array
            elif command == -1:  # -1 means turn right 90 degrees
                currentDirectionIndex = (currentDirectionIndex + 1) % 4  # Rotate right in the directionOffsets array
            else:
                # Move forward by 'command' steps.
                while command > 0:  # Loop over each step.
                    # Calculate the next x and y after moving a step in the current direction.
                    nextX = currentX + directionOffsets[currentDirectionIndex]
                    nextY = currentY + directionOffsets[currentDirectionIndex + 1]

                    # Check if the next position is an obstacle.
                    if encodePosition(nextX, nextY) in obstaclePositions:
                        break  # An obstacle blocks further movement in this direction.

                    # Update the robot's current position.
                    currentX, currentY = nextX, nextY

                    # Update the maximum distance squared if necessary.
                    maxDistanceSquared = max(maxDistanceSquared, currentX * currentX + currentY * currentY)

                    # Decrement the remaining steps to move forward.
                    command -= 1

        # Return the maximum Euclidean distance squared that the robot has been from the origin.
        return maxDistanceSquared