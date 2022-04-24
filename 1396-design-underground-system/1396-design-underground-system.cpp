struct Travel_data
{
        string station1;
        int in;
};
class UndergroundSystem {
    unordered_map<int, Travel_data*> customer;
    unordered_map<string, vector<int>> times;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        Travel_data* i = new Travel_data{stationName, t};
        customer[id] = i;
    }
    
    void checkOut(int id, string stationName, int t) {
        Travel_data* i = customer[id];
        int time = t - i -> in;
        string location = i -> station1 + " -> " + stationName;
        times[location].push_back(time);
        customer.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string x = startStation + " -> " + endStation;
        int t = accumulate(times[x].begin(), times[x].end(), 0);
        return t / (1.0 * times[x].size());
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */