#ifndef CITIES_H_
#define CITIES_H_
#define _USE_MATH_DEFINES


#include <cmath>
#include <string>

const static double EarthRadiusKm = 6372.8;
using namespace std;
namespace cityscape {
	class Cities {
	private:
		string city_name;
		string country_name;
		double distance;
		double latitude;
		double longitude;
		int number;

	public:
		Cities(int number = 0,
			string city_name = "",
			string country_name = "",
			double distance = 0.0,
			double latitude = 0.0,
			double longitude = 0.0);
		int get_number() const;
		string get_city_name() const;
		string get_country_name() const;
		double get_distance() const;
		double get_latitude() const;
		double get_longitude() const;
		double degree_to_radian(double angle);
		double distanceEarth(double latitude1, double longitude1, double latitude2, double longitude2);

		static bool sort_by_closest_distance(const Cities&, const Cities&);
		static bool sort_by_farthest_distance(const Cities&, const Cities&);

		void set_number(int number);
		void set_city_name(string city_name);
		void set_country_name(string country_name);
		void set_distance(double distance);
		void set_latitude(double latitude);
		void set_longitude(double longitude);


	};
}
#endif 