#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename T>
void serialize(ofstream& output, T value) {
  output.write(reinterpret_cast<const char*>(&value), sizeof(T));
}

template <>
inline void serialize<string>(ofstream& output, string value) {
  int valueLen = value.size();
  output.write(reinterpret_cast<const char*>(&valueLen), sizeof(int));
  output.write(value.c_str(), valueLen);
}

template <typename T>
T deserialize(ifstream& input) {
  T value;
  input.read(reinterpret_cast<char*>(&value), sizeof(T));
  return value;
}

template <>
inline string deserialize<string>(ifstream& input) {
  int valueLen;
  input.read(reinterpret_cast<char*>(&valueLen), sizeof(int));
  string value(valueLen, '\0');
  input.read(value.data(), valueLen);
  return value;
}
