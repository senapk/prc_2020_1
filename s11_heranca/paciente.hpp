#pragma once
#include <iostream>
#include <functional> // reference_wrapper
#include <string>
#include <vector>

#include "medico.hpp"

class Patient
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Doctor>> m_doctor{}; // so that we can use it here
 
	// We're going to make addDoctor private because we don't want the public to use it.
	// They should use Doctor::addPatient() instead, which is publicly exposed
	void addDoctor(const Doctor& doctor)
	{
		m_doctor.push_back(doctor);
	}
 
public:
	Patient(const std::string& name)
		: m_name{ name }
	{
	}
 
	// We'll implement this function below Doctor since we need Doctor to be defined at that point
	friend std::ostream& operator<<(std::ostream &out, const Patient &patient);
 
	const std::string& getName() const { return m_name; }
 
	// We'll friend Doctor::addPatient() so it can access the private function Patient::addDoctor()
	friend void Doctor::addPatient(Patient& patient);
};