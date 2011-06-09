// Ocp.hpp
// Greg Horn
// Casadi 2011

#pragma once

#include "Ode.hpp"

#include <casadi/sx/sx_tools.hpp>
#include <casadi/stl_vector_tools.hpp>

#include <interfaces/ipopt/ipopt_solver.hpp>

class Ocp
{
public:
	Ocp(Ode * _ode);
	~Ocp(void);

	void addNonlconIneq(std::vector<CasADi::SX> gNew);
	//	void addNonlconEq(std::vector<CasADi::SX> gNew);
	void addNonlconEq(CasADi::SXMatrix gNew);


	CasADi::SX objFun;
	std::vector<CasADi::SX> g;
	std::vector<double> gMin;
	std::vector<double> gMax;

	void solve(void);
	CasADi::IpoptSolver solver;

private:

protected:
	Ode * ode;

};
