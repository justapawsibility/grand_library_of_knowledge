#pragma once
#include <chrono>
#include <iostream>
#include <functional>
using namespace std;
using namespace chrono;

struct Timer {
  static void measure(function<void()> fn) {

    auto start = high_resolution_clock::now();
    fn();
    auto end = high_resolution_clock::now();

    duration<double> duration = end - start;
    cout << "Result: " << duration.count() << " seconds" << endl;
  }
};
