#include "Time.hpp"

Time::Time(){
    // get current time
    time_t now = time(0);

    _hour = localtime(&now)->tm_hour;
    _min = localtime(&now)->tm_min;
    _sec = localtime(&now)->tm_sec;

}

Time::Time(int hour, int min, int sec){
    if (IsValidTime(hour, min, sec)){
        _hour = hour;
        _min = min;
        _sec = sec;
    }
    else{
        _hour = 0;
        _min = 0;
        _sec = 0;
    }
}

Time::Time(const Time& t){
    _hour = t._hour;
    _min = t._min;
    _sec = t._sec;
}

Time::~Time(){

}

int Time::Hour() const{
    return _hour;
}

int Time::Min() const{
    return _min;
}

int Time::Sec() const{
    return _sec;
}

void Time::SetHour(int hour){
    if (hour >= 0 && hour <= 23){
        _hour = hour;
    }
}

void Time::SetMin(int min){
    if (min >= 0 && min <= 59){
        _min = min;
    }
}

void Time::SetSec(int sec){
    if (sec >= 0 && sec <= 59){
        _sec = sec;
    }
}

bool Time::IsValidTime(int hour, int min, int sec){
    if (hour >= 0 && hour <= 23 && min >= 0 && min <= 59 && sec >= 0 && sec <= 59){
        return true;
    }
    else{
        return false;
    }
}

string Time::toString() const{
    stringstream ss;
    if (_hour < 10){
        ss << "0" << _hour;
    }
    else{
        ss << _hour;
    }

    ss << ":";
    if (_min < 10){
        ss << "0" << _min;
    }
    else{
        ss << _min;
    }

    ss << ":";

    if (_sec < 10){
        ss << "0" << _sec;
    }
    else{
        ss << _sec;
    }

    if (_hour < 12){
        ss << " AM";
    }
    else{
        ss << " PM";
    }

    return ss.str();
}

istream& operator >> (istream& is, Time* t){
    cout << "Enter the hour: ";
    is >> t->_hour;
    cout << "Enter the minute: ";
    is >> t->_min;
    cout << "Enter the second: ";
    is >> t->_sec;
    return is;
}

ostream& operator << (ostream& os, const Time* t){
    os << t->toString();
    return os;
}



