class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12)
            hour=0;
        double a=hour*30.0;
        a+=(minutes*1.0/2);
        double b=minutes*6.0;
        a=abs(a-b);
        return min(a,360.0-a);
    }
};