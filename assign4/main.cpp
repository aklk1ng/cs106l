/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
    double mi, mx, avg;
    mi = *std::min_element(dailyWeather.begin(), dailyWeather.end());
    mx = *std::max_element(dailyWeather.begin(), dailyWeather.end());
    avg = std::accumulate(dailyWeather.begin(), dailyWeather.end(), 0.0) / dailyWeather.size();
    return Forecast { mi, mx, avg };
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
    std::vector<Forecast> res(weatherData.size());
    std::transform(weatherData.begin(), weatherData.end(), res.begin(), compute_forecast);
    return res;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
    std::vector<Forecast> res(forecastData);
    res.erase(std::remove_if(res.begin(), res.end(),
                             [&](Forecast f) {
                               return (f.max_temp - f.min_temp) <=
                                          kMaxTempRequirement ||
                                      f.avg_temp < uAvgTempRequirement;
                             }),
              res.end());
    return res;
}


std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
    std::vector<Forecast> res = forecastData;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(res.begin(), res.end(), g);
    return res;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
    std::vector<Forecast> res = get_forecasts(weatherData);
    res = get_filtered_data(res);
    return get_shuffled_data(res);
}

/* #### Please don't change this line! #### */
#include "utils.cpp"
