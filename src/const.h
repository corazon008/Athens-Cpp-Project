#pragma once

#include <csignal>
#include <string>
#include <vector>
#include <cmath>

std::vector<std::string> DigitToStringList(const unsigned int d);

std::string DigitToStringListRow(const unsigned int d, const size_t row);

unsigned int GetIntLength(const unsigned int n);

unsigned int GetNthDigit(const unsigned int n, const unsigned int digit);

std::vector<std::string> NumberToStringList(const unsigned int n);