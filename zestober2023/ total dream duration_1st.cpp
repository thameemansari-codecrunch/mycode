
//Author:S.Thameem Ansari
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip> // for std::setw

//struct Time to store the hour and minute
struct Time {
    int hour;
    int minute;
};
//The parseTime function takes a time string in the format "HH:MM" and parses it into a Time struct. It uses std::istringstream for parsing.
Time parseTime(const std::string& timeStr) {
    std::istringstream ss(timeStr);
    char delimiter;
    Time t;
    ss >> t.hour >> delimiter >> t.minute;
    return t;
}

std::string calculateDreamDuration(const std::vector<std::string>& dreamSegments) {
    int totalDuration = 0;

    for (const std::string& segment : dreamSegments) {
        std::istringstream ss(segment);
        std::string start, end;
        getline(ss, start, '-');
        getline(ss, end);

        Time startTime = parseTime(start);
        Time endTime = parseTime(end);

        // Convert start and end times to minutes
        int startTimeInMinutes = startTime.hour * 60 + startTime.minute;
        int endTimeInMinutes = endTime.hour * 60 + endTime.minute;

        // Calculate duration of the dream segment in minutes
        int segmentDreamDuration = endTimeInMinutes - startTimeInMinutes;

        // Add segment duration to total duration
        totalDuration += segmentDreamDuration;
    }

    // Convert total duration to hours and minutes
    int totalHours = totalDuration / 60;
    int totalMinutes = totalDuration % 60;

    // Format the result as "HH:MM"
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << totalHours << ":" << std::setw(2) << std::setfill('0') << totalMinutes;
    return oss.str();
}

int main() {
    std::vector<std::string> dreamSegments = {"02:30-03:15", "03:00-04:00", "05:45-06:30"};
    std::string totalDuration = calculateDreamDuration(dreamSegments);
    std::cout << "Total dream duration: " << totalDuration << std::endl;
    return 0;
}
