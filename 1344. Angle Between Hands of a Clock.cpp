class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour < 0 || minutes < 0 || hour > 12 || minutes > 60) return -1;
        if (hour == 12) hour = 0;
        if (minutes == 60) minutes = 0;
        
        double angle = abs((0.5*(hour*60+minutes)) - (6*minutes));
        if (angle < 360-angle) return angle;
        else return (360-angle);
    }
};
