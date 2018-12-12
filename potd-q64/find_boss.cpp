#include <queue>
#include <map>

#include "graph.cpp"

using namespace std;

typedef map<Node*, bool> clearedMap;

/*
Return true if you have defeated the boss, false if they are unbeatable and the player must give up
NOTE: If you are too weak to defeat the boss, then don't try! You will be defeated and gain 0 Exquisite Chocolate points!

@param map      This graph contains everything you need to traverse over
@param bossNode Here resides the boss you must defeat once you are strong enough
*/
bool findBoss(Graph& map, Node* bossNode) {
    clearedMap cleared;
    queue<Node*> toVisit;
    queue<Node*> tooStrong;
    Node* playerNode;

    // TODO: Follow the comments and finish this function!

    // Add initial neighbors to be visited

    while(!toVisit.empty()) {
        // Check if we can teleport directly to the boss and win

        // Iterate through enemy Nodes until we find a new, unseen, beatable one

        // Update playerNode

        // Add new playerNode's neighbors if they haven't been cleared already

        // Check if we need to update our toVisit queue, or if it can be be done later

        // Update our tooStrong queue
    }

    // If nowhere left to go or if we are strong enough, try beating the boss
    return false;
}
