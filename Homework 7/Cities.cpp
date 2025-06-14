#include "Cities.h"


namespace cityscape {
	Cities::Cities(int number,
		string city_name,
		string country_name,
		double distance,
		double latitude,
		double longitude) {
		this->set_number(number);
		this->set_city_name(city_name);
		this->set_country_name(country_name);
		this->set_distance(distance);
		this->set_latitude(latitude);
		this->set_longitude(longitude);
	}


	int Cities::get_number() const {
		return this->number;
	}

	string Cities::get_city_name() const {
		return this->city_name;
	}

	string Cities::get_country_name() const {
		return this->country_name;
	}

	double Cities::get_distance() const {
		return this->distance;
	}

	double Cities::get_latitude() const {
		return this->latitude;
	}

	double Cities::get_longitude() const {
		return this->longitude;
	}

	double Cities::degree_to_radian(double angle) {
		return M_PI * angle / 180.0;
	}

	double Cities::distanceEarth(double latitude1, double longitude1, double latitude2, double longitude2) {
		double lat1r, lon1r, lat2r, lon2r, u, v;
		lat1r = degree_to_radian(latitude1);
		lon1r = degree_to_radian(longitude1);
		lat2r = degree_to_radian(latitude2);
		lon2r = degree_to_radian(longitude2);
		u = sin((lat2r - lat1r) / 2);
		v = sin((lon2r - lon1r) / 2);
		return 2.0 * EarthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
	}

	bool Cities::sort_by_closest_distance(const Cities &lhs, const Cities &rhs) {
		return lhs.get_distance() < rhs.get_distance();
	}

	bool Cities::sort_by_farthest_distance(const Cities &lhs, const Cities &rhs) {
		return lhs.get_distance() > rhs.get_distance();
	}

	void Cities::set_number(int number) {
		this->number = number;
	}
	void Cities::set_city_name(string city_name) {
		this->city_name = city_name;
	}

	void Cities::set_country_name(string country_name) {
		this->country_name = country_name;
	}

	void Cities::set_distance(double distance) {
		this->distance = distance;
	}

	void Cities::set_latitude(double latitude) {
		this->latitude = latitude;
	}

	void Cities::set_longitude(double longitude) {
		this->longitude = longitude;
	}


}