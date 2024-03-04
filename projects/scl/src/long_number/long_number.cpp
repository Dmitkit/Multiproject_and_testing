#include "long_number.hpp"

namespace IBusko {
	LongNumber::LongNumber() {
		numbers = nullptr;
		length = 0;
		sign = POSITIVE;
	}
	
	LongNumber::LongNumber(const char* const str) {
		length = get_length(str);
		int i = 0;
		if (str[0] == MINUS){
			sign = NEGATIVE;
			i++;
		}
		else{
			sign = POSITIVE;
		}
		numbers = new int [length];
		for (int j = 0; j < length; i++, j++){
			numbers[j] = int(str[i]) - 48;
		}

	}
	
	LongNumber::LongNumber(const LongNumber& x) {
		sign = x.sign;
		length = x.length;
		if (length != 0){
		numbers = new int [length];
		
		for (int i = 0; i < length; i++){
			numbers[i] = x.numbers[i];
		}
		}
		else{
			numbers = nullptr;
		}
	}
	
	LongNumber::LongNumber(LongNumber&& x) {
		sign = x.sign;
		length = x.length;
		numbers = x.numbers;
		delete[] x.numbers;
	}
	
	LongNumber::~LongNumber() {
		sign = POSITIVE;
		length = 0;
		delete[] numbers;
	}
	
	LongNumber& LongNumber::operator = (const char* const str) {
		length = get_length(str);
		int i = 0;
		if (str[0] == MINUS){
			sign = NEGATIVE;
			i++;
		}
		else{
			sign = POSITIVE;
		}
		for (int j = 0; j < length; i++, j++){
			numbers[j] = int(str[i]) - 48;
		}
		return *this;
	}
	
	LongNumber& LongNumber::operator = (const LongNumber& x) {

		if (length < x.length){

			if (length != 0){
				delete[] numbers;
			}
			numbers = new int [x.length];
		}

		sign = x.sign;
		length = x.length;
		
		for (int i = 0; i <= length; i++){
			numbers[i] = x.numbers[i];
		}
		return *this;
	}
	
	LongNumber& LongNumber::operator = (LongNumber&& x) {
		sign = x.sign;
		length = x.length;
		if(numbers != nullptr){
			delete[] numbers;
		}
		numbers = x.numbers;
		delete[] x.numbers;
		return *this;
	}
	
	bool LongNumber::operator == (const LongNumber& x){
		if (x.sign != sign){
			return false;}
		if (x.length != length){
			return false;
		}
		for (int i = 0; i < length; i++){
			if (numbers[i] != x.numbers[i]){
				return false;
			}
		}
		return true;
	}
	
	bool LongNumber::operator > (const LongNumber& x) const{
		if (sign != x.sign){
			return (sign == POSITIVE ? true : false);
		}
		if (length != x.length){
			if (sign == POSITIVE){
				return (length > x.length ? true : false);
			}
			else{
				return (length < x.length ? true : false);
			}
		}
		for (int i = 0; i < length; i++){
				if (numbers[i] > x.numbers[i]){
					return (sign);
				}
				if (numbers[i] < x.numbers[i]){
					return (-sign);
				}
		}
		return false;
	}
	
	bool LongNumber::operator < (const LongNumber& x) const{
		LongNumber temp = x;
		return (x > *this);
	}
	
	LongNumber LongNumber::operator + (const LongNumber& x) {
		// TODO
		LongNumber result;
		if (x.sign != sign){
			if (x.sign == NEGATIVE){
				result = (*this - x);
				return result;
			}
			else{
				LongNumber temp = x;
				result = temp - *this;
				return (result);
			}
		}
		int temp_length = std::max(length, x.length) + 1;
		int * temp = new int [temp_length];
		bool x_is_longest = (x.length > length);
		int carry = 0; // флаг переноса из предыдущего разряда
		int min = std::min(length, x.length) - 1;
        for (int i = std::max(length, x.length); i > 0; --i) { //i >= 0? мб ошибка
				if(min >= 0){
					if (x_is_longest){
						temp[i] = (numbers[min] + carry + x.numbers[i - 1]) % 10;
						carry = (carry + numbers[min] + x.numbers[i - 1] >= 10);
					}
					else{
						temp[i] = (x.numbers[min] + carry + numbers[i - 1]) % 10;
						carry = (carry + x.numbers[min] + numbers[i - 1] >= 10);
					}
					min--;}
				else{
					if (x_is_longest){
						temp[i] = (carry + x.numbers[i - 1]) % 10;
						carry = (carry + x.numbers[i - 1] >= 10);
					}
					else{
						temp[i] = (carry + numbers[i - 1]) % 10;
						carry = ((carry + numbers[i - 1]) >= 10);
					}
				}
        }
		temp[0] = carry;
		bool first_digit_is_zero = (temp[0] == 0);
		result.length = (first_digit_is_zero)?(temp_length - 1):temp_length;
		result.numbers = new int [result.length];
		result.sign = x.sign;
		for (int i = 0; i < result.length; i++){
				result.numbers[i] = temp[i + first_digit_is_zero];
			}
		delete[] temp;
		return result;
	}
	
	LongNumber LongNumber::operator - (const LongNumber& x) {
		// TODO
		LongNumber result = x;
		if (x.sign != sign){
			LongNumber temp = x;
			temp.sign = (x.sign == NEGATIVE);
			result = temp + *this;
			return result;
		}
		bool x_is_bigger;
		if (x > *this && x.sign == POSITIVE){
			x_is_bigger = true;
		}
		else{
			x_is_bigger = false;
		};
		LongNumber minuend;
		LongNumber subtrahend;
		LongNumber difference;
		if (sign == POSITIVE){
			minuend = (x_is_bigger) ? x : *this;
			subtrahend = (x_is_bigger) ? *this : x;
		}
		else{
			minuend = (x_is_bigger) ? *this : x;
			subtrahend = (x_is_bigger) ? x : *this;
		}
		difference = minuend;
		int carry = 0;
		for (int i = minuend.length; i >=0; i--){
			if (minuend.numbers[i] < subtrahend.numbers[i] + carry){
				difference.numbers[i] = (minuend.numbers[i] - subtrahend.numbers[i] - carry) + 10;
				carry = 1;
			}
			else {
				difference.numbers[i] = (minuend.numbers[i] - subtrahend.numbers[i] - carry);
				carry = 0;
			}
		}
		int i = 0;
		while (difference.numbers[i] == 0 && difference.length > 1){
			i++;
			difference.length--;
		}
		result.numbers = new int [difference.length];
		result.sign = difference.sign;
		for (int j = 0; j < difference.length; j++){
			result.numbers[j] = difference.numbers[i + j];
		}
		return result;
	}
	
	LongNumber LongNumber::operator * (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}
	
	LongNumber LongNumber::operator / (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}
	
	LongNumber LongNumber::operator % (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}
	
	int LongNumber::get_digits_number() const {
		return length;
	}
	
	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}
	
	// ----------------------------------------------------------
	// PRIVATE
	// ----------------------------------------------------------
	int LongNumber::get_length(const char* const str) const {
		int length = 0;
		if (str == nullptr){
			return length;
		}
		int symbols_counted = 0;
		while (str[symbols_counted] != '\0'){
			symbols_counted++;
		}
		if (str[0] == MINUS){
			symbols_counted--;
		}
		length = symbols_counted;
		return length;
	}
	
	// ----------------------------------------------------------
	// FRIENDLY
	// ----------------------------------------------------------
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.sign == IBusko::LongNumber::NEGATIVE){
			os << IBusko::LongNumber::MINUS;
		}
		for (int i = 0; i < x.length; i++){
			os << x.numbers[i];
		}
		return os;
	}
}
