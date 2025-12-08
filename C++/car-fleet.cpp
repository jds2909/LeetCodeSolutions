class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // vector of pairs storing position & time to arrive
        vector<pair<int, double>> cars(speed.size());

        // for each car
        for (int i = 0; i < speed.size(); ++i)
        {
            // arrival time = distance from target / speed
            double arrivalTime = (double) (target - position[i]) / (double) speed[i];
            // pair containing position and time to arrive
            pair<int, double> newPair = { position[i], arrivalTime };
            // pass all pairs into cars
            cars[i] = newPair;
        }

        // sort cars vector by position (closest to furthest from target)
        // sorts by 1st value of pair by default (good for us)
        sort(cars.begin(), cars.end());

        // n is always >= 1 so numFleets is always at least 1
        int numFleets = 1;
        // set fastest arrival time
        double earliestArrival = cars.back().second;

        // iterate backwards from 2nd to last (closest to destination first)
        for (int i = cars.size() - 2; i >=0; --i)
        {
            // if speed is more than previous fleet, increment fleet and update new earliest arrival for new fleet
            if (cars[i].second > earliestArrival)
            {
                ++numFleets;
                earliestArrival = cars[i].second;
            }
        }
        // return number of fleets
        return numFleets;
    }
};