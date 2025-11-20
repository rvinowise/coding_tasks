
//yandex tasks; 6. Туризм
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
using namespace std;

struct Point {
	public:
    int x;
    int y;
    Point(int _x, int _y): x(_x), y(_y) {};
    Point() {};
    string to_string() {
        stringstream ss;
        ss << "Point " << x << ", " << y;
        return ss.str();
    }
};

struct Track {
	public:
    int start;
    int end;
    Track(int _start, int _end): start(_start-1), end(_end-1) {};
    Track() {};
    string to_string() {
        stringstream ss;
        ss << "Track " << start+1 << " -> " << end+1;
        return ss.str();
    }
    int direction() {
        if (start < end) {
            return 1;
        }
        return -1;
    }
};

std::vector<std::string> split_string(const std::string& str, string delimiter) {
    regex regex_delimiter(delimiter);
    sregex_token_iterator it(str.begin(), str.end(), regex_delimiter, -1);
    sregex_token_iterator end;
    
    vector<string> tokens;
    
    while (it != end) {
        auto token = *it;
        tokens.push_back(token);
        it++;
    }
    
    return tokens;
}

vector<Point> init_points_from_console(int points_number) {
    
    vector<Point> points(points_number);
    for(int point_index = 0; point_index < points_number; point_index++) {
        
    	string point_line; cin >> point_line;
        vector<string> point_coordinates = split_string(point_line, ",");

        points[point_index] = Point(
            stoi(point_coordinates[0]),
            stoi(point_coordinates[1])
        );
        //cout << points[point_index].to_string() << endl;
    }
    return points;
}

vector<Track> init_tracks_from_console(int tracks_number) {
    
    vector<Track> tracks(tracks_number);
    for(int track_index = 0; track_index < tracks_number; track_index++) {
        
    	string track_line; cin >> track_line;
        vector<string> track_as_string = split_string(track_line, ",");

        tracks[track_index] = Track(
            stoi(track_as_string[0]),
            stoi(track_as_string[1])
        );
        //cout << tracks[track_index].to_string() << endl;
    }
    return tracks;
}

int calculate_total_ascending(vector<Point> points, Track track) {
    int direction = track.direction();
    int total_ascension = 0;
    int previous_height = points[track.start].y;
    for (
        int i_point = track.start; 
        i_point != track.end; 
        i_point+=direction
    ) {
        if (previous_height < points[i_point].y) {
            total_ascension += points[i_point].y - previous_height;
        }
        previous_height = points[i_point].y;
    }
    return total_ascension;
}

int main() 
{
	int points_number;
  	std::cin >> points_number;
    
    auto points = init_points_from_console(points_number);
    
    int tracks_number;
  	std::cin >> tracks_number;
    auto tracks = init_tracks_from_console(tracks_number);
    
    for(Track track: tracks) {
        auto total_ascending = calculate_total_ascending(points, track);
        cout << total_ascending << endl;
    }

	return 0;
}
