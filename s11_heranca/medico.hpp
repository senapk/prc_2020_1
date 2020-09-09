#pragma once

#include <cstdint>
#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <vector>
 
// Since Doctor and Patient have a circular dependency, we're going to forward declare Patient
class Patient; //forward declaration
 
class Doctor
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Patient>> m_patient{};
 
public:
	Doctor(const std::string& name) :
		m_name{ name }
	{
	}
 
	void addPatient(Patient& patient);
	
	// We'll implement this function below Patient since we need Patient to be defined at that point
	friend std::ostream& operator<<(std::ostream &out, const Doctor &doctor);
 
	const std::string& getName() const { return m_name; }
};