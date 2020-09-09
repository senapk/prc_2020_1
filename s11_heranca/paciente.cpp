#include <iostream>
#include <functional> // reference_wrapper
#include <string>
#include <vector>
#include "paciente.hpp"
#include "medico.hpp"

std::ostream& operator<<(std::ostream &out, const Patient &patient)
{
	if (patient.m_doctor.empty())
	{
		out << patient.getName() << " has no doctors right now";
		return out;
	}
 
	out << patient.m_name << " is seeing doctors: ";
	for (const auto& doctor : patient.m_doctor)
		out << doctor.get().getName() << ' ';
 
	return out;
}