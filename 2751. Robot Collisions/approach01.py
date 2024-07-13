from typing import List

class Robot:
    def __init__(self, index: int, position: int, health: int, direction: str):
        self.index = index
        self.position = position
        self.health = health
        self.direction = direction

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        survived_healths = []
        robots = []
        active_robots = []  # Robots currently active in collision

        for i in range(len(positions)):
            robots.append(Robot(i, positions[i], healths[i], directions[i]))

        robots.sort(key=lambda robot: robot.position)

        for robot in robots:
            if robot.direction == 'R':
                active_robots.append(robot)
                continue
            # Collide with robots going right if any.
            while active_robots and active_robots[-1].direction == 'R' and robot.health > 0:
                if active_robots[-1].health == robot.health:
                    active_robots.pop()
                    robot.health = 0
                elif active_robots[-1].health < robot.health:
                    active_robots.pop()
                    robot.health -= 1
                else:  # active_robots[-1].health > robot.health
                    active_robots[-1].health -= 1
                    robot.health = 0
            if robot.health > 0:
                active_robots.append(robot)

        active_robots.sort(key=lambda robot: robot.index)

        for robot in active_robots:
            survived_healths.append(robot.health)

        return survived_healths
