struct Robot {
    int index;
    int position;
    int health;
    char direction;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> survivedHealths;
        vector<Robot> robots;
        vector<Robot> activeRobots; // Robots currently active in collision

        for (int i = 0; i < positions.size(); ++i) {
            robots.push_back(Robot{i, positions[i], healths[i], directions[i]});
        }

        ranges::sort(robots, [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });

        for (Robot& robot : robots) {
            if (robot.direction == 'R') {
                activeRobots.push_back(robot);
                continue;
            }
            // Collide with robots going right if any.
            while (!activeRobots.empty() &&
                   activeRobots.back().direction == 'R' && robot.health > 0) {
                if (activeRobots.back().health == robot.health) {
                    activeRobots.pop_back();
                    robot.health = 0;
                } else if (activeRobots.back().health < robot.health) {
                    activeRobots.pop_back();
                    robot.health -= 1;
                } else { // activeRobots.back().health > robot.health
                    activeRobots.back().health -= 1;
                    robot.health = 0;
                }
            }
            if (robot.health > 0) {
                activeRobots.push_back(robot);
            }
        }

        ranges::sort(activeRobots, [](const Robot& a, const Robot& b) {
            return a.index < b.index;
        });

        for (const Robot& robot : activeRobots) {
            survivedHealths.push_back(robot.health);
        }

        return survivedHealths;
    }
};
