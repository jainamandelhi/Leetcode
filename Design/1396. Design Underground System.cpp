class UndergroundSystem {
public:
    map<string,map<int,int> >ci,co;
    map<string,int>no;
    map<int,int> :: iterator itr;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ci[stationName][id] = t;
        //no[stationName]++;
    }
    
    void checkOut(int id, string stationName, int t) {
        co[stationName][id] = t;
       // no[stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans = 0;
        int temp = 0;
        int m = 0;
        for(itr=co[endStation].begin();itr!=co[endStation].end();itr++)
        {
            if(ci[startStation].find(itr->first) != ci[startStation].end())
            {
                temp = temp + co[endStation][itr->first] - ci[startStation][itr->first] ;
                m++;
            }
        }
        if(m == 0)
            return ans;
        ans = temp*(1.0);
        return ans/m;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */